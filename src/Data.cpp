#include "Data.h"
#include <optional>

#include <QBuffer>
#include <QDateTime>
#include <QImageReader>
#include <QLocale>
#include <QTextCodec>
#include <QFile>
#include <QRegularExpression>

#include <algorithm>

#include <QProcess>
#include <QString>
#include <QStringList>
#include <QTemporaryFile>
#include <QVector>
#include <QDir>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

#include "sql/sqlitetypes.h"

// Note that these aren't all possible BOMs. But they are probably the most common ones.
// The size is needed at least for the ones with character zero in them.
static const QByteArray bom3("\xEF\xBB\xBF", 3);
static const QByteArray bom2a("\xFE\xFF", 2);
static const QByteArray bom2b("\xFF\xFE", 2);
static const QByteArray bom4a("\x00\x00\xFE\xFF", 4);
static const QByteArray bom4b("\xFF\xFE\x00\x00", 4);

bool isTextOnly(QByteArray data, const QString& encoding, bool quickTest)
{
    // If the data starts with a Unicode BOM, we can use detection provided by QTextCodec.
    if(startsWithBom(data)) {
        QTextCodec *codec = encoding.isEmpty()? QTextCodec::codecForName("UTF-8") : QTextCodec::codecForName(encoding.toUtf8());
        QTextCodec *detectedCodec = QTextCodec::codecForUtfText(data, nullptr);
        return detectedCodec == codec;
    }

    // Truncate to the first few bytes for quick testing
    QByteArray::size_type testSize = quickTest? std::min(QByteArray::size_type(512), data.size()) : data.size();

    // If the quick test has been requested and we have to truncate the string, we have to use
    // an approach where truncated multibyte characters are not interpreted as invalid characters.
    if(quickTest && data.size() > testSize) {

        // We can assume that the default encoding (UTF-8) and all the ISO-8859
        // cannot contain character zero.
        // This has to be checked explicitly because toUnicode() is using zero as
        // a terminator for these encodings.
        if((encoding.isEmpty() || encoding.startsWith("ISO-8859")) && data.contains('\0'))
            return false;

        QTextCodec::ConverterState state;
        QTextCodec *codec = encoding.isEmpty()? QTextCodec::codecForName("UTF-8") : QTextCodec::codecForName(encoding.toUtf8());
        codec->toUnicode(data.constData(), testSize, &state);
        return state.invalidChars == 0;
    } else {
        // Convert to Unicode if necessary
        data = decodeString(data, encoding);
        QString text (data);
        bool isPrintable = true;
        for(QChar character : text) {
            if(character.isNonCharacter() || (character.category() == QChar::Other_Control && !character.isSpace())) {
                isPrintable = false;
                break;
            }
        }
        // Perform check
        return isPrintable && text.toUtf8() == data;
    }
}

bool isTextOnlyFile(const QString& fileName)
{
    QFile file(fileName);
    if (file.open(QFile::ReadOnly)) {
        QByteArray data = file.read(512);
        return !data.isEmpty() && isTextOnly(data);
    } else {
        return false;
    }
}

bool containsRightToLeft(const QString& text) {

    for(QChar ch : text) {
        switch(ch.direction()) {
        case QChar::DirR:
        case QChar::DirAL:
        case QChar::DirRLE:
        case QChar::DirRLO:
        case QChar::DirRLI:
            return true;
        default:
            break;
        }
    }
    return false;
}

bool startsWithBom(const QByteArray& data)
{
    if(data.startsWith(bom3) ||
            data.startsWith(bom2a) || data.startsWith(bom2b) ||
            data.startsWith(bom4a) || data.startsWith(bom4b))
    return true;
    else
        return false;
}

QByteArray removeBom(QByteArray& data)
{
    if(data.startsWith(bom3))
    {
        QByteArray bom = data.left(3);
        data.remove(0, 3);
        return bom;
    } else if(data.startsWith(bom2a) || data.startsWith(bom2b)) {
        QByteArray bom = data.left(2);
        data.remove(0, 2);
        return bom;
    } else if(data.startsWith(bom4a) || data.startsWith(bom4b)) {
        QByteArray bom = data.left(4);
        data.remove(0, 4);
        return bom;
    } else {
        return QByteArray();
    }
}

QString isImageData(const QByteArray& data)
{
    // Check if it's an image. First do a quick test by calling canRead() which only checks the first couple of bytes or so. Only if
    // that returned true, do a more sophisticated test of the data. This way we get both, good performance and proper data checking.
    QBuffer imageBuffer(const_cast<QByteArray*>(&data));
    QImageReader readerBuffer(&imageBuffer);
    QString imageFormat = readerBuffer.format();
    if(readerBuffer.canRead() && !readerBuffer.read().isNull())
        return imageFormat;
    else
        return QString();
}

QStringList toStringList(const QList<QByteArray>& list) {
    QStringList strings;
    for (const QByteArray &item : list) {
        strings.append(QString::fromUtf8(item));
    }
    return strings;
}

QByteArray encodeString(const QByteArray& str, const QString& encoding)
{
    if(encoding.isEmpty())
        return str;
    else
        return QTextCodec::codecForName(encoding.toUtf8())->fromUnicode(str);
}

QByteArray decodeString(const QByteArray& str, const QString& encoding)
{
    if(encoding.isEmpty())
        return str;
    else
        return QTextCodec::codecForName(encoding.toUtf8())->toUnicode(str).toUtf8();
}

QString humanReadableSize(unsigned long byteCount)
{
    static const std::vector<QString> units = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB"};

    double size = static_cast<double>(byteCount);
    for(const QString& unit : units)
    {
        if(size < 1024.0)
            return QString::number(size, 'f', 2) + " " + unit;

        size /= 1024.0;
    }

    return QString::number(size, 'f', 2) + " YiB";
}

QString isoDateTimeStringToLocalDateTimeString(const QString& date_string)
{
    return QLocale::system().toString(QDateTime::fromString(date_string, Qt::ISODate).toLocalTime(), QLocale::ShortFormat);
}

void removeCommentsFromQuery(QString& query)
{
    // Store the current size so we can easily check later if the string has been changed
    int oldSize = query.size();

    // This implements a simple state machine to strip the query from comments
    QChar quote;
    for(int i=0;i<query.size();i++)
    {
        // Are we in quote state?
        if(quote.isNull())
        {
            // We are currently not in quote state

            // So are we starting a quote?
            if((query.at(i) == '\'' || query.at(i) == '\"' || query.at(i) == '[') && (i == 0 || query.at(i-1) != '\\'))
            {
                // Quoted text is beginning. Switch to the quote state

                quote = query.at(i);
            } else if(query.at(i) == '-' && i+1 < query.size() && query.at(i+1) == '-') {
                // This is an end of line comment. Remove anything till the end of the line or the end of the string if this is the last line

                int pos_next_line_break = query.indexOf('\n', i);
                if(pos_next_line_break == -1)
                    query = query.left(i);
                else
                    query.remove(i, pos_next_line_break - i);       // The \n is left in intentionally
            } else if(query.at(i) == '/' && i+1 < query.size() && query.at(i+1) == '*') {
                // This is a block comment. Remove anything till the end of the block or the end of the string if the block is not closed
                int pos_end_comment = query.indexOf("*/", i);
                if(pos_end_comment == -1)
                    query = query.left(i);
                else
                    query.remove(i, pos_end_comment - i + 2);       // Add 2 to include the */
            }
        } else {
            // We are currently in quote state

            // If this is the closing quote character, switch back to normal state
            if((query.at(i) == quote) && (i == 0 || query.at(i-1) != '\\'))
                quote = QChar(0);
        }
    }

    query = query.trimmed();

    if (oldSize != query.size()) {
        // Remove multiple line breaks that might have been created by deleting comments till the end of the line but not including the line break
        query.replace(QRegularExpression("\\n+"), "\n");

        // Also remove any remaining whitespace at the end of each line
        query.replace(QRegularExpression("[ \t]+\n"), "\n");
    }
}

// JSONB Support

// Enum for element types
enum ElementType {
    NULL_TYPE = 0,
    TRUE_TYPE = 1,
    FALSE_TYPE = 2,
    INT = 3,
    INT5 = 4,
    FLOAT = 5,
    FLOAT5 = 6,
    TEXT = 7,
    TEXTJ = 8,
    TEXT5 = 9,
    TEXTRAW = 10,
    ARRAY = 11,
    OBJECT = 12,
    RESERVED_13 = 13,
    RESERVED_14 = 14,
    RESERVED_15 = 15
};

// Function declarations
QByteArray decodeElement(const QByteArray& data, int& offset);
QByteArray decodeString(const QByteArray& data, int& offset, uint32_t payloadSize);
QByteArray decodeArray(const QByteArray& data, int& offset, uint32_t payloadSize);
QByteArray decodeObject(const QByteArray& data, int& offset, uint32_t payloadSize);
bool isValidJSONB(const QByteArray& data);

// Function to decode JSONB to JSON
QByteArray JSONBtoJSON(const QByteArray& data) {
    if (!isValidJSONB(data)) {
        throw std::runtime_error("Invalid JSONB format");
    }

    int offset = 0;
    return decodeElement(data, offset);
}

// Function to check if the data is valid JSONB
bool isValidJSONB(const QByteArray& data) {
    if (data.isEmpty()) return false;

    int offset = 0;
    try {
        decodeElement(data, offset);
    } catch (...) {
        return false;
    }

    return offset == data.size();
}

// Function to decode big-endian integers from QByteArray
uint32_t decodeBigEndianInt(const QByteArray& data, int& offset, int size) {
    uint32_t value = 0;
    for (int i = 0; i < size; ++i) {
        value = (value << 8) | (static_cast<uint8_t>(data[offset + i]));
    }
    offset += size;
    return value;
}

// Decode functions for different JSONB types
QByteArray decodeString(const QByteArray& data, int& offset, uint32_t payloadSize) {
    QByteArray result = data.mid(offset, payloadSize);
    result.replace("\"", "\\\"");  // Escape quotes
    offset += payloadSize;
    return result;
}

QByteArray decodeArray(const QByteArray& data, int& offset, uint32_t payloadSize) {
    QByteArray result = "[";
    int startOffset = offset;

    bool first = true;
    while (offset < startOffset + payloadSize) {
        if (!first) {
            result.append(",");
        }
        first = false;

        QByteArray element = decodeElement(data, offset);
        result.append(element);
    }

    result.append("]");
    return result;
}

QByteArray decodeObject(const QByteArray& data, int& offset, uint32_t payloadSize) {
    QByteArray result = "{";
    int startOffset = offset;

    bool first = true;
    while (offset < startOffset + payloadSize) {
        if (!first) {
            result.append(",");
        }
        first = false;

        QByteArray key = decodeElement(data, offset);
        QByteArray value = decodeElement(data, offset);

        result.append(key).append(":").append(value);
    }

    result.append("}");
    return result;
}

QByteArray decodeElement(const QByteArray& data, int& offset) {
    if (offset >= data.size()) {
        throw std::runtime_error("Invalid JSONB: Offset out of bounds");
    }

    uint8_t header = data[offset++];
    uint8_t type = header & 0x0F;
    uint8_t sizeIndicator = header >> 4;

    uint32_t payloadSize = 0;
    switch (sizeIndicator) {
        case 0:
        case 1:
        case 2:
        case 3:
            case 4:
                case 5:
                    case 6:
                        case 7:
                            case 8:
                                case 9:
                                    case 10:
                                        case 11:
            payloadSize = sizeIndicator;
            break;
        case 12:
            payloadSize = decodeBigEndianInt(data, offset, 1);
            break;
        case 13:
            payloadSize = decodeBigEndianInt(data, offset, 2);
            break;
        case 14:
            payloadSize = decodeBigEndianInt(data, offset, 4);
            break;
        case 15:
            payloadSize = decodeBigEndianInt(data, offset, 8);
            break;
    }

    QByteArray result;

    switch (type) {
        case NULL_TYPE:
            result = "null";
            break;
        case TRUE_TYPE:
            result = "true";
            break;
        case FALSE_TYPE:
            result = "false";
            break;
        case INT:
        case INT5:
        case FLOAT:
        case FLOAT5:
            result = data.mid(offset, payloadSize);
            offset += payloadSize;
            break;
        case TEXT:
        case TEXTJ:
        case TEXT5:
        case TEXTRAW:
            result = "\"" + decodeString(data, offset, payloadSize) + "\"";
            break;
        case ARRAY:
            result = decodeArray(data, offset, payloadSize);
            break;
        case OBJECT:
            result = decodeObject(data, offset, payloadSize);
            break;
        case RESERVED_13:
        case RESERVED_14:
        case RESERVED_15:
            // Handle reserved types gracefully, currently just printing a message
            std::cerr << "Reserved type encountered: " << type << std::endl;
            result = ""; // Modify as per your handling needs
            break;
        default:
            throw std::runtime_error("Invalid JSONB: Unknown type");
    }

    return result;
}

// Function to convert a QByteArray to lowercase
QByteArray toLowerCase(const QByteArray &data) { return data.toLower(); }

// Function to check if a QByteArray contains any of the SQL keywords
bool isSQLScript(const QByteArray &data) {
  // List of common SQL keywords
  QStringList sqlKeywords = {
      "select",    "insert",   "update", "delete", "create", "drop",
      "alter",     "where",    "from",   "join",   "into",   "values",
      "table",     "database", "set",    "index",  "view",   "trigger",
      "procedure", "distinct", "group",  "order",  "by",     "limit",
      "having",    "union"};

  // Convert the QByteArray to a lowercase string
  QByteArray lowerCaseData = toLowerCase(data);

  // Check if any SQL keyword is present in the text
  for (const QString &keyword : sqlKeywords) {
    if (lowerCaseData.contains(keyword.toUtf8())) {
      return true;
    }
  }

  return false;
}

#ifdef Q_OS_WIN
    const QString checkSqlfluffCommand = "where sqlfluff";
#else
    const QString checkSqlfluffCommand = "command -v sqlfluff";
#endif

bool isSqlfluffInstalled() {
    static std::optional<bool> cache = std::nullopt;
    if (cache != std::nullopt) {
    return *cache;
    }
    QProcess process;
    process.start(checkSqlfluffCommand);
    process.waitForFinished();
    QByteArray output = process.readAllStandardOutput();
    QByteArray error = process.readAllStandardError();
    int exitCode = process.exitCode();

    qDebug() << "Installation check output:" << output;
    qDebug() << "Installation check error:" << error;
    qDebug() << "Installation check exit code:" << exitCode;

    // Check if the output is not empty and there are no errors
    cache = exitCode == 0 && !output.isEmpty();
    return *cache;
}

QString formatSqlWithSqlfluff(const QString& sqlQuery) {
    QString formattedQuery;

    // Create a temporary file to store the SQL query
    QTemporaryFile tempFile(QDir::tempPath() + QDir::separator() +
                            "XXXXXX.sql");
    if (tempFile.open()) {
        QTextStream out(&tempFile);
        out << sqlQuery;
        tempFile.close();

        QStringList arguments;
        arguments << "fix" << "--dialect" << "sqlite" << tempFile.fileName();

        QProcess process;
        process.start("sqlfluff", arguments);
        process.waitForStarted();
        process.waitForFinished();

        QByteArray output = process.readAllStandardOutput();
        QByteArray error = process.readAllStandardError();

        if (!error.isEmpty()) {
            qWarning() << "sqlfluff format error:" << error;
        } else {
            QFile resultFile(tempFile.fileName());
            qWarning() << tempFile.fileName();
            if (resultFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&resultFile);
                formattedQuery = in.readAll().trimmed();
                resultFile.close();
            } else {
                qWarning() << "Failed to open temporary file for reading.";
            }
        }

        // Remove the temporary file
        tempFile.remove();
    } else {
        qWarning() << "Failed to create temporary file.";
    }

    return formattedQuery;
}
// Function to split a QString into tokens based on delimiters
QVector<QString> split(const QString &str) {
  QVector<QString> tokens;
  QStringList parts =
      str.split(QRegExp("((?=\\()|\\s|(?=;))"), QString::SkipEmptyParts);
  for (const auto &part : parts) {
    tokens.push_back(part.trimmed());
  }
  return tokens;
}

// Function to beautify an SQL query stored in a QString
QString beautify_sql(const QString& sql) {
    if (sql.count("\n") >= 2) {
        return sql; // Do not beautify if two newlines already exist
    }

//   if (isSqlfluffInstalled()) {
//        auto str = formatSqlWithSqlfluff(sql);
//        if (!str.isEmpty()) {
//            return str;
//        }
//   }

    QStringList keywords = {
        "SELECT", "FROM", "WHERE", "ORDER BY", "GROUP BY", "INSERT INTO", "VALUES",
        "UPDATE", "SET", "DELETE FROM", "JOIN", "LEFT JOIN", "RIGHT JOIN", "INNER JOIN", "THEN", "END",
        "OUTER JOIN", "ON", "AND", "OR", "json_extract"
    };

    QVector<QString> tokens = split(sql);

    QString beautified_sql;
    int indent_level = 0;
    const QString indent = "    ";

    for (const auto& token : tokens) {
        QString upper_token = token.toUpper();

        if (keywords.contains(upper_token)) {
            beautified_sql += "\n";
            for (int i = 0; i < indent_level; ++i) {
                beautified_sql += indent;
            }
        }

        if (token == ";") {
            beautified_sql = beautified_sql.trimmed() + token;
            beautified_sql += "\n\n";
            indent_level = 0; // Reset indentation after semi-colon
        } else {
            beautified_sql += token + " ";
            if (token == "(") {
                beautified_sql += "\n";
                indent_level++;
            } else if (token == ")") {
                beautified_sql += "\n";
                indent_level--;
                for (int i = 0; i < indent_level; ++i) {
                    beautified_sql += indent;
                }
            }
        }
    }

    return beautified_sql;
}
