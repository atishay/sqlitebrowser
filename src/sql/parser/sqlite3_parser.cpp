// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "sqlite3_parser.hpp"


// Unqualified %code blocks.
#line 39 "sqlite3_parser.yy"

	#include "ParserDriver.h"
	
	static std::string unquote_text(std::string str, char quote_char)
	{
		if(quote_char != '[')
		{
			if(str.front() != quote_char || str.back() != quote_char)
				return str;

			str = str.substr(1, str.size()-2);

			std::string quote(2, quote_char);

			size_t pos = 0;
			while((pos = str.find(quote, pos)) != std::string::npos)
			{
				str.erase(pos, 1);
				pos += 1;               // Don't remove the other quote char too
			}
			return str;
		} else {
			if(str.front() != '[' || str.back() != ']')
				return str;

			return str.substr(1, str.size()-2);
		}
	}

#line 76 "sqlite3_parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 10 "sqlite3_parser.yy"
namespace  sqlb { namespace parser  {
#line 169 "sqlite3_parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, ParserDriver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yyscanner (yyscanner_yyarg),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_columndef_list: // columndef_list
        value.YY_MOVE_OR_COPY< ColumnList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columnconstraint_list: // columnconstraint_list
      case symbol_kind::S_tableconstraint: // tableconstraint
      case symbol_kind::S_tableconstraint_list: // tableconstraint_list
      case symbol_kind::S_optional_tableconstraint_list: // optional_tableconstraint_list
        value.YY_MOVE_OR_COPY< TableConstraints > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optional_if_not_exists: // optional_if_not_exists
      case symbol_kind::S_optional_unique: // optional_unique
      case symbol_kind::S_optional_temporary: // optional_temporary
      case symbol_kind::S_optional_always_generated: // optional_always_generated
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_createindex_stmt: // createindex_stmt
        value.YY_MOVE_OR_COPY< sqlb::IndexPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_indexed_column: // indexed_column
        value.YY_MOVE_OR_COPY< sqlb::IndexedColumn > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_indexed_column_list: // indexed_column_list
        value.YY_MOVE_OR_COPY< sqlb::IndexedColumnVector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columnid_list: // columnid_list
      case symbol_kind::S_optional_columnid_with_paren_list: // optional_columnid_with_paren_list
        value.YY_MOVE_OR_COPY< sqlb::StringVector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_createvirtualtable_stmt: // createvirtualtable_stmt
      case symbol_kind::S_createtable_stmt: // createtable_stmt
        value.YY_MOVE_OR_COPY< sqlb::TablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tableoption: // tableoption
      case symbol_kind::S_tableoptions_list: // tableoptions_list
      case symbol_kind::S_optional_tableoptions_list: // optional_tableoptions_list
        value.YY_MOVE_OR_COPY< std::bitset<sqlb::Table::NumOptions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columnconstraint: // columnconstraint
        value.YY_MOVE_OR_COPY< std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columndef: // columndef
        value.YY_MOVE_OR_COPY< std::shared_ptr<sqlb::Field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ABORT: // "ABORT"
      case symbol_kind::S_ACTION: // "ACTION"
      case symbol_kind::S_ALWAYS: // "ALWAYS"
      case symbol_kind::S_AND: // "AND"
      case symbol_kind::S_AND_BETWEEN: // "AND BETWEEN"
      case symbol_kind::S_AS: // "AS"
      case symbol_kind::S_ASC: // "ASC"
      case symbol_kind::S_AUTOINCREMENT: // "AUTOINCREMENT"
      case symbol_kind::S_BETWEEN: // "BETWEEN"
      case symbol_kind::S_CASCADE: // "CASCADE"
      case symbol_kind::S_CASE: // "CASE"
      case symbol_kind::S_CAST: // "CAST"
      case symbol_kind::S_CHECK: // "CHECK"
      case symbol_kind::S_COLLATE: // "COLLATE"
      case symbol_kind::S_CONFLICT: // "CONFLICT"
      case symbol_kind::S_CONSTRAINT: // "CONSTRAINT"
      case symbol_kind::S_CREATE: // "CREATE"
      case symbol_kind::S_CURRENT_DATE: // "CURRENT_DATE"
      case symbol_kind::S_CURRENT_TIME: // "CURRENT_TIME"
      case symbol_kind::S_CURRENT_TIMESTAMP: // "CURRENT_TIMESTAMP"
      case symbol_kind::S_DEFAULT: // "DEFAULT"
      case symbol_kind::S_DEFERRABLE: // "DEFERRABLE"
      case symbol_kind::S_DEFERRED: // "DEFERRED"
      case symbol_kind::S_DELETE: // "DELETE"
      case symbol_kind::S_DESC: // "DESC"
      case symbol_kind::S_DISTINCT: // "DISTINCT"
      case symbol_kind::S_ELSE: // "ELSE"
      case symbol_kind::S_END: // "END"
      case symbol_kind::S_ESCAPE: // "ESCAPE"
      case symbol_kind::S_EXISTS: // "EXISTS"
      case symbol_kind::S_FAIL: // "FAIL"
      case symbol_kind::S_FALSE: // "FALSE"
      case symbol_kind::S_FILTER: // "FILTER"
      case symbol_kind::S_FOLLOWING: // "FOLLOWING"
      case symbol_kind::S_FOREIGN: // "FOREIGN"
      case symbol_kind::S_FROM: // "FROM"
      case symbol_kind::S_GENERATED: // "GENERATED"
      case symbol_kind::S_GLOB: // "GLOB"
      case symbol_kind::S_IF: // "IF"
      case symbol_kind::S_IGNORE: // "IGNORE"
      case symbol_kind::S_IMMEDIATE: // "IMMEDIATE"
      case symbol_kind::S_IN: // "IN"
      case symbol_kind::S_INDEX: // "INDEX"
      case symbol_kind::S_INITIALLY: // "INITIALLY"
      case symbol_kind::S_INSERT: // "INSERT"
      case symbol_kind::S_IS: // "IS"
      case symbol_kind::S_ISNULL: // "ISNULL"
      case symbol_kind::S_KEY: // "KEY"
      case symbol_kind::S_LIKE: // "LIKE"
      case symbol_kind::S_MATCH: // "MATCH"
      case symbol_kind::S_NO: // "NO"
      case symbol_kind::S_NOT: // "NOT"
      case symbol_kind::S_NOTNULL: // "NOTNULL"
      case symbol_kind::S_NULL: // "NULL"
      case symbol_kind::S_ON: // "ON"
      case symbol_kind::S_OR: // "OR"
      case symbol_kind::S_OVER: // "OVER"
      case symbol_kind::S_PARTITION: // "PARTITION"
      case symbol_kind::S_PRECEDING: // "PRECEDING"
      case symbol_kind::S_PRIMARY: // "PRIMARY"
      case symbol_kind::S_RAISE: // "RAISE"
      case symbol_kind::S_RANGE: // "RANGE"
      case symbol_kind::S_REFERENCES: // "REFERENCES"
      case symbol_kind::S_REGEXP: // "REGEXP"
      case symbol_kind::S_REPLACE: // "REPLACE"
      case symbol_kind::S_RESTRICT: // "RESTRICT"
      case symbol_kind::S_RETURNING: // "RETURNING"
      case symbol_kind::S_ROLLBACK: // "ROLLBACK"
      case symbol_kind::S_ROWID: // "ROWID"
      case symbol_kind::S_ROWS: // "ROWS"
      case symbol_kind::S_SELECT: // "SELECT"
      case symbol_kind::S_SET: // "SET"
      case symbol_kind::S_STORED: // "STORED"
      case symbol_kind::S_STRICT: // "STRICT"
      case symbol_kind::S_TABLE: // "TABLE"
      case symbol_kind::S_TEMP: // "TEMP"
      case symbol_kind::S_TEMPORARY: // "TEMPORARY"
      case symbol_kind::S_THEN: // "THEN"
      case symbol_kind::S_TRUE: // "TRUE"
      case symbol_kind::S_UNBOUNDED: // "UNBOUNDED"
      case symbol_kind::S_UNIQUE: // "UNIQUE"
      case symbol_kind::S_UPDATE: // "UPDATE"
      case symbol_kind::S_USING: // "USING"
      case symbol_kind::S_VIRTUAL: // "VIRTUAL"
      case symbol_kind::S_WHEN: // "WHEN"
      case symbol_kind::S_WHERE: // "WHERE"
      case symbol_kind::S_WITHOUT: // "WITHOUT"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_NUMERIC: // "numeric"
      case symbol_kind::S_STRINGLITERAL: // "string literal"
      case symbol_kind::S_QUOTEDLITERAL: // "quoted literal"
      case symbol_kind::S_BLOBLITERAL: // "blob literal"
      case symbol_kind::S_BINDPARAMETER: // "bind parameter"
      case symbol_kind::S_literalvalue: // literalvalue
      case symbol_kind::S_id: // id
      case symbol_kind::S_allowed_keywords_as_identifier: // allowed_keywords_as_identifier
      case symbol_kind::S_tableid: // tableid
      case symbol_kind::S_columnid: // columnid
      case symbol_kind::S_signednumber: // signednumber
      case symbol_kind::S_signednumber_or_numeric: // signednumber_or_numeric
      case symbol_kind::S_typename_namelist: // typename_namelist
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_binary_expr: // binary_expr
      case symbol_kind::S_like_expr: // like_expr
      case symbol_kind::S_exprlist_expr: // exprlist_expr
      case symbol_kind::S_function_expr: // function_expr
      case symbol_kind::S_isnull_expr: // isnull_expr
      case symbol_kind::S_between_expr: // between_expr
      case symbol_kind::S_in_expr: // in_expr
      case symbol_kind::S_whenthenlist_expr: // whenthenlist_expr
      case symbol_kind::S_case_expr: // case_expr
      case symbol_kind::S_raise_expr: // raise_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_select_stmt: // select_stmt
      case symbol_kind::S_optional_sort_order: // optional_sort_order
      case symbol_kind::S_optional_where: // optional_where
      case symbol_kind::S_tableid_with_uninteresting_schema: // tableid_with_uninteresting_schema
      case symbol_kind::S_optional_exprlist_with_paren: // optional_exprlist_with_paren
      case symbol_kind::S_optional_conflictclause: // optional_conflictclause
      case symbol_kind::S_optional_typename: // optional_typename
      case symbol_kind::S_optional_storage_identifier: // optional_storage_identifier
      case symbol_kind::S_optional_constraintname: // optional_constraintname
      case symbol_kind::S_fk_clause_part: // fk_clause_part
      case symbol_kind::S_fk_clause_part_list: // fk_clause_part_list
      case symbol_kind::S_optional_fk_clause: // optional_fk_clause
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_columndef_list: // columndef_list
        value.move< ColumnList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columnconstraint_list: // columnconstraint_list
      case symbol_kind::S_tableconstraint: // tableconstraint
      case symbol_kind::S_tableconstraint_list: // tableconstraint_list
      case symbol_kind::S_optional_tableconstraint_list: // optional_tableconstraint_list
        value.move< TableConstraints > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optional_if_not_exists: // optional_if_not_exists
      case symbol_kind::S_optional_unique: // optional_unique
      case symbol_kind::S_optional_temporary: // optional_temporary
      case symbol_kind::S_optional_always_generated: // optional_always_generated
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_createindex_stmt: // createindex_stmt
        value.move< sqlb::IndexPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_indexed_column: // indexed_column
        value.move< sqlb::IndexedColumn > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_indexed_column_list: // indexed_column_list
        value.move< sqlb::IndexedColumnVector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columnid_list: // columnid_list
      case symbol_kind::S_optional_columnid_with_paren_list: // optional_columnid_with_paren_list
        value.move< sqlb::StringVector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_createvirtualtable_stmt: // createvirtualtable_stmt
      case symbol_kind::S_createtable_stmt: // createtable_stmt
        value.move< sqlb::TablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tableoption: // tableoption
      case symbol_kind::S_tableoptions_list: // tableoptions_list
      case symbol_kind::S_optional_tableoptions_list: // optional_tableoptions_list
        value.move< std::bitset<sqlb::Table::NumOptions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columnconstraint: // columnconstraint
        value.move< std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_columndef: // columndef
        value.move< std::shared_ptr<sqlb::Field> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ABORT: // "ABORT"
      case symbol_kind::S_ACTION: // "ACTION"
      case symbol_kind::S_ALWAYS: // "ALWAYS"
      case symbol_kind::S_AND: // "AND"
      case symbol_kind::S_AND_BETWEEN: // "AND BETWEEN"
      case symbol_kind::S_AS: // "AS"
      case symbol_kind::S_ASC: // "ASC"
      case symbol_kind::S_AUTOINCREMENT: // "AUTOINCREMENT"
      case symbol_kind::S_BETWEEN: // "BETWEEN"
      case symbol_kind::S_CASCADE: // "CASCADE"
      case symbol_kind::S_CASE: // "CASE"
      case symbol_kind::S_CAST: // "CAST"
      case symbol_kind::S_CHECK: // "CHECK"
      case symbol_kind::S_COLLATE: // "COLLATE"
      case symbol_kind::S_CONFLICT: // "CONFLICT"
      case symbol_kind::S_CONSTRAINT: // "CONSTRAINT"
      case symbol_kind::S_CREATE: // "CREATE"
      case symbol_kind::S_CURRENT_DATE: // "CURRENT_DATE"
      case symbol_kind::S_CURRENT_TIME: // "CURRENT_TIME"
      case symbol_kind::S_CURRENT_TIMESTAMP: // "CURRENT_TIMESTAMP"
      case symbol_kind::S_DEFAULT: // "DEFAULT"
      case symbol_kind::S_DEFERRABLE: // "DEFERRABLE"
      case symbol_kind::S_DEFERRED: // "DEFERRED"
      case symbol_kind::S_DELETE: // "DELETE"
      case symbol_kind::S_DESC: // "DESC"
      case symbol_kind::S_DISTINCT: // "DISTINCT"
      case symbol_kind::S_ELSE: // "ELSE"
      case symbol_kind::S_END: // "END"
      case symbol_kind::S_ESCAPE: // "ESCAPE"
      case symbol_kind::S_EXISTS: // "EXISTS"
      case symbol_kind::S_FAIL: // "FAIL"
      case symbol_kind::S_FALSE: // "FALSE"
      case symbol_kind::S_FILTER: // "FILTER"
      case symbol_kind::S_FOLLOWING: // "FOLLOWING"
      case symbol_kind::S_FOREIGN: // "FOREIGN"
      case symbol_kind::S_FROM: // "FROM"
      case symbol_kind::S_GENERATED: // "GENERATED"
      case symbol_kind::S_GLOB: // "GLOB"
      case symbol_kind::S_IF: // "IF"
      case symbol_kind::S_IGNORE: // "IGNORE"
      case symbol_kind::S_IMMEDIATE: // "IMMEDIATE"
      case symbol_kind::S_IN: // "IN"
      case symbol_kind::S_INDEX: // "INDEX"
      case symbol_kind::S_INITIALLY: // "INITIALLY"
      case symbol_kind::S_INSERT: // "INSERT"
      case symbol_kind::S_IS: // "IS"
      case symbol_kind::S_ISNULL: // "ISNULL"
      case symbol_kind::S_KEY: // "KEY"
      case symbol_kind::S_LIKE: // "LIKE"
      case symbol_kind::S_MATCH: // "MATCH"
      case symbol_kind::S_NO: // "NO"
      case symbol_kind::S_NOT: // "NOT"
      case symbol_kind::S_NOTNULL: // "NOTNULL"
      case symbol_kind::S_NULL: // "NULL"
      case symbol_kind::S_ON: // "ON"
      case symbol_kind::S_OR: // "OR"
      case symbol_kind::S_OVER: // "OVER"
      case symbol_kind::S_PARTITION: // "PARTITION"
      case symbol_kind::S_PRECEDING: // "PRECEDING"
      case symbol_kind::S_PRIMARY: // "PRIMARY"
      case symbol_kind::S_RAISE: // "RAISE"
      case symbol_kind::S_RANGE: // "RANGE"
      case symbol_kind::S_REFERENCES: // "REFERENCES"
      case symbol_kind::S_REGEXP: // "REGEXP"
      case symbol_kind::S_REPLACE: // "REPLACE"
      case symbol_kind::S_RESTRICT: // "RESTRICT"
      case symbol_kind::S_RETURNING: // "RETURNING"
      case symbol_kind::S_ROLLBACK: // "ROLLBACK"
      case symbol_kind::S_ROWID: // "ROWID"
      case symbol_kind::S_ROWS: // "ROWS"
      case symbol_kind::S_SELECT: // "SELECT"
      case symbol_kind::S_SET: // "SET"
      case symbol_kind::S_STORED: // "STORED"
      case symbol_kind::S_STRICT: // "STRICT"
      case symbol_kind::S_TABLE: // "TABLE"
      case symbol_kind::S_TEMP: // "TEMP"
      case symbol_kind::S_TEMPORARY: // "TEMPORARY"
      case symbol_kind::S_THEN: // "THEN"
      case symbol_kind::S_TRUE: // "TRUE"
      case symbol_kind::S_UNBOUNDED: // "UNBOUNDED"
      case symbol_kind::S_UNIQUE: // "UNIQUE"
      case symbol_kind::S_UPDATE: // "UPDATE"
      case symbol_kind::S_USING: // "USING"
      case symbol_kind::S_VIRTUAL: // "VIRTUAL"
      case symbol_kind::S_WHEN: // "WHEN"
      case symbol_kind::S_WHERE: // "WHERE"
      case symbol_kind::S_WITHOUT: // "WITHOUT"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_NUMERIC: // "numeric"
      case symbol_kind::S_STRINGLITERAL: // "string literal"
      case symbol_kind::S_QUOTEDLITERAL: // "quoted literal"
      case symbol_kind::S_BLOBLITERAL: // "blob literal"
      case symbol_kind::S_BINDPARAMETER: // "bind parameter"
      case symbol_kind::S_literalvalue: // literalvalue
      case symbol_kind::S_id: // id
      case symbol_kind::S_allowed_keywords_as_identifier: // allowed_keywords_as_identifier
      case symbol_kind::S_tableid: // tableid
      case symbol_kind::S_columnid: // columnid
      case symbol_kind::S_signednumber: // signednumber
      case symbol_kind::S_signednumber_or_numeric: // signednumber_or_numeric
      case symbol_kind::S_typename_namelist: // typename_namelist
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_binary_expr: // binary_expr
      case symbol_kind::S_like_expr: // like_expr
      case symbol_kind::S_exprlist_expr: // exprlist_expr
      case symbol_kind::S_function_expr: // function_expr
      case symbol_kind::S_isnull_expr: // isnull_expr
      case symbol_kind::S_between_expr: // between_expr
      case symbol_kind::S_in_expr: // in_expr
      case symbol_kind::S_whenthenlist_expr: // whenthenlist_expr
      case symbol_kind::S_case_expr: // case_expr
      case symbol_kind::S_raise_expr: // raise_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_select_stmt: // select_stmt
      case symbol_kind::S_optional_sort_order: // optional_sort_order
      case symbol_kind::S_optional_where: // optional_where
      case symbol_kind::S_tableid_with_uninteresting_schema: // tableid_with_uninteresting_schema
      case symbol_kind::S_optional_exprlist_with_paren: // optional_exprlist_with_paren
      case symbol_kind::S_optional_conflictclause: // optional_conflictclause
      case symbol_kind::S_optional_typename: // optional_typename
      case symbol_kind::S_optional_storage_identifier: // optional_storage_identifier
      case symbol_kind::S_optional_constraintname: // optional_constraintname
      case symbol_kind::S_fk_clause_part: // fk_clause_part
      case symbol_kind::S_fk_clause_part_list: // fk_clause_part_list
      case symbol_kind::S_optional_fk_clause: // optional_fk_clause
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_columndef_list: // columndef_list
        value.copy< ColumnList > (that.value);
        break;

      case symbol_kind::S_columnconstraint_list: // columnconstraint_list
      case symbol_kind::S_tableconstraint: // tableconstraint
      case symbol_kind::S_tableconstraint_list: // tableconstraint_list
      case symbol_kind::S_optional_tableconstraint_list: // optional_tableconstraint_list
        value.copy< TableConstraints > (that.value);
        break;

      case symbol_kind::S_optional_if_not_exists: // optional_if_not_exists
      case symbol_kind::S_optional_unique: // optional_unique
      case symbol_kind::S_optional_temporary: // optional_temporary
      case symbol_kind::S_optional_always_generated: // optional_always_generated
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_createindex_stmt: // createindex_stmt
        value.copy< sqlb::IndexPtr > (that.value);
        break;

      case symbol_kind::S_indexed_column: // indexed_column
        value.copy< sqlb::IndexedColumn > (that.value);
        break;

      case symbol_kind::S_indexed_column_list: // indexed_column_list
        value.copy< sqlb::IndexedColumnVector > (that.value);
        break;

      case symbol_kind::S_columnid_list: // columnid_list
      case symbol_kind::S_optional_columnid_with_paren_list: // optional_columnid_with_paren_list
        value.copy< sqlb::StringVector > (that.value);
        break;

      case symbol_kind::S_createvirtualtable_stmt: // createvirtualtable_stmt
      case symbol_kind::S_createtable_stmt: // createtable_stmt
        value.copy< sqlb::TablePtr > (that.value);
        break;

      case symbol_kind::S_tableoption: // tableoption
      case symbol_kind::S_tableoptions_list: // tableoptions_list
      case symbol_kind::S_optional_tableoptions_list: // optional_tableoptions_list
        value.copy< std::bitset<sqlb::Table::NumOptions> > (that.value);
        break;

      case symbol_kind::S_columnconstraint: // columnconstraint
        value.copy< std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > (that.value);
        break;

      case symbol_kind::S_columndef: // columndef
        value.copy< std::shared_ptr<sqlb::Field> > (that.value);
        break;

      case symbol_kind::S_ABORT: // "ABORT"
      case symbol_kind::S_ACTION: // "ACTION"
      case symbol_kind::S_ALWAYS: // "ALWAYS"
      case symbol_kind::S_AND: // "AND"
      case symbol_kind::S_AND_BETWEEN: // "AND BETWEEN"
      case symbol_kind::S_AS: // "AS"
      case symbol_kind::S_ASC: // "ASC"
      case symbol_kind::S_AUTOINCREMENT: // "AUTOINCREMENT"
      case symbol_kind::S_BETWEEN: // "BETWEEN"
      case symbol_kind::S_CASCADE: // "CASCADE"
      case symbol_kind::S_CASE: // "CASE"
      case symbol_kind::S_CAST: // "CAST"
      case symbol_kind::S_CHECK: // "CHECK"
      case symbol_kind::S_COLLATE: // "COLLATE"
      case symbol_kind::S_CONFLICT: // "CONFLICT"
      case symbol_kind::S_CONSTRAINT: // "CONSTRAINT"
      case symbol_kind::S_CREATE: // "CREATE"
      case symbol_kind::S_CURRENT_DATE: // "CURRENT_DATE"
      case symbol_kind::S_CURRENT_TIME: // "CURRENT_TIME"
      case symbol_kind::S_CURRENT_TIMESTAMP: // "CURRENT_TIMESTAMP"
      case symbol_kind::S_DEFAULT: // "DEFAULT"
      case symbol_kind::S_DEFERRABLE: // "DEFERRABLE"
      case symbol_kind::S_DEFERRED: // "DEFERRED"
      case symbol_kind::S_DELETE: // "DELETE"
      case symbol_kind::S_DESC: // "DESC"
      case symbol_kind::S_DISTINCT: // "DISTINCT"
      case symbol_kind::S_ELSE: // "ELSE"
      case symbol_kind::S_END: // "END"
      case symbol_kind::S_ESCAPE: // "ESCAPE"
      case symbol_kind::S_EXISTS: // "EXISTS"
      case symbol_kind::S_FAIL: // "FAIL"
      case symbol_kind::S_FALSE: // "FALSE"
      case symbol_kind::S_FILTER: // "FILTER"
      case symbol_kind::S_FOLLOWING: // "FOLLOWING"
      case symbol_kind::S_FOREIGN: // "FOREIGN"
      case symbol_kind::S_FROM: // "FROM"
      case symbol_kind::S_GENERATED: // "GENERATED"
      case symbol_kind::S_GLOB: // "GLOB"
      case symbol_kind::S_IF: // "IF"
      case symbol_kind::S_IGNORE: // "IGNORE"
      case symbol_kind::S_IMMEDIATE: // "IMMEDIATE"
      case symbol_kind::S_IN: // "IN"
      case symbol_kind::S_INDEX: // "INDEX"
      case symbol_kind::S_INITIALLY: // "INITIALLY"
      case symbol_kind::S_INSERT: // "INSERT"
      case symbol_kind::S_IS: // "IS"
      case symbol_kind::S_ISNULL: // "ISNULL"
      case symbol_kind::S_KEY: // "KEY"
      case symbol_kind::S_LIKE: // "LIKE"
      case symbol_kind::S_MATCH: // "MATCH"
      case symbol_kind::S_NO: // "NO"
      case symbol_kind::S_NOT: // "NOT"
      case symbol_kind::S_NOTNULL: // "NOTNULL"
      case symbol_kind::S_NULL: // "NULL"
      case symbol_kind::S_ON: // "ON"
      case symbol_kind::S_OR: // "OR"
      case symbol_kind::S_OVER: // "OVER"
      case symbol_kind::S_PARTITION: // "PARTITION"
      case symbol_kind::S_PRECEDING: // "PRECEDING"
      case symbol_kind::S_PRIMARY: // "PRIMARY"
      case symbol_kind::S_RAISE: // "RAISE"
      case symbol_kind::S_RANGE: // "RANGE"
      case symbol_kind::S_REFERENCES: // "REFERENCES"
      case symbol_kind::S_REGEXP: // "REGEXP"
      case symbol_kind::S_REPLACE: // "REPLACE"
      case symbol_kind::S_RESTRICT: // "RESTRICT"
      case symbol_kind::S_RETURNING: // "RETURNING"
      case symbol_kind::S_ROLLBACK: // "ROLLBACK"
      case symbol_kind::S_ROWID: // "ROWID"
      case symbol_kind::S_ROWS: // "ROWS"
      case symbol_kind::S_SELECT: // "SELECT"
      case symbol_kind::S_SET: // "SET"
      case symbol_kind::S_STORED: // "STORED"
      case symbol_kind::S_STRICT: // "STRICT"
      case symbol_kind::S_TABLE: // "TABLE"
      case symbol_kind::S_TEMP: // "TEMP"
      case symbol_kind::S_TEMPORARY: // "TEMPORARY"
      case symbol_kind::S_THEN: // "THEN"
      case symbol_kind::S_TRUE: // "TRUE"
      case symbol_kind::S_UNBOUNDED: // "UNBOUNDED"
      case symbol_kind::S_UNIQUE: // "UNIQUE"
      case symbol_kind::S_UPDATE: // "UPDATE"
      case symbol_kind::S_USING: // "USING"
      case symbol_kind::S_VIRTUAL: // "VIRTUAL"
      case symbol_kind::S_WHEN: // "WHEN"
      case symbol_kind::S_WHERE: // "WHERE"
      case symbol_kind::S_WITHOUT: // "WITHOUT"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_NUMERIC: // "numeric"
      case symbol_kind::S_STRINGLITERAL: // "string literal"
      case symbol_kind::S_QUOTEDLITERAL: // "quoted literal"
      case symbol_kind::S_BLOBLITERAL: // "blob literal"
      case symbol_kind::S_BINDPARAMETER: // "bind parameter"
      case symbol_kind::S_literalvalue: // literalvalue
      case symbol_kind::S_id: // id
      case symbol_kind::S_allowed_keywords_as_identifier: // allowed_keywords_as_identifier
      case symbol_kind::S_tableid: // tableid
      case symbol_kind::S_columnid: // columnid
      case symbol_kind::S_signednumber: // signednumber
      case symbol_kind::S_signednumber_or_numeric: // signednumber_or_numeric
      case symbol_kind::S_typename_namelist: // typename_namelist
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_binary_expr: // binary_expr
      case symbol_kind::S_like_expr: // like_expr
      case symbol_kind::S_exprlist_expr: // exprlist_expr
      case symbol_kind::S_function_expr: // function_expr
      case symbol_kind::S_isnull_expr: // isnull_expr
      case symbol_kind::S_between_expr: // between_expr
      case symbol_kind::S_in_expr: // in_expr
      case symbol_kind::S_whenthenlist_expr: // whenthenlist_expr
      case symbol_kind::S_case_expr: // case_expr
      case symbol_kind::S_raise_expr: // raise_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_select_stmt: // select_stmt
      case symbol_kind::S_optional_sort_order: // optional_sort_order
      case symbol_kind::S_optional_where: // optional_where
      case symbol_kind::S_tableid_with_uninteresting_schema: // tableid_with_uninteresting_schema
      case symbol_kind::S_optional_exprlist_with_paren: // optional_exprlist_with_paren
      case symbol_kind::S_optional_conflictclause: // optional_conflictclause
      case symbol_kind::S_optional_typename: // optional_typename
      case symbol_kind::S_optional_storage_identifier: // optional_storage_identifier
      case symbol_kind::S_optional_constraintname: // optional_constraintname
      case symbol_kind::S_fk_clause_part: // fk_clause_part
      case symbol_kind::S_fk_clause_part_list: // fk_clause_part_list
      case symbol_kind::S_optional_fk_clause: // optional_fk_clause
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_columndef_list: // columndef_list
        value.move< ColumnList > (that.value);
        break;

      case symbol_kind::S_columnconstraint_list: // columnconstraint_list
      case symbol_kind::S_tableconstraint: // tableconstraint
      case symbol_kind::S_tableconstraint_list: // tableconstraint_list
      case symbol_kind::S_optional_tableconstraint_list: // optional_tableconstraint_list
        value.move< TableConstraints > (that.value);
        break;

      case symbol_kind::S_optional_if_not_exists: // optional_if_not_exists
      case symbol_kind::S_optional_unique: // optional_unique
      case symbol_kind::S_optional_temporary: // optional_temporary
      case symbol_kind::S_optional_always_generated: // optional_always_generated
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_createindex_stmt: // createindex_stmt
        value.move< sqlb::IndexPtr > (that.value);
        break;

      case symbol_kind::S_indexed_column: // indexed_column
        value.move< sqlb::IndexedColumn > (that.value);
        break;

      case symbol_kind::S_indexed_column_list: // indexed_column_list
        value.move< sqlb::IndexedColumnVector > (that.value);
        break;

      case symbol_kind::S_columnid_list: // columnid_list
      case symbol_kind::S_optional_columnid_with_paren_list: // optional_columnid_with_paren_list
        value.move< sqlb::StringVector > (that.value);
        break;

      case symbol_kind::S_createvirtualtable_stmt: // createvirtualtable_stmt
      case symbol_kind::S_createtable_stmt: // createtable_stmt
        value.move< sqlb::TablePtr > (that.value);
        break;

      case symbol_kind::S_tableoption: // tableoption
      case symbol_kind::S_tableoptions_list: // tableoptions_list
      case symbol_kind::S_optional_tableoptions_list: // optional_tableoptions_list
        value.move< std::bitset<sqlb::Table::NumOptions> > (that.value);
        break;

      case symbol_kind::S_columnconstraint: // columnconstraint
        value.move< std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > (that.value);
        break;

      case symbol_kind::S_columndef: // columndef
        value.move< std::shared_ptr<sqlb::Field> > (that.value);
        break;

      case symbol_kind::S_ABORT: // "ABORT"
      case symbol_kind::S_ACTION: // "ACTION"
      case symbol_kind::S_ALWAYS: // "ALWAYS"
      case symbol_kind::S_AND: // "AND"
      case symbol_kind::S_AND_BETWEEN: // "AND BETWEEN"
      case symbol_kind::S_AS: // "AS"
      case symbol_kind::S_ASC: // "ASC"
      case symbol_kind::S_AUTOINCREMENT: // "AUTOINCREMENT"
      case symbol_kind::S_BETWEEN: // "BETWEEN"
      case symbol_kind::S_CASCADE: // "CASCADE"
      case symbol_kind::S_CASE: // "CASE"
      case symbol_kind::S_CAST: // "CAST"
      case symbol_kind::S_CHECK: // "CHECK"
      case symbol_kind::S_COLLATE: // "COLLATE"
      case symbol_kind::S_CONFLICT: // "CONFLICT"
      case symbol_kind::S_CONSTRAINT: // "CONSTRAINT"
      case symbol_kind::S_CREATE: // "CREATE"
      case symbol_kind::S_CURRENT_DATE: // "CURRENT_DATE"
      case symbol_kind::S_CURRENT_TIME: // "CURRENT_TIME"
      case symbol_kind::S_CURRENT_TIMESTAMP: // "CURRENT_TIMESTAMP"
      case symbol_kind::S_DEFAULT: // "DEFAULT"
      case symbol_kind::S_DEFERRABLE: // "DEFERRABLE"
      case symbol_kind::S_DEFERRED: // "DEFERRED"
      case symbol_kind::S_DELETE: // "DELETE"
      case symbol_kind::S_DESC: // "DESC"
      case symbol_kind::S_DISTINCT: // "DISTINCT"
      case symbol_kind::S_ELSE: // "ELSE"
      case symbol_kind::S_END: // "END"
      case symbol_kind::S_ESCAPE: // "ESCAPE"
      case symbol_kind::S_EXISTS: // "EXISTS"
      case symbol_kind::S_FAIL: // "FAIL"
      case symbol_kind::S_FALSE: // "FALSE"
      case symbol_kind::S_FILTER: // "FILTER"
      case symbol_kind::S_FOLLOWING: // "FOLLOWING"
      case symbol_kind::S_FOREIGN: // "FOREIGN"
      case symbol_kind::S_FROM: // "FROM"
      case symbol_kind::S_GENERATED: // "GENERATED"
      case symbol_kind::S_GLOB: // "GLOB"
      case symbol_kind::S_IF: // "IF"
      case symbol_kind::S_IGNORE: // "IGNORE"
      case symbol_kind::S_IMMEDIATE: // "IMMEDIATE"
      case symbol_kind::S_IN: // "IN"
      case symbol_kind::S_INDEX: // "INDEX"
      case symbol_kind::S_INITIALLY: // "INITIALLY"
      case symbol_kind::S_INSERT: // "INSERT"
      case symbol_kind::S_IS: // "IS"
      case symbol_kind::S_ISNULL: // "ISNULL"
      case symbol_kind::S_KEY: // "KEY"
      case symbol_kind::S_LIKE: // "LIKE"
      case symbol_kind::S_MATCH: // "MATCH"
      case symbol_kind::S_NO: // "NO"
      case symbol_kind::S_NOT: // "NOT"
      case symbol_kind::S_NOTNULL: // "NOTNULL"
      case symbol_kind::S_NULL: // "NULL"
      case symbol_kind::S_ON: // "ON"
      case symbol_kind::S_OR: // "OR"
      case symbol_kind::S_OVER: // "OVER"
      case symbol_kind::S_PARTITION: // "PARTITION"
      case symbol_kind::S_PRECEDING: // "PRECEDING"
      case symbol_kind::S_PRIMARY: // "PRIMARY"
      case symbol_kind::S_RAISE: // "RAISE"
      case symbol_kind::S_RANGE: // "RANGE"
      case symbol_kind::S_REFERENCES: // "REFERENCES"
      case symbol_kind::S_REGEXP: // "REGEXP"
      case symbol_kind::S_REPLACE: // "REPLACE"
      case symbol_kind::S_RESTRICT: // "RESTRICT"
      case symbol_kind::S_RETURNING: // "RETURNING"
      case symbol_kind::S_ROLLBACK: // "ROLLBACK"
      case symbol_kind::S_ROWID: // "ROWID"
      case symbol_kind::S_ROWS: // "ROWS"
      case symbol_kind::S_SELECT: // "SELECT"
      case symbol_kind::S_SET: // "SET"
      case symbol_kind::S_STORED: // "STORED"
      case symbol_kind::S_STRICT: // "STRICT"
      case symbol_kind::S_TABLE: // "TABLE"
      case symbol_kind::S_TEMP: // "TEMP"
      case symbol_kind::S_TEMPORARY: // "TEMPORARY"
      case symbol_kind::S_THEN: // "THEN"
      case symbol_kind::S_TRUE: // "TRUE"
      case symbol_kind::S_UNBOUNDED: // "UNBOUNDED"
      case symbol_kind::S_UNIQUE: // "UNIQUE"
      case symbol_kind::S_UPDATE: // "UPDATE"
      case symbol_kind::S_USING: // "USING"
      case symbol_kind::S_VIRTUAL: // "VIRTUAL"
      case symbol_kind::S_WHEN: // "WHEN"
      case symbol_kind::S_WHERE: // "WHERE"
      case symbol_kind::S_WITHOUT: // "WITHOUT"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_NUMERIC: // "numeric"
      case symbol_kind::S_STRINGLITERAL: // "string literal"
      case symbol_kind::S_QUOTEDLITERAL: // "quoted literal"
      case symbol_kind::S_BLOBLITERAL: // "blob literal"
      case symbol_kind::S_BINDPARAMETER: // "bind parameter"
      case symbol_kind::S_literalvalue: // literalvalue
      case symbol_kind::S_id: // id
      case symbol_kind::S_allowed_keywords_as_identifier: // allowed_keywords_as_identifier
      case symbol_kind::S_tableid: // tableid
      case symbol_kind::S_columnid: // columnid
      case symbol_kind::S_signednumber: // signednumber
      case symbol_kind::S_signednumber_or_numeric: // signednumber_or_numeric
      case symbol_kind::S_typename_namelist: // typename_namelist
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_binary_expr: // binary_expr
      case symbol_kind::S_like_expr: // like_expr
      case symbol_kind::S_exprlist_expr: // exprlist_expr
      case symbol_kind::S_function_expr: // function_expr
      case symbol_kind::S_isnull_expr: // isnull_expr
      case symbol_kind::S_between_expr: // between_expr
      case symbol_kind::S_in_expr: // in_expr
      case symbol_kind::S_whenthenlist_expr: // whenthenlist_expr
      case symbol_kind::S_case_expr: // case_expr
      case symbol_kind::S_raise_expr: // raise_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_select_stmt: // select_stmt
      case symbol_kind::S_optional_sort_order: // optional_sort_order
      case symbol_kind::S_optional_where: // optional_where
      case symbol_kind::S_tableid_with_uninteresting_schema: // tableid_with_uninteresting_schema
      case symbol_kind::S_optional_exprlist_with_paren: // optional_exprlist_with_paren
      case symbol_kind::S_optional_conflictclause: // optional_conflictclause
      case symbol_kind::S_optional_typename: // optional_typename
      case symbol_kind::S_optional_storage_identifier: // optional_storage_identifier
      case symbol_kind::S_optional_constraintname: // optional_constraintname
      case symbol_kind::S_fk_clause_part: // fk_clause_part
      case symbol_kind::S_fk_clause_part_list: // fk_clause_part_list
      case symbol_kind::S_optional_fk_clause: // optional_fk_clause
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (yyscanner, drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_columndef_list: // columndef_list
        yylhs.value.emplace< ColumnList > ();
        break;

      case symbol_kind::S_columnconstraint_list: // columnconstraint_list
      case symbol_kind::S_tableconstraint: // tableconstraint
      case symbol_kind::S_tableconstraint_list: // tableconstraint_list
      case symbol_kind::S_optional_tableconstraint_list: // optional_tableconstraint_list
        yylhs.value.emplace< TableConstraints > ();
        break;

      case symbol_kind::S_optional_if_not_exists: // optional_if_not_exists
      case symbol_kind::S_optional_unique: // optional_unique
      case symbol_kind::S_optional_temporary: // optional_temporary
      case symbol_kind::S_optional_always_generated: // optional_always_generated
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_createindex_stmt: // createindex_stmt
        yylhs.value.emplace< sqlb::IndexPtr > ();
        break;

      case symbol_kind::S_indexed_column: // indexed_column
        yylhs.value.emplace< sqlb::IndexedColumn > ();
        break;

      case symbol_kind::S_indexed_column_list: // indexed_column_list
        yylhs.value.emplace< sqlb::IndexedColumnVector > ();
        break;

      case symbol_kind::S_columnid_list: // columnid_list
      case symbol_kind::S_optional_columnid_with_paren_list: // optional_columnid_with_paren_list
        yylhs.value.emplace< sqlb::StringVector > ();
        break;

      case symbol_kind::S_createvirtualtable_stmt: // createvirtualtable_stmt
      case symbol_kind::S_createtable_stmt: // createtable_stmt
        yylhs.value.emplace< sqlb::TablePtr > ();
        break;

      case symbol_kind::S_tableoption: // tableoption
      case symbol_kind::S_tableoptions_list: // tableoptions_list
      case symbol_kind::S_optional_tableoptions_list: // optional_tableoptions_list
        yylhs.value.emplace< std::bitset<sqlb::Table::NumOptions> > ();
        break;

      case symbol_kind::S_columnconstraint: // columnconstraint
        yylhs.value.emplace< std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ();
        break;

      case symbol_kind::S_columndef: // columndef
        yylhs.value.emplace< std::shared_ptr<sqlb::Field> > ();
        break;

      case symbol_kind::S_ABORT: // "ABORT"
      case symbol_kind::S_ACTION: // "ACTION"
      case symbol_kind::S_ALWAYS: // "ALWAYS"
      case symbol_kind::S_AND: // "AND"
      case symbol_kind::S_AND_BETWEEN: // "AND BETWEEN"
      case symbol_kind::S_AS: // "AS"
      case symbol_kind::S_ASC: // "ASC"
      case symbol_kind::S_AUTOINCREMENT: // "AUTOINCREMENT"
      case symbol_kind::S_BETWEEN: // "BETWEEN"
      case symbol_kind::S_CASCADE: // "CASCADE"
      case symbol_kind::S_CASE: // "CASE"
      case symbol_kind::S_CAST: // "CAST"
      case symbol_kind::S_CHECK: // "CHECK"
      case symbol_kind::S_COLLATE: // "COLLATE"
      case symbol_kind::S_CONFLICT: // "CONFLICT"
      case symbol_kind::S_CONSTRAINT: // "CONSTRAINT"
      case symbol_kind::S_CREATE: // "CREATE"
      case symbol_kind::S_CURRENT_DATE: // "CURRENT_DATE"
      case symbol_kind::S_CURRENT_TIME: // "CURRENT_TIME"
      case symbol_kind::S_CURRENT_TIMESTAMP: // "CURRENT_TIMESTAMP"
      case symbol_kind::S_DEFAULT: // "DEFAULT"
      case symbol_kind::S_DEFERRABLE: // "DEFERRABLE"
      case symbol_kind::S_DEFERRED: // "DEFERRED"
      case symbol_kind::S_DELETE: // "DELETE"
      case symbol_kind::S_DESC: // "DESC"
      case symbol_kind::S_DISTINCT: // "DISTINCT"
      case symbol_kind::S_ELSE: // "ELSE"
      case symbol_kind::S_END: // "END"
      case symbol_kind::S_ESCAPE: // "ESCAPE"
      case symbol_kind::S_EXISTS: // "EXISTS"
      case symbol_kind::S_FAIL: // "FAIL"
      case symbol_kind::S_FALSE: // "FALSE"
      case symbol_kind::S_FILTER: // "FILTER"
      case symbol_kind::S_FOLLOWING: // "FOLLOWING"
      case symbol_kind::S_FOREIGN: // "FOREIGN"
      case symbol_kind::S_FROM: // "FROM"
      case symbol_kind::S_GENERATED: // "GENERATED"
      case symbol_kind::S_GLOB: // "GLOB"
      case symbol_kind::S_IF: // "IF"
      case symbol_kind::S_IGNORE: // "IGNORE"
      case symbol_kind::S_IMMEDIATE: // "IMMEDIATE"
      case symbol_kind::S_IN: // "IN"
      case symbol_kind::S_INDEX: // "INDEX"
      case symbol_kind::S_INITIALLY: // "INITIALLY"
      case symbol_kind::S_INSERT: // "INSERT"
      case symbol_kind::S_IS: // "IS"
      case symbol_kind::S_ISNULL: // "ISNULL"
      case symbol_kind::S_KEY: // "KEY"
      case symbol_kind::S_LIKE: // "LIKE"
      case symbol_kind::S_MATCH: // "MATCH"
      case symbol_kind::S_NO: // "NO"
      case symbol_kind::S_NOT: // "NOT"
      case symbol_kind::S_NOTNULL: // "NOTNULL"
      case symbol_kind::S_NULL: // "NULL"
      case symbol_kind::S_ON: // "ON"
      case symbol_kind::S_OR: // "OR"
      case symbol_kind::S_OVER: // "OVER"
      case symbol_kind::S_PARTITION: // "PARTITION"
      case symbol_kind::S_PRECEDING: // "PRECEDING"
      case symbol_kind::S_PRIMARY: // "PRIMARY"
      case symbol_kind::S_RAISE: // "RAISE"
      case symbol_kind::S_RANGE: // "RANGE"
      case symbol_kind::S_REFERENCES: // "REFERENCES"
      case symbol_kind::S_REGEXP: // "REGEXP"
      case symbol_kind::S_REPLACE: // "REPLACE"
      case symbol_kind::S_RESTRICT: // "RESTRICT"
      case symbol_kind::S_RETURNING: // "RETURNING"
      case symbol_kind::S_ROLLBACK: // "ROLLBACK"
      case symbol_kind::S_ROWID: // "ROWID"
      case symbol_kind::S_ROWS: // "ROWS"
      case symbol_kind::S_SELECT: // "SELECT"
      case symbol_kind::S_SET: // "SET"
      case symbol_kind::S_STORED: // "STORED"
      case symbol_kind::S_STRICT: // "STRICT"
      case symbol_kind::S_TABLE: // "TABLE"
      case symbol_kind::S_TEMP: // "TEMP"
      case symbol_kind::S_TEMPORARY: // "TEMPORARY"
      case symbol_kind::S_THEN: // "THEN"
      case symbol_kind::S_TRUE: // "TRUE"
      case symbol_kind::S_UNBOUNDED: // "UNBOUNDED"
      case symbol_kind::S_UNIQUE: // "UNIQUE"
      case symbol_kind::S_UPDATE: // "UPDATE"
      case symbol_kind::S_USING: // "USING"
      case symbol_kind::S_VIRTUAL: // "VIRTUAL"
      case symbol_kind::S_WHEN: // "WHEN"
      case symbol_kind::S_WHERE: // "WHERE"
      case symbol_kind::S_WITHOUT: // "WITHOUT"
      case symbol_kind::S_IDENTIFIER: // "identifier"
      case symbol_kind::S_NUMERIC: // "numeric"
      case symbol_kind::S_STRINGLITERAL: // "string literal"
      case symbol_kind::S_QUOTEDLITERAL: // "quoted literal"
      case symbol_kind::S_BLOBLITERAL: // "blob literal"
      case symbol_kind::S_BINDPARAMETER: // "bind parameter"
      case symbol_kind::S_literalvalue: // literalvalue
      case symbol_kind::S_id: // id
      case symbol_kind::S_allowed_keywords_as_identifier: // allowed_keywords_as_identifier
      case symbol_kind::S_tableid: // tableid
      case symbol_kind::S_columnid: // columnid
      case symbol_kind::S_signednumber: // signednumber
      case symbol_kind::S_signednumber_or_numeric: // signednumber_or_numeric
      case symbol_kind::S_typename_namelist: // typename_namelist
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_unary_expr: // unary_expr
      case symbol_kind::S_binary_expr: // binary_expr
      case symbol_kind::S_like_expr: // like_expr
      case symbol_kind::S_exprlist_expr: // exprlist_expr
      case symbol_kind::S_function_expr: // function_expr
      case symbol_kind::S_isnull_expr: // isnull_expr
      case symbol_kind::S_between_expr: // between_expr
      case symbol_kind::S_in_expr: // in_expr
      case symbol_kind::S_whenthenlist_expr: // whenthenlist_expr
      case symbol_kind::S_case_expr: // case_expr
      case symbol_kind::S_raise_expr: // raise_expr
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_select_stmt: // select_stmt
      case symbol_kind::S_optional_sort_order: // optional_sort_order
      case symbol_kind::S_optional_where: // optional_where
      case symbol_kind::S_tableid_with_uninteresting_schema: // tableid_with_uninteresting_schema
      case symbol_kind::S_optional_exprlist_with_paren: // optional_exprlist_with_paren
      case symbol_kind::S_optional_conflictclause: // optional_conflictclause
      case symbol_kind::S_optional_typename: // optional_typename
      case symbol_kind::S_optional_storage_identifier: // optional_storage_identifier
      case symbol_kind::S_optional_constraintname: // optional_constraintname
      case symbol_kind::S_fk_clause_part: // fk_clause_part
      case symbol_kind::S_fk_clause_part_list: // fk_clause_part_list
      case symbol_kind::S_optional_fk_clause: // optional_fk_clause
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 4: // statement: createindex_stmt
#line 278 "sqlite3_parser.yy"
                                        { drv.result = yystack_[0].value.as < sqlb::IndexPtr > (); }
#line 1479 "sqlite3_parser.cpp"
    break;

  case 5: // statement: createvirtualtable_stmt
#line 279 "sqlite3_parser.yy"
                                        { drv.result = yystack_[0].value.as < sqlb::TablePtr > (); }
#line 1485 "sqlite3_parser.cpp"
    break;

  case 6: // statement: createtable_stmt
#line 280 "sqlite3_parser.yy"
                                        { drv.result = yystack_[0].value.as < sqlb::TablePtr > (); }
#line 1491 "sqlite3_parser.cpp"
    break;

  case 7: // literalvalue: "numeric"
#line 288 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1497 "sqlite3_parser.cpp"
    break;

  case 8: // literalvalue: "string literal"
#line 289 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1503 "sqlite3_parser.cpp"
    break;

  case 9: // literalvalue: "blob literal"
#line 290 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1509 "sqlite3_parser.cpp"
    break;

  case 10: // literalvalue: "NULL"
#line 291 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1515 "sqlite3_parser.cpp"
    break;

  case 11: // literalvalue: "TRUE"
#line 292 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1521 "sqlite3_parser.cpp"
    break;

  case 12: // literalvalue: "FALSE"
#line 293 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1527 "sqlite3_parser.cpp"
    break;

  case 13: // literalvalue: "CURRENT_TIME"
#line 294 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1533 "sqlite3_parser.cpp"
    break;

  case 14: // literalvalue: "CURRENT_DATE"
#line 295 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1539 "sqlite3_parser.cpp"
    break;

  case 15: // literalvalue: "CURRENT_TIMESTAMP"
#line 296 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1545 "sqlite3_parser.cpp"
    break;

  case 16: // id: "identifier"
#line 300 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1551 "sqlite3_parser.cpp"
    break;

  case 17: // id: "quoted literal"
#line 301 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1557 "sqlite3_parser.cpp"
    break;

  case 18: // allowed_keywords_as_identifier: "ABORT"
#line 306 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1563 "sqlite3_parser.cpp"
    break;

  case 19: // allowed_keywords_as_identifier: "ACTION"
#line 307 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1569 "sqlite3_parser.cpp"
    break;

  case 20: // allowed_keywords_as_identifier: "ALWAYS"
#line 308 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1575 "sqlite3_parser.cpp"
    break;

  case 21: // allowed_keywords_as_identifier: "ASC"
#line 309 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1581 "sqlite3_parser.cpp"
    break;

  case 22: // allowed_keywords_as_identifier: "CASCADE"
#line 310 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1587 "sqlite3_parser.cpp"
    break;

  case 23: // allowed_keywords_as_identifier: "CAST"
#line 311 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1593 "sqlite3_parser.cpp"
    break;

  case 24: // allowed_keywords_as_identifier: "CONFLICT"
#line 312 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1599 "sqlite3_parser.cpp"
    break;

  case 25: // allowed_keywords_as_identifier: "DEFERRED"
#line 313 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1605 "sqlite3_parser.cpp"
    break;

  case 26: // allowed_keywords_as_identifier: "DESC"
#line 314 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1611 "sqlite3_parser.cpp"
    break;

  case 27: // allowed_keywords_as_identifier: "END"
#line 315 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1617 "sqlite3_parser.cpp"
    break;

  case 28: // allowed_keywords_as_identifier: "FAIL"
#line 316 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1623 "sqlite3_parser.cpp"
    break;

  case 29: // allowed_keywords_as_identifier: "FILTER"
#line 317 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1629 "sqlite3_parser.cpp"
    break;

  case 30: // allowed_keywords_as_identifier: "FOLLOWING"
#line 318 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1635 "sqlite3_parser.cpp"
    break;

  case 31: // allowed_keywords_as_identifier: "GENERATED"
#line 319 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1641 "sqlite3_parser.cpp"
    break;

  case 32: // allowed_keywords_as_identifier: "GLOB"
#line 320 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1647 "sqlite3_parser.cpp"
    break;

  case 33: // allowed_keywords_as_identifier: "KEY"
#line 321 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1653 "sqlite3_parser.cpp"
    break;

  case 34: // allowed_keywords_as_identifier: "LIKE"
#line 322 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1659 "sqlite3_parser.cpp"
    break;

  case 35: // allowed_keywords_as_identifier: "IGNORE"
#line 323 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1665 "sqlite3_parser.cpp"
    break;

  case 36: // allowed_keywords_as_identifier: "INITIALLY"
#line 324 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1671 "sqlite3_parser.cpp"
    break;

  case 37: // allowed_keywords_as_identifier: "IMMEDIATE"
#line 325 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1677 "sqlite3_parser.cpp"
    break;

  case 38: // allowed_keywords_as_identifier: "MATCH"
#line 326 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1683 "sqlite3_parser.cpp"
    break;

  case 39: // allowed_keywords_as_identifier: "NO"
#line 327 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1689 "sqlite3_parser.cpp"
    break;

  case 40: // allowed_keywords_as_identifier: "OVER"
#line 328 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1695 "sqlite3_parser.cpp"
    break;

  case 41: // allowed_keywords_as_identifier: "PARTITION"
#line 329 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1701 "sqlite3_parser.cpp"
    break;

  case 42: // allowed_keywords_as_identifier: "PRECEDING"
#line 330 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1707 "sqlite3_parser.cpp"
    break;

  case 43: // allowed_keywords_as_identifier: "RAISE"
#line 331 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1713 "sqlite3_parser.cpp"
    break;

  case 44: // allowed_keywords_as_identifier: "RANGE"
#line 332 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1719 "sqlite3_parser.cpp"
    break;

  case 45: // allowed_keywords_as_identifier: "REGEXP"
#line 333 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1725 "sqlite3_parser.cpp"
    break;

  case 46: // allowed_keywords_as_identifier: "REPLACE"
#line 334 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1731 "sqlite3_parser.cpp"
    break;

  case 47: // allowed_keywords_as_identifier: "RESTRICT"
#line 335 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1737 "sqlite3_parser.cpp"
    break;

  case 48: // allowed_keywords_as_identifier: "RETURNING"
#line 336 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1743 "sqlite3_parser.cpp"
    break;

  case 49: // allowed_keywords_as_identifier: "ROLLBACK"
#line 337 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1749 "sqlite3_parser.cpp"
    break;

  case 50: // allowed_keywords_as_identifier: "ROWID"
#line 338 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1755 "sqlite3_parser.cpp"
    break;

  case 51: // allowed_keywords_as_identifier: "ROWS"
#line 339 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1761 "sqlite3_parser.cpp"
    break;

  case 52: // allowed_keywords_as_identifier: "STORED"
#line 340 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1767 "sqlite3_parser.cpp"
    break;

  case 53: // allowed_keywords_as_identifier: "STRICT"
#line 341 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1773 "sqlite3_parser.cpp"
    break;

  case 54: // allowed_keywords_as_identifier: "TEMPORARY"
#line 342 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1779 "sqlite3_parser.cpp"
    break;

  case 55: // allowed_keywords_as_identifier: "TEMP"
#line 343 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1785 "sqlite3_parser.cpp"
    break;

  case 56: // allowed_keywords_as_identifier: "UNBOUNDED"
#line 344 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1791 "sqlite3_parser.cpp"
    break;

  case 57: // allowed_keywords_as_identifier: "VIRTUAL"
#line 345 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1797 "sqlite3_parser.cpp"
    break;

  case 58: // allowed_keywords_as_identifier: "WITHOUT"
#line 346 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1803 "sqlite3_parser.cpp"
    break;

  case 59: // tableid: allowed_keywords_as_identifier
#line 350 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1809 "sqlite3_parser.cpp"
    break;

  case 60: // tableid: "CURRENT_TIME"
#line 351 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1815 "sqlite3_parser.cpp"
    break;

  case 61: // tableid: "CURRENT_DATE"
#line 352 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1821 "sqlite3_parser.cpp"
    break;

  case 62: // tableid: "CURRENT_TIMESTAMP"
#line 353 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1827 "sqlite3_parser.cpp"
    break;

  case 63: // tableid: id
#line 354 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1833 "sqlite3_parser.cpp"
    break;

  case 64: // tableid: "string literal"
#line 355 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = unquote_text(yystack_[0].value.as < std::string > (), '\''); }
#line 1839 "sqlite3_parser.cpp"
    break;

  case 65: // columnid: allowed_keywords_as_identifier
#line 359 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1845 "sqlite3_parser.cpp"
    break;

  case 66: // columnid: "CURRENT_TIME"
#line 360 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1851 "sqlite3_parser.cpp"
    break;

  case 67: // columnid: "CURRENT_DATE"
#line 361 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1857 "sqlite3_parser.cpp"
    break;

  case 68: // columnid: "CURRENT_TIMESTAMP"
#line 362 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1863 "sqlite3_parser.cpp"
    break;

  case 69: // columnid: "IF"
#line 363 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1869 "sqlite3_parser.cpp"
    break;

  case 70: // columnid: id
#line 364 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1875 "sqlite3_parser.cpp"
    break;

  case 71: // columnid: "string literal"
#line 365 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = unquote_text(yystack_[0].value.as < std::string > (), '\''); }
#line 1881 "sqlite3_parser.cpp"
    break;

  case 72: // signednumber: "+" "numeric"
#line 369 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "+" + yystack_[0].value.as < std::string > (); }
#line 1887 "sqlite3_parser.cpp"
    break;

  case 73: // signednumber: "-" "numeric"
#line 370 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "-" + yystack_[0].value.as < std::string > (); }
#line 1893 "sqlite3_parser.cpp"
    break;

  case 74: // signednumber_or_numeric: signednumber
#line 374 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1899 "sqlite3_parser.cpp"
    break;

  case 75: // signednumber_or_numeric: "numeric"
#line 375 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1905 "sqlite3_parser.cpp"
    break;

  case 76: // typename_namelist: tableid
#line 379 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1911 "sqlite3_parser.cpp"
    break;

  case 77: // typename_namelist: typename_namelist tableid
#line 380 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 1917 "sqlite3_parser.cpp"
    break;

  case 78: // type_name: typename_namelist
#line 384 "sqlite3_parser.yy"
                                                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1923 "sqlite3_parser.cpp"
    break;

  case 79: // type_name: typename_namelist "(" signednumber_or_numeric ")"
#line 385 "sqlite3_parser.yy"
                                                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 1929 "sqlite3_parser.cpp"
    break;

  case 80: // type_name: typename_namelist "(" signednumber_or_numeric "," signednumber_or_numeric ")"
#line 386 "sqlite3_parser.yy"
                                                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + "(" + yystack_[3].value.as < std::string > () + ", " + yystack_[1].value.as < std::string > () + ")"; }
#line 1935 "sqlite3_parser.cpp"
    break;

  case 81: // unary_expr: "-" expr
#line 390 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "-" + yystack_[0].value.as < std::string > (); }
#line 1941 "sqlite3_parser.cpp"
    break;

  case 82: // unary_expr: "+" expr
#line 391 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "+" + yystack_[0].value.as < std::string > (); }
#line 1947 "sqlite3_parser.cpp"
    break;

  case 83: // unary_expr: "~" expr
#line 392 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "~" + yystack_[0].value.as < std::string > (); }
#line 1953 "sqlite3_parser.cpp"
    break;

  case 84: // unary_expr: "NOT" expr
#line 393 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "NOT " + yystack_[0].value.as < std::string > (); }
#line 1959 "sqlite3_parser.cpp"
    break;

  case 85: // binary_expr: expr "||" expr
#line 397 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " || " + yystack_[0].value.as < std::string > (); }
#line 1965 "sqlite3_parser.cpp"
    break;

  case 86: // binary_expr: expr "*" expr
#line 398 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " * " + yystack_[0].value.as < std::string > (); }
#line 1971 "sqlite3_parser.cpp"
    break;

  case 87: // binary_expr: expr "/" expr
#line 399 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " / " + yystack_[0].value.as < std::string > (); }
#line 1977 "sqlite3_parser.cpp"
    break;

  case 88: // binary_expr: expr "->" expr
#line 400 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " -> " + yystack_[0].value.as < std::string > (); }
#line 1983 "sqlite3_parser.cpp"
    break;

  case 89: // binary_expr: expr "->>" expr
#line 401 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " ->> " + yystack_[0].value.as < std::string > (); }
#line 1989 "sqlite3_parser.cpp"
    break;

  case 90: // binary_expr: expr "%" expr
#line 402 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " % " + yystack_[0].value.as < std::string > (); }
#line 1995 "sqlite3_parser.cpp"
    break;

  case 91: // binary_expr: expr "+" expr
#line 403 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " + " + yystack_[0].value.as < std::string > (); }
#line 2001 "sqlite3_parser.cpp"
    break;

  case 92: // binary_expr: expr "-" expr
#line 404 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " - " + yystack_[0].value.as < std::string > (); }
#line 2007 "sqlite3_parser.cpp"
    break;

  case 93: // binary_expr: expr "<<" expr
#line 405 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " << " + yystack_[0].value.as < std::string > (); }
#line 2013 "sqlite3_parser.cpp"
    break;

  case 94: // binary_expr: expr ">>" expr
#line 406 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " >> " + yystack_[0].value.as < std::string > (); }
#line 2019 "sqlite3_parser.cpp"
    break;

  case 95: // binary_expr: expr "&" expr
#line 407 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " & " + yystack_[0].value.as < std::string > (); }
#line 2025 "sqlite3_parser.cpp"
    break;

  case 96: // binary_expr: expr "|" expr
#line 408 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " | " + yystack_[0].value.as < std::string > (); }
#line 2031 "sqlite3_parser.cpp"
    break;

  case 97: // binary_expr: expr "<" expr
#line 409 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " < " + yystack_[0].value.as < std::string > (); }
#line 2037 "sqlite3_parser.cpp"
    break;

  case 98: // binary_expr: expr "<=" expr
#line 410 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " <= " + yystack_[0].value.as < std::string > (); }
#line 2043 "sqlite3_parser.cpp"
    break;

  case 99: // binary_expr: expr ">" expr
#line 411 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " > " + yystack_[0].value.as < std::string > (); }
#line 2049 "sqlite3_parser.cpp"
    break;

  case 100: // binary_expr: expr ">=" expr
#line 412 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " >= " + yystack_[0].value.as < std::string > (); }
#line 2055 "sqlite3_parser.cpp"
    break;

  case 101: // binary_expr: expr "=" expr
#line 413 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " = " + yystack_[0].value.as < std::string > (); }
#line 2061 "sqlite3_parser.cpp"
    break;

  case 102: // binary_expr: expr "==" expr
#line 414 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " == " + yystack_[0].value.as < std::string > (); }
#line 2067 "sqlite3_parser.cpp"
    break;

  case 103: // binary_expr: expr "!=" expr
#line 415 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " != " + yystack_[0].value.as < std::string > (); }
#line 2073 "sqlite3_parser.cpp"
    break;

  case 104: // binary_expr: expr "<>" expr
#line 416 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " <> " + yystack_[0].value.as < std::string > (); }
#line 2079 "sqlite3_parser.cpp"
    break;

  case 105: // binary_expr: expr "IS" expr
#line 417 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " IS " + yystack_[0].value.as < std::string > (); }
#line 2085 "sqlite3_parser.cpp"
    break;

  case 106: // binary_expr: expr "IS" "DISTINCT" "FROM" expr
#line 418 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IS DISTINCT FROM " + yystack_[0].value.as < std::string > (); }
#line 2091 "sqlite3_parser.cpp"
    break;

  case 107: // binary_expr: expr "IS" "NOT" "DISTINCT" "FROM" expr
#line 419 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " IS NOT DISTINCT FROM " + yystack_[0].value.as < std::string > (); }
#line 2097 "sqlite3_parser.cpp"
    break;

  case 108: // binary_expr: expr "AND" expr
#line 420 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 2103 "sqlite3_parser.cpp"
    break;

  case 109: // binary_expr: expr "OR" expr
#line 421 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " OR " + yystack_[0].value.as < std::string > (); }
#line 2109 "sqlite3_parser.cpp"
    break;

  case 110: // like_expr: expr "LIKE" expr
#line 425 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " LIKE " + yystack_[0].value.as < std::string > (); }
#line 2115 "sqlite3_parser.cpp"
    break;

  case 111: // like_expr: expr "GLOB" expr
#line 426 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " GLOB " + yystack_[0].value.as < std::string > (); }
#line 2121 "sqlite3_parser.cpp"
    break;

  case 112: // like_expr: expr "MATCH" expr
#line 427 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " MATCH " + yystack_[0].value.as < std::string > (); }
#line 2127 "sqlite3_parser.cpp"
    break;

  case 113: // like_expr: expr "REGEXP" expr
#line 428 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " REGEXP " + yystack_[0].value.as < std::string > (); }
#line 2133 "sqlite3_parser.cpp"
    break;

  case 114: // like_expr: expr "NOT" "LIKE" expr
#line 429 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT LIKE " + yystack_[0].value.as < std::string > (); }
#line 2139 "sqlite3_parser.cpp"
    break;

  case 115: // like_expr: expr "NOT" "GLOB" expr
#line 430 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT GLOB " + yystack_[0].value.as < std::string > (); }
#line 2145 "sqlite3_parser.cpp"
    break;

  case 116: // like_expr: expr "NOT" "MATCH" expr
#line 431 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT MATCH " + yystack_[0].value.as < std::string > (); }
#line 2151 "sqlite3_parser.cpp"
    break;

  case 117: // like_expr: expr "NOT" "REGEXP" expr
#line 432 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT REGEXP " + yystack_[0].value.as < std::string > (); }
#line 2157 "sqlite3_parser.cpp"
    break;

  case 118: // like_expr: expr "LIKE" expr "ESCAPE" expr
#line 433 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " LIKE " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2163 "sqlite3_parser.cpp"
    break;

  case 119: // like_expr: expr "GLOB" expr "ESCAPE" expr
#line 434 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " GLOB " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2169 "sqlite3_parser.cpp"
    break;

  case 120: // like_expr: expr "MATCH" expr "ESCAPE" expr
#line 435 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " MATCH " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2175 "sqlite3_parser.cpp"
    break;

  case 121: // like_expr: expr "REGEXP" expr "ESCAPE" expr
#line 436 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " REGEXP " + yystack_[2].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2181 "sqlite3_parser.cpp"
    break;

  case 122: // like_expr: expr "NOT" "LIKE" expr "ESCAPE" expr
#line 437 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT LIKE " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2187 "sqlite3_parser.cpp"
    break;

  case 123: // like_expr: expr "NOT" "GLOB" expr "ESCAPE" expr
#line 438 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT GLOB " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2193 "sqlite3_parser.cpp"
    break;

  case 124: // like_expr: expr "NOT" "MATCH" expr "ESCAPE" expr
#line 439 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT MATCH " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2199 "sqlite3_parser.cpp"
    break;

  case 125: // like_expr: expr "NOT" "REGEXP" expr "ESCAPE" expr
#line 440 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT REGEXP " + yystack_[3].value.as < std::string > () + " ESCAPE " + yystack_[0].value.as < std::string > (); }
#line 2205 "sqlite3_parser.cpp"
    break;

  case 126: // exprlist_expr: expr
#line 444 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2211 "sqlite3_parser.cpp"
    break;

  case 127: // exprlist_expr: exprlist_expr "," expr
#line 445 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + ", " + yystack_[0].value.as < std::string > (); }
#line 2217 "sqlite3_parser.cpp"
    break;

  case 128: // function_expr: id "(" exprlist_expr ")"
#line 449 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2223 "sqlite3_parser.cpp"
    break;

  case 129: // function_expr: id "(" "DISTINCT" exprlist_expr ")"
#line 450 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + "(DISTINCT " + yystack_[1].value.as < std::string > () + ")"; }
#line 2229 "sqlite3_parser.cpp"
    break;

  case 130: // function_expr: id "(" ")"
#line 451 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + "()"; }
#line 2235 "sqlite3_parser.cpp"
    break;

  case 131: // function_expr: id "(" "*" ")"
#line 452 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + "(*)"; }
#line 2241 "sqlite3_parser.cpp"
    break;

  case 132: // isnull_expr: expr "ISNULL"
#line 456 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " ISNULL"; }
#line 2247 "sqlite3_parser.cpp"
    break;

  case 133: // isnull_expr: expr "NOTNULL"
#line 457 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " NOTNULL"; }
#line 2253 "sqlite3_parser.cpp"
    break;

  case 134: // isnull_expr: expr "NOT" "NULL"
#line 458 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " NOT NULL"; }
#line 2259 "sqlite3_parser.cpp"
    break;

  case 135: // between_expr: expr "BETWEEN" expr "AND BETWEEN" expr
#line 462 "sqlite3_parser.yy"
                                                                { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " BETWEEN " + yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 2265 "sqlite3_parser.cpp"
    break;

  case 136: // between_expr: expr "NOT" "BETWEEN" expr "AND BETWEEN" expr
#line 463 "sqlite3_parser.yy"
                                                                { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT BETWEEN " + yystack_[2].value.as < std::string > () + " AND " + yystack_[0].value.as < std::string > (); }
#line 2271 "sqlite3_parser.cpp"
    break;

  case 137: // in_expr: expr "IN" "(" ")"
#line 467 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " IN ()"; }
#line 2277 "sqlite3_parser.cpp"
    break;

  case 138: // in_expr: expr "IN" "(" select_stmt ")"
#line 468 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2283 "sqlite3_parser.cpp"
    break;

  case 139: // in_expr: expr "IN" "(" exprlist_expr ")"
#line 469 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2289 "sqlite3_parser.cpp"
    break;

  case 140: // in_expr: expr "IN" id "." tableid
#line 470 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2295 "sqlite3_parser.cpp"
    break;

  case 141: // in_expr: expr "IN" tableid
#line 471 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2301 "sqlite3_parser.cpp"
    break;

  case 142: // in_expr: expr "IN" id "." id "(" ")"
#line 472 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[6].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + yystack_[2].value.as < std::string > () + "()"; }
#line 2307 "sqlite3_parser.cpp"
    break;

  case 143: // in_expr: expr "IN" id "." id "(" exprlist_expr ")"
#line 473 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[7].value.as < std::string > () + " IN " + sqlb::escapeIdentifier(yystack_[5].value.as < std::string > ()) + "." + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2313 "sqlite3_parser.cpp"
    break;

  case 144: // in_expr: expr "IN" id "(" exprlist_expr ")"
#line 474 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " IN " + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2319 "sqlite3_parser.cpp"
    break;

  case 145: // in_expr: expr "NOT" "IN" "(" ")"
#line 475 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " NOT IN ()"; }
#line 2325 "sqlite3_parser.cpp"
    break;

  case 146: // in_expr: expr "NOT" "IN" "(" select_stmt ")"
#line 476 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2331 "sqlite3_parser.cpp"
    break;

  case 147: // in_expr: expr "NOT" "IN" "(" exprlist_expr ")"
#line 477 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN (" + yystack_[1].value.as < std::string > () + ")"; }
#line 2337 "sqlite3_parser.cpp"
    break;

  case 148: // in_expr: expr "NOT" "IN" id "." tableid
#line 478 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2343 "sqlite3_parser.cpp"
    break;

  case 149: // in_expr: expr "NOT" "IN" tableid
#line 479 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2349 "sqlite3_parser.cpp"
    break;

  case 150: // in_expr: expr "NOT" "IN" id "." id "(" ")"
#line 480 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[7].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + yystack_[2].value.as < std::string > () + "()"; }
#line 2355 "sqlite3_parser.cpp"
    break;

  case 151: // in_expr: expr "NOT" "IN" id "." id "(" exprlist_expr ")"
#line 481 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[8].value.as < std::string > () + " NOT IN " + sqlb::escapeIdentifier(yystack_[5].value.as < std::string > ()) + "." + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2361 "sqlite3_parser.cpp"
    break;

  case 152: // in_expr: expr "NOT" "IN" id "(" exprlist_expr ")"
#line 482 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[6].value.as < std::string > () + " NOT IN " + yystack_[3].value.as < std::string > () + "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2367 "sqlite3_parser.cpp"
    break;

  case 153: // whenthenlist_expr: "WHEN" expr "THEN" expr
#line 486 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "WHEN " + yystack_[2].value.as < std::string > () + " THEN " + yystack_[0].value.as < std::string > (); }
#line 2373 "sqlite3_parser.cpp"
    break;

  case 154: // whenthenlist_expr: whenthenlist_expr "WHEN" expr "THEN" expr
#line 487 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " WHEN" + yystack_[2].value.as < std::string > () + " THEN " + yystack_[0].value.as < std::string > (); }
#line 2379 "sqlite3_parser.cpp"
    break;

  case 155: // case_expr: "CASE" expr whenthenlist_expr "ELSE" expr "END"
#line 491 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "CASE " + yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " ELSE " + yystack_[1].value.as < std::string > () + " END"; }
#line 2385 "sqlite3_parser.cpp"
    break;

  case 156: // case_expr: "CASE" expr whenthenlist_expr "END"
#line 492 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "CASE " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " END"; }
#line 2391 "sqlite3_parser.cpp"
    break;

  case 157: // case_expr: "CASE" whenthenlist_expr "ELSE" expr "END"
#line 493 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "CASE " + yystack_[3].value.as < std::string > () + " ELSE " + yystack_[1].value.as < std::string > () + " END"; }
#line 2397 "sqlite3_parser.cpp"
    break;

  case 158: // case_expr: "CASE" whenthenlist_expr "END"
#line 494 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "CASE " + yystack_[1].value.as < std::string > () + " END"; }
#line 2403 "sqlite3_parser.cpp"
    break;

  case 159: // raise_expr: "RAISE" "(" "IGNORE" ")"
#line 498 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "RAISE(IGNORE)"; }
#line 2409 "sqlite3_parser.cpp"
    break;

  case 160: // raise_expr: "RAISE" "(" "ROLLBACK" "," "string literal" ")"
#line 499 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "RAISE(ROLLBACK, " + yystack_[1].value.as < std::string > () + ")"; }
#line 2415 "sqlite3_parser.cpp"
    break;

  case 161: // raise_expr: "RAISE" "(" "ABORT" "," "string literal" ")"
#line 500 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "RAISE(ABORT, " + yystack_[1].value.as < std::string > () + ")"; }
#line 2421 "sqlite3_parser.cpp"
    break;

  case 162: // raise_expr: "RAISE" "(" "FAIL" "," "string literal" ")"
#line 501 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "RAISE(FAIL, " + yystack_[1].value.as < std::string > () + ")"; }
#line 2427 "sqlite3_parser.cpp"
    break;

  case 163: // expr: literalvalue
#line 505 "sqlite3_parser.yy"
        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2433 "sqlite3_parser.cpp"
    break;

  case 164: // expr: allowed_keywords_as_identifier
#line 506 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2439 "sqlite3_parser.cpp"
    break;

  case 165: // expr: "bind parameter"
#line 507 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2445 "sqlite3_parser.cpp"
    break;

  case 166: // expr: id "." id "." id
#line 508 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[4].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2451 "sqlite3_parser.cpp"
    break;

  case 167: // expr: id "." id
#line 509 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[2].value.as < std::string > ()) + "." + sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2457 "sqlite3_parser.cpp"
    break;

  case 168: // expr: id
#line 510 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = sqlb::escapeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 2463 "sqlite3_parser.cpp"
    break;

  case 169: // expr: unary_expr
#line 511 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2469 "sqlite3_parser.cpp"
    break;

  case 170: // expr: binary_expr
#line 512 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2475 "sqlite3_parser.cpp"
    break;

  case 171: // expr: function_expr
#line 513 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2481 "sqlite3_parser.cpp"
    break;

  case 172: // expr: "(" exprlist_expr ")"
#line 514 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "(" + yystack_[1].value.as < std::string > () + ")"; }
#line 2487 "sqlite3_parser.cpp"
    break;

  case 173: // expr: "CAST" "(" expr "AS" type_name ")"
#line 515 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "CAST(" + yystack_[3].value.as < std::string > () + " AS " + yystack_[1].value.as < std::string > () + ")"; }
#line 2493 "sqlite3_parser.cpp"
    break;

  case 174: // expr: expr "COLLATE" id
#line 516 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " COLLATE " + yystack_[0].value.as < std::string > (); }
#line 2499 "sqlite3_parser.cpp"
    break;

  case 175: // expr: like_expr
#line 517 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2505 "sqlite3_parser.cpp"
    break;

  case 176: // expr: isnull_expr
#line 518 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2511 "sqlite3_parser.cpp"
    break;

  case 177: // expr: between_expr
#line 519 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2517 "sqlite3_parser.cpp"
    break;

  case 178: // expr: in_expr
#line 520 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2523 "sqlite3_parser.cpp"
    break;

  case 179: // expr: case_expr
#line 521 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2529 "sqlite3_parser.cpp"
    break;

  case 180: // expr: raise_expr
#line 522 "sqlite3_parser.yy"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2535 "sqlite3_parser.cpp"
    break;

  case 181: // select_stmt: "SELECT"
#line 531 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "SELECT"; }
#line 2541 "sqlite3_parser.cpp"
    break;

  case 182: // optional_if_not_exists: %empty
#line 539 "sqlite3_parser.yy"
                                                { yylhs.value.as < bool > () = false; }
#line 2547 "sqlite3_parser.cpp"
    break;

  case 183: // optional_if_not_exists: "IF" "NOT" "EXISTS"
#line 540 "sqlite3_parser.yy"
                                                { yylhs.value.as < bool > () = true; }
#line 2553 "sqlite3_parser.cpp"
    break;

  case 184: // optional_sort_order: %empty
#line 544 "sqlite3_parser.yy"
                                                { }
#line 2559 "sqlite3_parser.cpp"
    break;

  case 185: // optional_sort_order: "ASC"
#line 545 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "ASC"; }
#line 2565 "sqlite3_parser.cpp"
    break;

  case 186: // optional_sort_order: "DESC"
#line 546 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = "DESC"; }
#line 2571 "sqlite3_parser.cpp"
    break;

  case 187: // optional_unique: %empty
#line 554 "sqlite3_parser.yy"
                                                { yylhs.value.as < bool > () = false; }
#line 2577 "sqlite3_parser.cpp"
    break;

  case 188: // optional_unique: "UNIQUE"
#line 555 "sqlite3_parser.yy"
                                                { yylhs.value.as < bool > () = true; }
#line 2583 "sqlite3_parser.cpp"
    break;

  case 189: // optional_where: %empty
#line 559 "sqlite3_parser.yy"
                                                { }
#line 2589 "sqlite3_parser.cpp"
    break;

  case 190: // optional_where: "WHERE" expr
#line 560 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2595 "sqlite3_parser.cpp"
    break;

  case 191: // tableid_with_uninteresting_schema: id "." tableid
#line 564 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2601 "sqlite3_parser.cpp"
    break;

  case 192: // tableid_with_uninteresting_schema: "TEMP" "." tableid
#line 565 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2607 "sqlite3_parser.cpp"
    break;

  case 193: // tableid_with_uninteresting_schema: tableid
#line 566 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2613 "sqlite3_parser.cpp"
    break;

  case 194: // indexed_column: expr optional_sort_order
#line 570 "sqlite3_parser.yy"
                                                {
							// If the expression is only one column name and nothing else, treat it as a column name; otherwise as an expression.
							char quote = getIdentifierQuoteChar();
							if((quote == '[' && std::count(yystack_[1].value.as < std::string > ().begin(), yystack_[1].value.as < std::string > ().end(), quote) == 1 && yystack_[1].value.as < std::string > ().front() == '[' && yystack_[1].value.as < std::string > ().back() == ']') ||
								(quote != '[' && std::count(yystack_[1].value.as < std::string > ().begin(), yystack_[1].value.as < std::string > ().end(), quote) == 2 && yystack_[1].value.as < std::string > ().front() == quote && yystack_[1].value.as < std::string > ().back() == quote))
							{
								yylhs.value.as < sqlb::IndexedColumn > () = sqlb::IndexedColumn(unquote_text(yystack_[1].value.as < std::string > (), quote), false, yystack_[0].value.as < std::string > ());
							} else if(std::count(yystack_[1].value.as < std::string > ().begin(), yystack_[1].value.as < std::string > ().end(), '\'') == 2 && yystack_[1].value.as < std::string > ().front() == '\'' && yystack_[1].value.as < std::string > ().back() == '\'') {
								// Also remove single quotes when this actually is a string literal but looks like a columnid
								yylhs.value.as < sqlb::IndexedColumn > () = sqlb::IndexedColumn(unquote_text(yystack_[1].value.as < std::string > (), '\''), false, yystack_[0].value.as < std::string > ());
							} else {
								yylhs.value.as < sqlb::IndexedColumn > () = sqlb::IndexedColumn(yystack_[1].value.as < std::string > (), true, yystack_[0].value.as < std::string > ());
							}
						}
#line 2632 "sqlite3_parser.cpp"
    break;

  case 195: // indexed_column_list: indexed_column
#line 587 "sqlite3_parser.yy"
                                                        { yylhs.value.as < sqlb::IndexedColumnVector > () = sqlb::IndexedColumnVector(1, yystack_[0].value.as < sqlb::IndexedColumn > ()); }
#line 2638 "sqlite3_parser.cpp"
    break;

  case 196: // indexed_column_list: indexed_column_list "," indexed_column
#line 588 "sqlite3_parser.yy"
                                                        { yylhs.value.as < sqlb::IndexedColumnVector > () = yystack_[2].value.as < sqlb::IndexedColumnVector > (); yylhs.value.as < sqlb::IndexedColumnVector > ().push_back(yystack_[0].value.as < sqlb::IndexedColumn > ()); }
#line 2644 "sqlite3_parser.cpp"
    break;

  case 197: // createindex_stmt: "CREATE" optional_unique "INDEX" optional_if_not_exists tableid_with_uninteresting_schema "ON" tableid "(" indexed_column_list ")" optional_where
#line 592 "sqlite3_parser.yy"
                                                                                                                                                                {
													yylhs.value.as < sqlb::IndexPtr > () = std::make_shared<sqlb::Index>(yystack_[6].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setTable(yystack_[4].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setUnique(yystack_[9].value.as < bool > ());
													yylhs.value.as < sqlb::IndexPtr > ()->setWhereExpr(yystack_[0].value.as < std::string > ());
													yylhs.value.as < sqlb::IndexPtr > ()->fields = yystack_[2].value.as < sqlb::IndexedColumnVector > ();
													yylhs.value.as < sqlb::IndexPtr > ()->setFullyParsed(true);
												}
#line 2657 "sqlite3_parser.cpp"
    break;

  case 198: // optional_exprlist_with_paren: %empty
#line 607 "sqlite3_parser.yy"
                                                { }
#line 2663 "sqlite3_parser.cpp"
    break;

  case 199: // optional_exprlist_with_paren: "(" ")"
#line 608 "sqlite3_parser.yy"
                                                { }
#line 2669 "sqlite3_parser.cpp"
    break;

  case 200: // optional_exprlist_with_paren: "(" exprlist_expr ")"
#line 609 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > (); }
#line 2675 "sqlite3_parser.cpp"
    break;

  case 201: // createvirtualtable_stmt: "CREATE" "VIRTUAL" "TABLE" optional_if_not_exists tableid_with_uninteresting_schema "USING" id optional_exprlist_with_paren
#line 613 "sqlite3_parser.yy"
                                                                                                                                {
													yylhs.value.as < sqlb::TablePtr > () = std::make_shared<sqlb::Table>(yystack_[3].value.as < std::string > ());
													yylhs.value.as < sqlb::TablePtr > ()->setVirtualUsing(yystack_[1].value.as < std::string > ());
													yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(false);
												}
#line 2685 "sqlite3_parser.cpp"
    break;

  case 202: // optional_temporary: %empty
#line 625 "sqlite3_parser.yy"
                                                        { yylhs.value.as < bool > () = false; }
#line 2691 "sqlite3_parser.cpp"
    break;

  case 203: // optional_temporary: "TEMP"
#line 626 "sqlite3_parser.yy"
                                                        { yylhs.value.as < bool > () = true; }
#line 2697 "sqlite3_parser.cpp"
    break;

  case 204: // optional_temporary: "TEMPORARY"
#line 627 "sqlite3_parser.yy"
                                                        { yylhs.value.as < bool > () = true; }
#line 2703 "sqlite3_parser.cpp"
    break;

  case 205: // tableoption: "WITHOUT" "ROWID"
#line 631 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::bitset<sqlb::Table::NumOptions> > ().set(sqlb::Table::WithoutRowid, true); }
#line 2709 "sqlite3_parser.cpp"
    break;

  case 206: // tableoption: "STRICT"
#line 632 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::bitset<sqlb::Table::NumOptions> > ().set(sqlb::Table::Strict, true); }
#line 2715 "sqlite3_parser.cpp"
    break;

  case 207: // tableoptions_list: tableoption
#line 636 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::bitset<sqlb::Table::NumOptions> > () = yystack_[0].value.as < std::bitset<sqlb::Table::NumOptions> > (); }
#line 2721 "sqlite3_parser.cpp"
    break;

  case 208: // tableoptions_list: tableoptions_list "," tableoption
#line 637 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::bitset<sqlb::Table::NumOptions> > () = yystack_[2].value.as < std::bitset<sqlb::Table::NumOptions> > () | yystack_[0].value.as < std::bitset<sqlb::Table::NumOptions> > (); }
#line 2727 "sqlite3_parser.cpp"
    break;

  case 209: // tableoptions_list: tableoptions_list tableoption
#line 638 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::bitset<sqlb::Table::NumOptions> > () = yystack_[1].value.as < std::bitset<sqlb::Table::NumOptions> > () | yystack_[0].value.as < std::bitset<sqlb::Table::NumOptions> > (); }
#line 2733 "sqlite3_parser.cpp"
    break;

  case 210: // optional_tableoptions_list: %empty
#line 642 "sqlite3_parser.yy"
                                                        { }
#line 2739 "sqlite3_parser.cpp"
    break;

  case 211: // optional_tableoptions_list: tableoptions_list
#line 643 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::bitset<sqlb::Table::NumOptions> > () = yystack_[0].value.as < std::bitset<sqlb::Table::NumOptions> > (); }
#line 2745 "sqlite3_parser.cpp"
    break;

  case 212: // optional_conflictclause: %empty
#line 647 "sqlite3_parser.yy"
                                                        { }
#line 2751 "sqlite3_parser.cpp"
    break;

  case 213: // optional_conflictclause: "ON" "CONFLICT" "ROLLBACK"
#line 648 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2757 "sqlite3_parser.cpp"
    break;

  case 214: // optional_conflictclause: "ON" "CONFLICT" "ABORT"
#line 649 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2763 "sqlite3_parser.cpp"
    break;

  case 215: // optional_conflictclause: "ON" "CONFLICT" "FAIL"
#line 650 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2769 "sqlite3_parser.cpp"
    break;

  case 216: // optional_conflictclause: "ON" "CONFLICT" "IGNORE"
#line 651 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2775 "sqlite3_parser.cpp"
    break;

  case 217: // optional_conflictclause: "ON" "CONFLICT" "REPLACE"
#line 652 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2781 "sqlite3_parser.cpp"
    break;

  case 218: // optional_typename: %empty
#line 656 "sqlite3_parser.yy"
                                                { }
#line 2787 "sqlite3_parser.cpp"
    break;

  case 219: // optional_typename: type_name
#line 657 "sqlite3_parser.yy"
                                                { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 2793 "sqlite3_parser.cpp"
    break;

  case 220: // optional_storage_identifier: %empty
#line 661 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "VIRTUAL"; }
#line 2799 "sqlite3_parser.cpp"
    break;

  case 221: // optional_storage_identifier: "STORED"
#line 662 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "STORED"; }
#line 2805 "sqlite3_parser.cpp"
    break;

  case 222: // optional_storage_identifier: "VIRTUAL"
#line 663 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = "VIRTUAL"; }
#line 2811 "sqlite3_parser.cpp"
    break;

  case 223: // optional_always_generated: %empty
#line 667 "sqlite3_parser.yy"
                                                        { yylhs.value.as < bool > () = false; }
#line 2817 "sqlite3_parser.cpp"
    break;

  case 224: // optional_always_generated: "GENERATED" "ALWAYS"
#line 668 "sqlite3_parser.yy"
                                                        { yylhs.value.as < bool > () = true; }
#line 2823 "sqlite3_parser.cpp"
    break;

  case 225: // columnconstraint: optional_constraintname "PRIMARY" "KEY" optional_sort_order optional_conflictclause
#line 672 "sqlite3_parser.yy"
                                                                                        {
												auto pk = std::make_shared<sqlb::PrimaryKeyConstraint>();
												pk->setName(yystack_[4].value.as < std::string > ());
												pk->setConflictAction(yystack_[0].value.as < std::string > ());
												yylhs.value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().first = pk;
											}
#line 2834 "sqlite3_parser.cpp"
    break;

  case 226: // columnconstraint: optional_constraintname "PRIMARY" "KEY" optional_sort_order optional_conflictclause "AUTOINCREMENT"
#line 678 "sqlite3_parser.yy"
                                                                                                        {
												auto pk = std::make_shared<sqlb::PrimaryKeyConstraint>();
												pk->setName(yystack_[5].value.as < std::string > ());
												pk->setConflictAction(yystack_[1].value.as < std::string > ());
												pk->setAutoIncrement(true);
												yylhs.value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().first = pk;
											}
#line 2846 "sqlite3_parser.cpp"
    break;

  case 227: // columnconstraint: optional_constraintname "NOT" "NULL" optional_conflictclause
#line 685 "sqlite3_parser.yy"
                                                                                        {
												auto nn = std::make_shared<sqlb::NotNullConstraint>();
												nn->setName(yystack_[3].value.as < std::string > ());
												nn->setConflictAction(yystack_[0].value.as < std::string > ());
												drv.last_table_column->setNotNull(nn);
											}
#line 2857 "sqlite3_parser.cpp"
    break;

  case 228: // columnconstraint: optional_constraintname "NULL"
#line 691 "sqlite3_parser.yy"
                                                                                        {
											}
#line 2864 "sqlite3_parser.cpp"
    break;

  case 229: // columnconstraint: optional_constraintname "UNIQUE" optional_conflictclause
#line 693 "sqlite3_parser.yy"
                                                                                        {
												auto u = std::make_shared<sqlb::UniqueConstraint>();
												u->setName(yystack_[2].value.as < std::string > ());
												u->setConflictAction(yystack_[0].value.as < std::string > ());
												drv.last_table_column->setUnique(u);
											}
#line 2875 "sqlite3_parser.cpp"
    break;

  case 230: // columnconstraint: optional_constraintname "CHECK" "(" expr ")"
#line 699 "sqlite3_parser.yy"
                                                                                        {
												auto c = std::make_shared<sqlb::CheckConstraint>(yystack_[1].value.as < std::string > ());
												c->setName(yystack_[4].value.as < std::string > ());
												drv.last_table_column->setCheck(c);
											}
#line 2885 "sqlite3_parser.cpp"
    break;

  case 231: // columnconstraint: optional_constraintname "DEFAULT" signednumber
#line 704 "sqlite3_parser.yy"
                                                                                        {
												auto d = std::make_shared<sqlb::DefaultConstraint>(yystack_[0].value.as < std::string > ());
												d->setName(yystack_[2].value.as < std::string > ());
												drv.last_table_column->setDefaultValue(d);
											}
#line 2895 "sqlite3_parser.cpp"
    break;

  case 232: // columnconstraint: optional_constraintname "DEFAULT" literalvalue
#line 709 "sqlite3_parser.yy"
                                                                                        {
												auto d = std::make_shared<sqlb::DefaultConstraint>(yystack_[0].value.as < std::string > ());
												d->setName(yystack_[2].value.as < std::string > ());
												drv.last_table_column->setDefaultValue(d);
											}
#line 2905 "sqlite3_parser.cpp"
    break;

  case 233: // columnconstraint: optional_constraintname "DEFAULT" id
#line 714 "sqlite3_parser.yy"
                                                                                        {
												auto d = std::make_shared<sqlb::DefaultConstraint>(yystack_[0].value.as < std::string > ());
												d->setName(yystack_[2].value.as < std::string > ());
												drv.last_table_column->setDefaultValue(d);
											}
#line 2915 "sqlite3_parser.cpp"
    break;

  case 234: // columnconstraint: optional_constraintname "DEFAULT" allowed_keywords_as_identifier
#line 719 "sqlite3_parser.yy"
                                                                                        {	// We must allow the same keywords as unquoted default values as in the columnid context.
												// But we do not use columnid here in order to avoid reduce/reduce conflicts.
												auto d = std::make_shared<sqlb::DefaultConstraint>(yystack_[0].value.as < std::string > ());
												d->setName(yystack_[2].value.as < std::string > ());
												drv.last_table_column->setDefaultValue(d);
											}
#line 2926 "sqlite3_parser.cpp"
    break;

  case 235: // columnconstraint: optional_constraintname "DEFAULT" "IF"
#line 725 "sqlite3_parser.yy"
                                                                                        {	// Same as above.
												auto d = std::make_shared<sqlb::DefaultConstraint>(yystack_[0].value.as < std::string > ());
												d->setName(yystack_[2].value.as < std::string > ());
												drv.last_table_column->setDefaultValue(d);
											}
#line 2936 "sqlite3_parser.cpp"
    break;

  case 236: // columnconstraint: optional_constraintname "DEFAULT" "(" expr ")"
#line 730 "sqlite3_parser.yy"
                                                                                        {
												auto d = std::make_shared<sqlb::DefaultConstraint>("(" + yystack_[1].value.as < std::string > () + ")");
												d->setName(yystack_[4].value.as < std::string > ());
												drv.last_table_column->setDefaultValue(d);
											}
#line 2946 "sqlite3_parser.cpp"
    break;

  case 237: // columnconstraint: optional_constraintname "COLLATE" id
#line 735 "sqlite3_parser.yy"
                                                                                        {
												auto c = std::make_shared<sqlb::CollateConstraint>(yystack_[0].value.as < std::string > ());
												c->setName(yystack_[2].value.as < std::string > ());
												drv.last_table_column->setCollation(c);
											}
#line 2956 "sqlite3_parser.cpp"
    break;

  case 238: // columnconstraint: optional_constraintname "REFERENCES" tableid optional_columnid_with_paren_list optional_fk_clause
#line 740 "sqlite3_parser.yy"
                                                                                                                {	// TODO Solve shift/reduce conflict. It is not super important though as shifting seems to be right here.
												auto fk = std::make_shared<sqlb::ForeignKeyClause>();
												fk->setName(yystack_[4].value.as < std::string > ());
												fk->setTable(yystack_[2].value.as < std::string > ());
												fk->setColumns(yystack_[1].value.as < sqlb::StringVector > ());
												fk->setConstraint(yystack_[0].value.as < std::string > ());
												yylhs.value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().second = fk;
											}
#line 2969 "sqlite3_parser.cpp"
    break;

  case 239: // columnconstraint: optional_constraintname optional_always_generated "AS" "(" expr ")" optional_storage_identifier
#line 748 "sqlite3_parser.yy"
                                                                                                        {		// TODO Solve shift/reduce conflict.
												auto g = std::make_shared<sqlb::GeneratedColumnConstraint>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ());
												g->setName(yystack_[6].value.as < std::string > ());

												drv.last_table_column->setGenerated(g);

												// This is a hack which removes any "GENERATED ALWAYS" from the end of the type name.
												// As of now these are shifted to the type instead of reducing the type when seeing the GENERATED identifier.
												// TODO Remove this once the grammar is conflict free
												const std::string generated_always = "GENERATED ALWAYS";
												if(drv.last_table_column->type().size() >= generated_always.size() && drv.last_table_column->type().compare(drv.last_table_column->type().size() - generated_always.size(), generated_always.size(), generated_always) == 0)
												{
													std::string type = drv.last_table_column->type().substr(0, drv.last_table_column->type().size()-generated_always.size());
													if(type.back() == ' ')
														type.pop_back();
													drv.last_table_column->setType(type);
												}
											}
#line 2992 "sqlite3_parser.cpp"
    break;

  case 240: // columnconstraint_list: %empty
#line 769 "sqlite3_parser.yy"
                                                        { }
#line 2998 "sqlite3_parser.cpp"
    break;

  case 241: // columnconstraint_list: columnconstraint_list columnconstraint
#line 770 "sqlite3_parser.yy"
                                                        {
								yylhs.value.as < TableConstraints > () = yystack_[1].value.as < TableConstraints > ();

								// Primary key and foreign key constraints are converted to table constraints
								// because we cannot store them as column constraints at the moment.
								if(yystack_[0].value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().first)
									yylhs.value.as < TableConstraints > ().index.insert(std::make_pair(sqlb::IndexedColumnVector{sqlb::IndexedColumn(drv.last_table_column->name(), false)}, yystack_[0].value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().first));
								if(yystack_[0].value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().second)
									yylhs.value.as < TableConstraints > ().fk.insert(std::make_pair(sqlb::StringVector{drv.last_table_column->name()}, yystack_[0].value.as < std::pair<std::shared_ptr<sqlb::PrimaryKeyConstraint>, std::shared_ptr<sqlb::ForeignKeyClause>> > ().second));
							}
#line 3013 "sqlite3_parser.cpp"
    break;

  case 242: // columndef: columnid optional_typename
#line 783 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::shared_ptr<sqlb::Field> > () = std::make_shared<sqlb::Field>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ()); drv.last_table_column = yylhs.value.as < std::shared_ptr<sqlb::Field> > (); }
#line 3019 "sqlite3_parser.cpp"
    break;

  case 243: // columndef_list: columndef columnconstraint_list
#line 787 "sqlite3_parser.yy"
                                                                { yylhs.value.as < ColumnList > ().first.push_back(yystack_[1].value.as < std::shared_ptr<sqlb::Field> > ()); yylhs.value.as < ColumnList > ().second = yystack_[0].value.as < TableConstraints > (); }
#line 3025 "sqlite3_parser.cpp"
    break;

  case 244: // columndef_list: columndef_list "," columndef columnconstraint_list
#line 788 "sqlite3_parser.yy"
                                                                { yylhs.value.as < ColumnList > () = yystack_[3].value.as < ColumnList > (); yylhs.value.as < ColumnList > ().first.push_back(yystack_[1].value.as < std::shared_ptr<sqlb::Field> > ()); yylhs.value.as < ColumnList > ().second.index.insert(yystack_[0].value.as < TableConstraints > ().index.begin(), yystack_[0].value.as < TableConstraints > ().index.end()); yylhs.value.as < ColumnList > ().second.fk.insert(yystack_[0].value.as < TableConstraints > ().fk.begin(), yystack_[0].value.as < TableConstraints > ().fk.end()); }
#line 3031 "sqlite3_parser.cpp"
    break;

  case 245: // optional_constraintname: %empty
#line 792 "sqlite3_parser.yy"
                                                        { }
#line 3037 "sqlite3_parser.cpp"
    break;

  case 246: // optional_constraintname: "CONSTRAINT" id
#line 793 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3043 "sqlite3_parser.cpp"
    break;

  case 247: // optional_constraintname: "CONSTRAINT" "string literal"
#line 794 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3049 "sqlite3_parser.cpp"
    break;

  case 248: // columnid_list: columnid
#line 798 "sqlite3_parser.yy"
                                                        { yylhs.value.as < sqlb::StringVector > () = sqlb::StringVector(1, yystack_[0].value.as < std::string > ()); }
#line 3055 "sqlite3_parser.cpp"
    break;

  case 249: // columnid_list: columnid_list "," columnid
#line 799 "sqlite3_parser.yy"
                                                        { yylhs.value.as < sqlb::StringVector > () = yystack_[2].value.as < sqlb::StringVector > (); yylhs.value.as < sqlb::StringVector > ().push_back(yystack_[0].value.as < std::string > ()); }
#line 3061 "sqlite3_parser.cpp"
    break;

  case 250: // optional_columnid_with_paren_list: %empty
#line 803 "sqlite3_parser.yy"
                                                        { }
#line 3067 "sqlite3_parser.cpp"
    break;

  case 251: // optional_columnid_with_paren_list: "(" columnid_list ")"
#line 804 "sqlite3_parser.yy"
                                                        { yylhs.value.as < sqlb::StringVector > () = yystack_[1].value.as < sqlb::StringVector > (); }
#line 3073 "sqlite3_parser.cpp"
    break;

  case 252: // fk_clause_part: "ON" "DELETE" "SET" "NULL"
#line 808 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3079 "sqlite3_parser.cpp"
    break;

  case 253: // fk_clause_part: "ON" "DELETE" "SET" "DEFAULT"
#line 809 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3085 "sqlite3_parser.cpp"
    break;

  case 254: // fk_clause_part: "ON" "DELETE" "CASCADE"
#line 810 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3091 "sqlite3_parser.cpp"
    break;

  case 255: // fk_clause_part: "ON" "DELETE" "RESTRICT"
#line 811 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3097 "sqlite3_parser.cpp"
    break;

  case 256: // fk_clause_part: "ON" "DELETE" "NO" "ACTION"
#line 812 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3103 "sqlite3_parser.cpp"
    break;

  case 257: // fk_clause_part: "ON" "UPDATE" "SET" "NULL"
#line 813 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3109 "sqlite3_parser.cpp"
    break;

  case 258: // fk_clause_part: "ON" "UPDATE" "SET" "DEFAULT"
#line 814 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3115 "sqlite3_parser.cpp"
    break;

  case 259: // fk_clause_part: "ON" "UPDATE" "CASCADE"
#line 815 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3121 "sqlite3_parser.cpp"
    break;

  case 260: // fk_clause_part: "ON" "UPDATE" "RESTRICT"
#line 816 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3127 "sqlite3_parser.cpp"
    break;

  case 261: // fk_clause_part: "ON" "UPDATE" "NO" "ACTION"
#line 817 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3133 "sqlite3_parser.cpp"
    break;

  case 262: // fk_clause_part: "ON" "INSERT" "SET" "NULL"
#line 818 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3139 "sqlite3_parser.cpp"
    break;

  case 263: // fk_clause_part: "ON" "INSERT" "SET" "DEFAULT"
#line 819 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3145 "sqlite3_parser.cpp"
    break;

  case 264: // fk_clause_part: "ON" "INSERT" "CASCADE"
#line 820 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3151 "sqlite3_parser.cpp"
    break;

  case 265: // fk_clause_part: "ON" "INSERT" "RESTRICT"
#line 821 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3157 "sqlite3_parser.cpp"
    break;

  case 266: // fk_clause_part: "ON" "INSERT" "NO" "ACTION"
#line 822 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3163 "sqlite3_parser.cpp"
    break;

  case 267: // fk_clause_part: "MATCH" id
#line 823 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3169 "sqlite3_parser.cpp"
    break;

  case 268: // fk_clause_part_list: fk_clause_part
#line 827 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3175 "sqlite3_parser.cpp"
    break;

  case 269: // fk_clause_part_list: fk_clause_part_list fk_clause_part
#line 828 "sqlite3_parser.yy"
                                                        { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3181 "sqlite3_parser.cpp"
    break;

  case 270: // optional_fk_clause: %empty
#line 832 "sqlite3_parser.yy"
                                                                        { }
#line 3187 "sqlite3_parser.cpp"
    break;

  case 271: // optional_fk_clause: fk_clause_part_list
#line 833 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3193 "sqlite3_parser.cpp"
    break;

  case 272: // optional_fk_clause: fk_clause_part_list "DEFERRABLE" "INITIALLY" "DEFERRED"
#line 834 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3199 "sqlite3_parser.cpp"
    break;

  case 273: // optional_fk_clause: fk_clause_part_list "DEFERRABLE" "INITIALLY" "IMMEDIATE"
#line 835 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3205 "sqlite3_parser.cpp"
    break;

  case 274: // optional_fk_clause: fk_clause_part_list "DEFERRABLE"
#line 836 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3211 "sqlite3_parser.cpp"
    break;

  case 275: // optional_fk_clause: fk_clause_part_list "NOT" "DEFERRABLE" "INITIALLY" "DEFERRED"
#line 837 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3217 "sqlite3_parser.cpp"
    break;

  case 276: // optional_fk_clause: fk_clause_part_list "NOT" "DEFERRABLE" "INITIALLY" "IMMEDIATE"
#line 838 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[4].value.as < std::string > () + " " + yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3223 "sqlite3_parser.cpp"
    break;

  case 277: // optional_fk_clause: fk_clause_part_list "NOT" "DEFERRABLE"
#line 839 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3229 "sqlite3_parser.cpp"
    break;

  case 278: // optional_fk_clause: "DEFERRABLE" "INITIALLY" "DEFERRED"
#line 840 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3235 "sqlite3_parser.cpp"
    break;

  case 279: // optional_fk_clause: "DEFERRABLE" "INITIALLY" "IMMEDIATE"
#line 841 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3241 "sqlite3_parser.cpp"
    break;

  case 280: // optional_fk_clause: "DEFERRABLE"
#line 842 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 3247 "sqlite3_parser.cpp"
    break;

  case 281: // optional_fk_clause: "NOT" "DEFERRABLE" "INITIALLY" "DEFERRED"
#line 843 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3253 "sqlite3_parser.cpp"
    break;

  case 282: // optional_fk_clause: "NOT" "DEFERRABLE" "INITIALLY" "IMMEDIATE"
#line 844 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[3].value.as < std::string > () + " " + yystack_[2].value.as < std::string > () + " " + yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3259 "sqlite3_parser.cpp"
    break;

  case 283: // optional_fk_clause: "NOT" "DEFERRABLE"
#line 845 "sqlite3_parser.yy"
                                                                        { yylhs.value.as < std::string > () = yystack_[1].value.as < std::string > () + " " + yystack_[0].value.as < std::string > (); }
#line 3265 "sqlite3_parser.cpp"
    break;

  case 284: // tableconstraint: optional_constraintname "PRIMARY" "KEY" "(" indexed_column_list ")" optional_conflictclause
#line 849 "sqlite3_parser.yy"
                                                                                                        {
														auto pk = std::make_shared<sqlb::PrimaryKeyConstraint>();
														pk->setName(yystack_[6].value.as < std::string > ());
														pk->setConflictAction(yystack_[0].value.as < std::string > ());
														yylhs.value.as < TableConstraints > ().index.insert(std::make_pair(yystack_[2].value.as < sqlb::IndexedColumnVector > (), pk));
													}
#line 3276 "sqlite3_parser.cpp"
    break;

  case 285: // tableconstraint: optional_constraintname "PRIMARY" "KEY" "(" indexed_column_list "AUTOINCREMENT" ")" optional_conflictclause
#line 855 "sqlite3_parser.yy"
                                                                                                                {
														auto pk = std::make_shared<sqlb::PrimaryKeyConstraint>();
														pk->setName(yystack_[7].value.as < std::string > ());
														pk->setConflictAction(yystack_[0].value.as < std::string > ());
														pk->setAutoIncrement(true);
														yylhs.value.as < TableConstraints > ().index.insert(std::make_pair(yystack_[3].value.as < sqlb::IndexedColumnVector > (), pk));
													}
#line 3288 "sqlite3_parser.cpp"
    break;

  case 286: // tableconstraint: optional_constraintname "UNIQUE" "(" indexed_column_list ")" optional_conflictclause
#line 862 "sqlite3_parser.yy"
                                                                                                        {
														auto u = std::make_shared<sqlb::UniqueConstraint>();
														u->setName(yystack_[5].value.as < std::string > ());
														u->setConflictAction(yystack_[0].value.as < std::string > ());
														sqlb::StringVector columns;
														yylhs.value.as < TableConstraints > ().index.insert(std::make_pair(yystack_[2].value.as < sqlb::IndexedColumnVector > (), u));
													}
#line 3300 "sqlite3_parser.cpp"
    break;

  case 287: // tableconstraint: optional_constraintname "CHECK" "(" expr ")"
#line 869 "sqlite3_parser.yy"
                                                                                                        {
														auto c = std::make_shared<sqlb::CheckConstraint>(yystack_[1].value.as < std::string > ());
														c->setName(yystack_[4].value.as < std::string > ());
														yylhs.value.as < TableConstraints > ().check.push_back(c);
													}
#line 3310 "sqlite3_parser.cpp"
    break;

  case 288: // tableconstraint: optional_constraintname "FOREIGN" "KEY" "(" columnid_list ")" "REFERENCES" tableid optional_columnid_with_paren_list optional_fk_clause
#line 874 "sqlite3_parser.yy"
                                                                                                                                                {
														auto f = std::make_shared<sqlb::ForeignKeyClause>(yystack_[2].value.as < std::string > (), yystack_[1].value.as < sqlb::StringVector > (), yystack_[0].value.as < std::string > ());
														f->setName(yystack_[9].value.as < std::string > ());
														yylhs.value.as < TableConstraints > ().fk.insert(std::make_pair(yystack_[5].value.as < sqlb::StringVector > (), f));
													}
#line 3320 "sqlite3_parser.cpp"
    break;

  case 289: // tableconstraint_list: tableconstraint
#line 882 "sqlite3_parser.yy"
                                                        { yylhs.value.as < TableConstraints > () = yystack_[0].value.as < TableConstraints > (); }
#line 3326 "sqlite3_parser.cpp"
    break;

  case 290: // tableconstraint_list: tableconstraint_list "," tableconstraint
#line 883 "sqlite3_parser.yy"
                                                        { yylhs.value.as < TableConstraints > () = yystack_[2].value.as < TableConstraints > (); yylhs.value.as < TableConstraints > ().index.insert(yystack_[0].value.as < TableConstraints > ().index.begin(), yystack_[0].value.as < TableConstraints > ().index.end()); yylhs.value.as < TableConstraints > ().fk.insert(yystack_[0].value.as < TableConstraints > ().fk.begin(), yystack_[0].value.as < TableConstraints > ().fk.end()); std::copy(yystack_[0].value.as < TableConstraints > ().check.begin(), yystack_[0].value.as < TableConstraints > ().check.end(), std::back_inserter(yylhs.value.as < TableConstraints > ().check)); }
#line 3332 "sqlite3_parser.cpp"
    break;

  case 291: // tableconstraint_list: tableconstraint_list tableconstraint
#line 884 "sqlite3_parser.yy"
                                                        { yylhs.value.as < TableConstraints > () = yystack_[1].value.as < TableConstraints > (); yylhs.value.as < TableConstraints > ().index.insert(yystack_[0].value.as < TableConstraints > ().index.begin(), yystack_[0].value.as < TableConstraints > ().index.end()); yylhs.value.as < TableConstraints > ().fk.insert(yystack_[0].value.as < TableConstraints > ().fk.begin(), yystack_[0].value.as < TableConstraints > ().fk.end()); std::copy(yystack_[0].value.as < TableConstraints > ().check.begin(), yystack_[0].value.as < TableConstraints > ().check.end(), std::back_inserter(yylhs.value.as < TableConstraints > ().check)); }
#line 3338 "sqlite3_parser.cpp"
    break;

  case 292: // optional_tableconstraint_list: %empty
#line 888 "sqlite3_parser.yy"
                                                        { }
#line 3344 "sqlite3_parser.cpp"
    break;

  case 293: // optional_tableconstraint_list: "," tableconstraint_list
#line 889 "sqlite3_parser.yy"
                                                        { yylhs.value.as < TableConstraints > () = yystack_[0].value.as < TableConstraints > (); }
#line 3350 "sqlite3_parser.cpp"
    break;

  case 294: // createtable_stmt: "CREATE" optional_temporary "TABLE" optional_if_not_exists tableid_with_uninteresting_schema "AS" select_stmt
#line 893 "sqlite3_parser.yy"
                                                                                                                        {
										yylhs.value.as < sqlb::TablePtr > () = std::make_shared<sqlb::Table>(yystack_[2].value.as < std::string > ());
										yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(false);
									}
#line 3359 "sqlite3_parser.cpp"
    break;

  case 295: // createtable_stmt: "CREATE" optional_temporary "TABLE" optional_if_not_exists tableid_with_uninteresting_schema "(" columndef_list optional_tableconstraint_list ")" optional_tableoptions_list
#line 897 "sqlite3_parser.yy"
                                                                                                                                                                                                {
										yylhs.value.as < sqlb::TablePtr > () = std::make_shared<sqlb::Table>(yystack_[5].value.as < std::string > ());
										yylhs.value.as < sqlb::TablePtr > ()->setWithoutRowidTable(yystack_[0].value.as < std::bitset<sqlb::Table::NumOptions> > ().test(sqlb::Table::WithoutRowid));
										yylhs.value.as < sqlb::TablePtr > ()->setStrict(yystack_[0].value.as < std::bitset<sqlb::Table::NumOptions> > ().test(sqlb::Table::Strict));
										for(const auto& i : yystack_[2].value.as < TableConstraints > ().index)
											yylhs.value.as < sqlb::TablePtr > ()->addConstraint(i.first, i.second);
										for(const auto& i : yystack_[2].value.as < TableConstraints > ().fk)
											yylhs.value.as < sqlb::TablePtr > ()->addConstraint(i.first, i.second);
										for(const auto& i : yystack_[2].value.as < TableConstraints > ().check)
											yylhs.value.as < sqlb::TablePtr > ()->addConstraint(i);
										yylhs.value.as < sqlb::TablePtr > ()->setFullyParsed(true);

										for(const auto& f : yystack_[3].value.as < ColumnList > ().first)
											yylhs.value.as < sqlb::TablePtr > ()->fields.push_back(*f);
										for(const auto& pk : yystack_[3].value.as < ColumnList > ().second.index)
											yylhs.value.as < sqlb::TablePtr > ()->addConstraint(pk.first, pk.second);
										for(const auto& fk : yystack_[3].value.as < ColumnList > ().second.fk)
											yylhs.value.as < sqlb::TablePtr > ()->addConstraint(fk.first, fk.second);
									}
#line 3383 "sqlite3_parser.cpp"
    break;


#line 3387 "sqlite3_parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -318;

  const short parser::yytable_ninf_ = -294;

  const short
  parser::yypact_[] =
  {
     -16,   214,    57,   116,  -318,  -318,  -318,  -318,  -318,  -318,
      60,    10,   121,  -318,  -318,   108,   108,   108,   171,  3610,
    3610,  3610,   172,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
    -318,  -318,   255,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
     264,  -318,  -318,   167,   202,    72,  -318,  3701,  3701,   150,
    3701,  3519,   189,  -318,  -318,  -318,  -318,   290,   293,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  3701,  -318,   294,  -318,
    -318,  1316,  -318,  2018,  -318,  2229,  -318,  -318,    47,  3428,
     300,  2018,  -318,  2018,  2018,  2018,  1433,   304,  -318,  -318,
    -318,  -318,  2018,  -318,   307,  -318,  -318,  -318,  -318,  -318,
    -318,    69,  -318,  -318,  -318,  -318,    46,  -318,  -318,  -318,
    -318,  -318,  -318,  3257,  2527,  -318,   182,     6,  -318,   100,
    -318,   219,  -318,   101,  -318,   127,   -18,   248,   -22,   -22,
     -22,  2018,    27,  2605,  2018,    92,   191,   965,   150,  -318,
    2018,  2018,  2018,  2018,  2018,  2018,  2018,  2018,  2018,  2018,
    2018,  2018,  2018,  2018,  2018,  2018,  2018,  2018,  2018,  2018,
    2018,   150,  2018,  2323,  1550,  -318,  2018,  2018,   306,  -318,
    2018,  2018,  2018,  2018,  -318,  -318,  -318,   201,  2018,   204,
     207,  -318,  -318,   266,  -318,  -318,   329,   150,  2135,   313,
     279,  -318,   292,  3701,   299,   356,   135,   394,   310,   325,
     395,   359,  -318,  -318,   305,  -318,    24,  -318,  -318,  2683,
    2018,  -318,  2018,    31,  2775,   396,   397,   400,   399,  -318,
     402,  2018,   269,   403,  3257,    15,    15,    26,    26,    30,
      26,    30,    23,   181,   181,     8,     8,     8,     8,   181,
     181,    30,    30,    92,  2853,  -318,   335,  1082,   274,  -318,
     345,  1667,   181,   556,   916,  2018,  2018,  2417,  2018,  2018,
    -318,  2018,   516,  2720,  3257,  3257,  2018,  -318,  -318,  -318,
    -318,  -318,     6,  2018,  -318,  2018,  -318,  -318,  -318,  -318,
    -318,  -318,   299,   112,   406,   369,  -318,   408,  2018,   409,
     410,  2018,  -318,  -318,   -18,  -318,  2018,  2931,  3009,  2018,
    -318,  3701,   298,   301,  -318,   302,  -318,   319,  -318,   150,
    2018,  2018,  -318,   324,   412,  2018,  3701,  2018,   357,  2018,
    2018,  3101,  3046,  1199,   326,  -318,  3294,  3342,  3379,  2018,
    3257,   416,   216,   710,  -318,   299,  3519,   233,   196,  2018,
     793,  3519,  2018,   334,  -318,  3257,  -318,  2018,  3179,   417,
     418,   420,   425,  -318,  -318,   181,   181,  -318,  -318,   358,
     427,  -318,   -22,  2018,   181,   181,  2018,  2018,  -318,   363,
     429,  2018,  3701,  2018,  2018,  2018,   181,  -318,  -318,  -318,
     401,  -318,   372,   361,   150,   389,   107,  -318,   287,  -318,
    -318,  -318,  -318,  -318,  -318,   876,  -318,   373,   177,   299,
    3257,  -318,  -318,  -318,  -318,  -318,  -318,  1784,   -22,   181,
     181,  -318,  -318,   381,   433,  -318,   181,   181,   181,  -318,
    -318,  3519,    99,  -318,   370,    -4,    -1,   173,   371,   391,
    -318,   -63,   353,   299,   439,  -318,  -318,   387,  -318,  1901,
    -318,  -318,  -318,   109,  -318,   419,  -318,    -2,  -318,   421,
    -318,    79,  -318,   422,  -318,   105,   126,   374,  -318,  -318,
    -318,  3701,  -318,   299,  -318,  -318,   388,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
     194,   406,  -318,  -318,  -318,  -318,   233,  -318
  };

  const short
  parser::yydefact_[] =
  {
       0,   187,     0,     2,     4,     5,     6,   203,   204,   188,
       0,     0,     0,     1,     3,   182,   182,   182,     0,     0,
       0,     0,     0,    18,    19,    20,    21,    22,    23,    24,
      61,    60,    62,    25,    26,    27,    28,    29,    30,    31,
      32,    35,    37,    36,    33,    34,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    54,    56,    57,    58,    16,    64,    17,
      63,    59,   193,     0,     0,     0,   183,     0,     0,     0,
       0,     0,     0,    55,    63,   192,   191,   198,     0,    67,
      66,    68,    69,    71,    70,    65,   218,   240,   292,   181,
     294,     0,   201,     0,    76,    78,   219,   242,   245,   245,
       0,     0,   199,     0,     0,     0,     0,    23,    14,    13,
      15,    12,     0,    10,    43,    11,     7,     8,     9,   165,
     163,   168,   164,   169,   170,   175,     0,   171,   176,   177,
     178,   179,   180,   126,   184,   195,     0,     0,    77,     0,
     241,   223,   240,     0,   289,   245,   210,     0,    82,    81,
      83,     0,     0,     0,     0,    84,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,     0,     0,     0,   133,
       0,     0,     0,     0,   185,   186,   194,   189,     0,     0,
       0,    75,    74,     0,   247,   246,     0,     0,     0,     0,
       0,   228,     0,     0,   212,     0,   245,     0,     0,     0,
       0,   245,   291,   206,     0,   207,   211,   295,   172,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,   167,   127,    91,    92,    86,    87,    95,
      90,    96,    85,   101,   102,    99,   100,    97,    98,   103,
     104,    93,    94,   108,     0,   174,   111,     0,    63,   141,
       0,     0,   105,   110,   112,     0,     0,     0,     0,     0,
     134,     0,   109,   113,    88,    89,     0,   197,   196,    72,
      73,    79,     0,     0,   237,     0,   235,   232,   233,   234,
     231,   224,   212,   184,   250,     0,   229,     0,     0,     0,
       0,     0,   290,   205,     0,   209,     0,     0,     0,     0,
     156,     0,     0,     0,   159,     0,   131,     0,   128,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,     0,    63,   149,   114,   116,   117,     0,
     190,     0,     0,     0,   227,   212,     0,   270,     0,     0,
       0,     0,     0,     0,   208,   153,   157,     0,     0,     0,
       0,     0,     0,   129,   166,   135,   119,   139,   138,     0,
      63,   140,   106,     0,   118,   120,     0,     0,   145,     0,
       0,     0,     0,     0,     0,     0,   121,    80,   230,   236,
     225,   248,     0,   280,     0,     0,     0,   268,   271,   238,
     214,   215,   216,   217,   213,     0,   287,     0,     0,   212,
     154,   155,   173,   161,   162,   160,   144,     0,   107,   136,
     123,   147,   146,     0,    63,   148,   122,   124,   125,   226,
     251,     0,     0,   267,   283,     0,     0,     0,   274,     0,
     269,   220,     0,   212,     0,   286,   142,     0,   152,     0,
     249,   278,   279,     0,   254,     0,   255,     0,   264,     0,
     265,     0,   259,     0,   260,     0,     0,   277,   221,   222,
     239,     0,   284,   212,   143,   150,     0,   281,   282,   256,
     253,   252,   266,   263,   262,   261,   258,   257,   272,   273,
       0,   250,   285,   151,   275,   276,   270,   288
  };

  const short
  parser::yypgoto_[] =
  {
    -318,  -318,  -318,   227,   -19,   -13,   -68,  -317,   230,   144,
    -318,   120,  -318,  -318,  -318,   -98,  -318,  -318,  -318,  -318,
     289,  -318,  -318,   312,  -266,   228,   140,  -318,  -318,   352,
     246,  -301,  -318,  -318,  -318,  -318,  -231,  -318,  -318,  -309,
    -318,  -318,  -318,  -318,   308,   348,  -318,  -104,    87,   -52,
      43,  -318,   -54,  -112,  -318,  -318,  -318
  };

  const short
  parser::yydefgoto_[] =
  {
       0,     2,     3,   130,   131,   132,    72,    96,   212,   213,
     105,   106,   133,   134,   135,   136,   137,   138,   139,   140,
     162,   141,   142,   143,   100,    19,   206,    11,   297,    73,
     145,   146,     4,   102,     5,    12,   235,   236,   237,   316,
     107,   490,   225,   150,   108,    97,    98,   153,   412,   367,
     417,   418,   419,   154,   155,   110,     6
  };

  const short
  parser::yytable_[] =
  {
      70,    70,    70,   364,   151,   325,    71,    71,    71,    85,
      86,   344,    88,   157,   209,   210,   171,   172,   173,   174,
     373,   175,   176,   177,   178,   173,   174,     1,   104,   176,
     324,   178,   474,   187,   188,   478,   488,   148,   171,   172,
     173,   174,   178,   232,   176,   500,   178,   489,   191,   411,
     169,  -243,   170,  -243,   411,   191,   410,    13,    84,    84,
      87,    84,    94,   191,    71,    71,   191,    71,    95,   252,
     191,   428,   167,   475,   168,    81,   479,    84,   501,    16,
     240,   241,   233,    71,   329,   330,    84,   400,   476,   149,
      94,   480,    71,   374,   477,   234,    95,   481,   202,   203,
     171,   172,   173,   174,    82,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   322,
     465,   211,   151,    14,   233,   279,   503,   190,   202,   203,
     215,  -293,   191,   231,   470,   202,   203,   234,   242,  -244,
     227,  -244,   242,   202,   203,   204,   202,   203,   471,   253,
     202,   203,   506,   337,   492,   314,   192,   455,   497,   504,
     193,    15,   228,   205,   194,   195,   472,   196,   197,   149,
     198,   199,   275,    18,   278,   508,   498,   149,   456,   343,
      71,   463,   201,   208,   512,   507,   207,   229,   208,   171,
     172,   173,   174,   509,   175,   176,   177,   178,   304,   308,
     181,   182,   183,   184,    84,   309,   187,   188,   230,   482,
      71,   464,   202,   203,    67,   457,   214,    69,   245,   355,
     408,   191,    17,   420,   171,   172,   173,   174,    76,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   514,    20,    21,   189,   389,   246,    22,
     483,   190,   238,   421,   170,   399,   191,   247,   216,   217,
      77,   515,   422,   104,    67,   484,   218,    69,   354,    78,
     301,   485,   302,   338,    71,   170,    79,   345,   391,   346,
     192,   413,   219,    80,   193,   248,    99,   423,   194,   195,
     424,   196,   197,   101,   198,   199,   103,   220,   200,   221,
     109,   202,   203,   443,   156,   222,   201,   164,   223,   414,
     166,   415,    84,   296,   416,  -202,     7,     8,    71,   299,
     384,     9,   300,   383,    10,   170,   224,   390,   387,   401,
     170,   402,   303,    71,   445,   458,   202,   203,   429,   467,
     208,   285,   311,   171,   172,   173,   174,    94,   175,   176,
     177,   178,    94,    95,   181,   182,   183,   184,    95,   312,
     187,   188,   436,   414,   170,   459,   313,   441,   416,   170,
     286,   496,    74,    75,   287,   191,   450,   462,   451,   451,
     315,   288,   289,   444,   319,   468,   290,   170,   317,    71,
     341,   494,   513,   170,   170,   453,   291,   318,   321,   320,
     323,   149,   332,   333,   334,   335,   336,   347,   339,   366,
     368,   369,   371,   372,   380,   144,   388,   381,   382,   393,
     407,   432,   433,   511,   434,   158,   159,   160,   163,   435,
     437,   452,    94,   442,   165,   449,   469,   454,    95,   487,
     473,   486,   491,   493,   510,   307,   361,   499,   310,   502,
     505,   379,   243,   365,   298,   202,   203,   152,   427,   516,
     226,   460,   517,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,   239,     0,     0,   244,     0,    71,     0,
       0,     0,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,     0,   276,     0,   282,     0,   283,   284,
       0,     0,   292,   293,   294,   295,     0,     0,     0,     0,
     144,     0,     0,     0,   171,   172,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,     0,     0,   189,     0,     0,     0,
       0,   190,   327,     0,   328,     0,   191,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,     0,   175,
     176,   177,   178,     0,     0,   181,   182,   183,   184,     0,
     192,   187,   188,     0,   193,     0,     0,     0,   194,   195,
       0,   196,   197,   165,   198,   199,   191,   351,   352,     0,
     356,   357,     0,   358,     0,     0,   201,     0,   360,     0,
       0,   349,     0,     0,     0,   362,     0,   363,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,     0,     0,   144,     0,     0,   202,   203,   375,     0,
       0,   378,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   385,   386,     0,     0,     0,     0,     0,   392,
       0,   394,   395,     0,     0,     0,     0,     0,     0,     0,
       0,   406,     0,     0,     0,     0,   202,   203,     0,     0,
       0,   425,     0,     0,   144,     0,     0,     0,     0,   430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,     0,     0,   439,   440,
       0,     0,     0,     0,   409,   446,   447,   448,   171,   172,
     173,   174,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,     0,     0,
     189,     0,     0,     0,     0,   190,     0,     0,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,   193,     0,
       0,     0,   194,   195,     0,   196,   197,     0,   198,   199,
       0,     0,   200,     0,     0,     0,     0,   426,     0,     0,
     201,   171,   172,   173,   174,     0,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,   189,     0,     0,     0,     0,   190,     0,
     202,   203,     0,   191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,   193,     0,     0,     0,   194,   195,     0,   196,   197,
       0,   198,   199,     0,     0,   200,     0,     0,     0,     0,
     461,     0,     0,   201,   171,   172,   173,   174,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,     0,     0,     0,   189,     0,     0,     0,
       0,   190,     0,   202,   203,     0,   191,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,     0,   175,
     176,   177,   178,     0,     0,   181,   182,   183,   184,     0,
     192,   187,   188,     0,   193,     0,     0,     0,   194,   195,
       0,   196,   197,     0,   198,   199,   191,     0,   200,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   111,   249,
       0,   350,     0,   113,   114,   250,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,     0,   202,   203,    26,     0,
       0,    27,   116,   117,     0,     0,    29,     0,     0,   118,
     119,   120,     0,     0,    33,     0,    34,   251,     0,    35,
       0,     0,    36,   121,    37,    38,     0,     0,    39,    40,
       0,    41,    42,     0,     0,    43,   202,   203,     0,    44,
      45,    46,    47,   122,     0,   123,     0,     0,    48,    49,
      50,     0,   124,    52,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,     0,    83,    63,     0,
     125,    64,     0,     0,     0,    65,     0,     0,    66,    67,
     126,   127,    69,   128,   129,   111,   342,     0,     0,     0,
     113,   114,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,    25,     0,     0,     0,    26,     0,     0,    27,   116,
     117,     0,     0,    29,     0,     0,   118,   119,   120,     0,
       0,    33,     0,    34,     0,     0,    35,     0,     0,    36,
     121,    37,    38,     0,     0,    39,    40,     0,    41,    42,
       0,     0,    43,     0,     0,     0,    44,    45,    46,    47,
     122,     0,   123,     0,     0,    48,    49,    50,     0,   124,
      52,     0,    53,    54,    55,    56,    57,    58,    59,    99,
       0,    60,    61,     0,    83,    63,     0,   125,    64,     0,
       0,     0,    65,     0,     0,    66,    67,   126,   127,    69,
     128,   129,   111,   398,     0,     0,     0,   113,   114,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,     0,
       0,     0,    26,     0,     0,    27,   116,   117,     0,     0,
      29,     0,     0,   118,   119,   120,     0,     0,    33,     0,
      34,     0,     0,    35,     0,     0,    36,   121,    37,    38,
       0,     0,    39,    40,     0,    41,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,   122,     0,   123,
       0,     0,    48,    49,    50,     0,   124,    52,     0,    53,
      54,    55,    56,    57,    58,    59,    99,     0,    60,    61,
       0,    83,    63,     0,   125,    64,     0,     0,     0,    65,
       0,     0,    66,    67,   126,   127,    69,   128,   129,   111,
     112,     0,     0,     0,   113,   114,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,     0,     0,     0,    26,
       0,     0,    27,   116,   117,     0,     0,    29,     0,     0,
     118,   119,   120,     0,     0,    33,     0,    34,     0,     0,
      35,     0,     0,    36,   121,    37,    38,     0,     0,    39,
      40,     0,    41,    42,     0,     0,    43,     0,     0,     0,
      44,    45,    46,    47,   122,     0,   123,     0,     0,    48,
      49,    50,     0,   124,    52,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,     0,    83,    63,
       0,   125,    64,     0,     0,     0,    65,     0,     0,    66,
      67,   126,   127,    69,   128,   129,   111,     0,     0,     0,
       0,   113,   114,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,    25,     0,     0,     0,    26,     0,     0,    27,
     116,   117,     0,     0,    29,     0,     0,   118,   119,   120,
       0,     0,    33,     0,    34,     0,     0,    35,     0,     0,
      36,   121,    37,    38,     0,     0,    39,    40,     0,    41,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,   122,     0,   123,     0,     0,    48,    49,    50,     0,
     124,    52,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    60,    61,     0,    83,    63,     0,   125,    64,
       0,     0,     0,    65,   161,     0,    66,    67,   126,   127,
      69,   128,   129,   111,     0,     0,     0,     0,   113,   114,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
       0,     0,     0,    26,     0,     0,    27,   116,   117,     0,
       0,    29,     0,     0,   118,   119,   120,     0,     0,    33,
       0,    34,   280,     0,    35,     0,     0,    36,   121,    37,
      38,     0,     0,    39,    40,     0,    41,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,   281,     0,
     123,     0,     0,    48,    49,    50,     0,   124,    52,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     0,    83,    63,     0,   125,    64,     0,     0,     0,
      65,     0,     0,    66,    67,   126,   127,    69,   128,   129,
     111,     0,     0,     0,     0,   113,   114,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,     0,     0,     0,
      26,     0,     0,    27,   116,   117,     0,     0,    29,     0,
       0,   118,   119,   120,     0,     0,    33,     0,    34,   348,
       0,    35,     0,     0,    36,   121,    37,    38,     0,     0,
      39,    40,     0,    41,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,   122,     0,   123,     0,     0,
      48,    49,    50,     0,   124,    52,     0,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,    61,     0,    83,
      63,     0,   125,    64,     0,     0,     0,    65,     0,     0,
      66,    67,   126,   127,    69,   128,   129,   111,   466,     0,
       0,     0,   113,   114,     0,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    24,    25,     0,     0,     0,    26,     0,     0,
      27,   116,   117,     0,     0,    29,     0,     0,   118,   119,
     120,     0,     0,    33,     0,    34,     0,     0,    35,     0,
       0,    36,   121,    37,    38,     0,     0,    39,    40,     0,
      41,    42,     0,     0,    43,     0,     0,     0,    44,    45,
      46,    47,   122,     0,   123,     0,     0,    48,    49,    50,
       0,   124,    52,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,    61,     0,    83,    63,     0,   125,
      64,     0,     0,     0,    65,     0,     0,    66,    67,   126,
     127,    69,   128,   129,   111,   495,     0,     0,     0,   113,
     114,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    24,
      25,     0,     0,     0,    26,     0,     0,    27,   116,   117,
       0,     0,    29,     0,     0,   118,   119,   120,     0,     0,
      33,     0,    34,     0,     0,    35,     0,     0,    36,   121,
      37,    38,     0,     0,    39,    40,     0,    41,    42,     0,
       0,    43,     0,     0,     0,    44,    45,    46,    47,   122,
       0,   123,     0,     0,    48,    49,    50,     0,   124,    52,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,     0,    83,    63,     0,   125,    64,     0,     0,
       0,    65,     0,     0,    66,    67,   126,   127,    69,   128,
     129,   111,     0,     0,     0,     0,   113,   114,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,     0,     0,
       0,    26,     0,     0,    27,   116,   117,     0,     0,    29,
       0,     0,   118,   119,   120,     0,     0,    33,     0,    34,
       0,     0,    35,     0,     0,    36,   121,    37,    38,     0,
       0,    39,    40,     0,    41,    42,     0,     0,    43,     0,
       0,     0,    44,    45,    46,    47,   122,     0,   123,     0,
       0,    48,    49,    50,     0,   124,    52,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,     0,
      83,    63,     0,   125,    64,     0,     0,     0,    65,     0,
       0,    66,    67,   126,   127,    69,   128,   129,   305,     0,
       0,     0,     0,   209,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,    25,     0,     0,     0,    26,     0,
       0,    27,     0,    28,     0,     0,    29,     0,     0,   118,
     119,   120,     0,     0,    33,     0,    34,     0,     0,    35,
       0,     0,    36,   121,    37,    38,     0,     0,    39,    40,
     306,    41,    42,     0,     0,    43,     0,     0,     0,    44,
      45,    46,    47,     0,     0,   123,     0,     0,    48,    49,
      50,     0,    51,    52,     0,    53,    54,    55,    56,    57,
      58,    59,   147,     0,    60,    61,     0,    83,    63,     0,
     125,    64,     0,     0,     0,    65,     0,     0,    66,    67,
     126,   127,    69,   128,     0,     0,    23,    24,    25,     0,
       0,     0,    26,     0,     0,    27,     0,    28,     0,     0,
      29,     0,     0,    30,    31,    32,     0,     0,    33,     0,
      34,     0,     0,    35,     0,     0,    36,     0,    37,    38,
       0,     0,    39,    40,     0,    41,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,     0,     0,
       0,     0,    48,    49,    50,     0,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,   277,     0,    60,    61,
       0,    83,    63,     0,     0,    64,     0,     0,     0,    65,
       0,     0,    66,    67,     0,    68,    69,     0,     0,     0,
      23,    24,    25,     0,     0,     0,    26,     0,     0,    27,
       0,    28,     0,     0,    29,     0,     0,    30,    31,    32,
       0,     0,    33,     0,    34,     0,     0,    35,     0,     0,
      36,     0,    37,    38,     0,     0,    39,    40,     0,    41,
      42,     0,     0,    43,     0,     0,     0,    44,    45,    46,
      47,     0,     0,     0,     0,     0,    48,    49,    50,     0,
      51,    52,     0,    53,    54,    55,    56,    57,    58,    59,
     353,     0,    60,    61,     0,    83,    63,     0,     0,    64,
       0,     0,     0,    65,     0,     0,    66,    67,     0,    68,
      69,     0,     0,     0,    23,    24,    25,     0,     0,     0,
      26,     0,     0,    27,     0,    28,     0,     0,    29,     0,
       0,    30,    31,    32,     0,     0,    33,     0,    34,     0,
       0,    35,     0,     0,    36,     0,    37,    38,     0,     0,
      39,    40,     0,    41,    42,     0,     0,    43,     0,     0,
       0,    44,    45,    46,    47,     0,     0,     0,     0,     0,
      48,    49,    50,     0,    51,    52,     0,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    60,    61,     0,    83,
      63,     0,     0,    64,     0,     0,     0,    65,     0,     0,
      66,    67,     0,    68,    69,   171,   172,   173,   174,     0,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,     0,     0,   189,     0,     0,
     204,     0,   190,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,     0,     0,     0,   193,     0,     0,     0,   194,
     195,     0,   196,   197,     0,   198,   199,     0,     0,   200,
       0,     0,     0,   171,   172,   173,   174,   201,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,     0,     0,   189,     0,     0,     0,     0,
     190,     0,     0,     0,     0,   191,     0,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
       0,     0,     0,   193,     0,     0,     0,   194,   195,     0,
     196,   197,     0,   198,   199,     0,     0,   200,     0,     0,
       0,   171,   172,   173,   174,   201,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,   189,     0,     0,   161,     0,   190,     0,
       0,     0,     0,   191,     0,   202,   203,     0,   171,   172,
     173,   174,     0,   175,   176,   177,   178,     0,     0,   181,
     182,   183,   184,     0,     0,   187,   188,   192,     0,     0,
       0,   193,     0,     0,     0,   194,   195,     0,   196,   197,
     191,   198,   199,     0,     0,   200,     0,     0,     0,     0,
       0,     0,     0,   201,     0,   359,     0,     0,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   326,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   202,   203,   189,     0,   331,     0,     0,
     190,     0,     0,     0,     0,   191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     202,   203,     0,   193,     0,     0,     0,   194,   195,     0,
     196,   197,     0,   198,   199,     0,     0,   200,     0,     0,
       0,   171,   172,   173,   174,   201,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,     0,     0,   189,   340,     0,     0,     0,   190,     0,
       0,     0,     0,   191,     0,   202,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,   193,     0,     0,     0,   194,   195,     0,   196,   197,
       0,   198,   199,     0,     0,   200,     0,     0,     0,   171,
     172,   173,   174,   201,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,     0,
       0,   189,     0,     0,     0,     0,   190,     0,     0,     0,
       0,   191,     0,   202,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,     0,     0,     0,   193,
       0,     0,     0,   194,   195,     0,   196,   197,     0,   198,
     199,     0,     0,   200,     0,     0,     0,   171,   172,   173,
     174,   201,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,   189,
       0,     0,     0,     0,   190,     0,     0,     0,     0,   191,
       0,   202,   203,     0,   171,   172,   173,   174,     0,   175,
     176,   177,   178,     0,     0,   181,   182,   183,   184,     0,
       0,   187,   188,   192,     0,     0,     0,   193,     0,     0,
       0,   194,   195,     0,   196,   197,   191,   198,   199,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,   201,
       0,   397,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   377,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   202,
     203,   189,   396,     0,     0,     0,   190,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   202,   203,     0,   193,
       0,     0,     0,   194,   195,     0,   196,   197,     0,   198,
     199,     0,     0,   200,     0,     0,     0,   171,   172,   173,
     174,   201,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,     0,     0,   189,
       0,     0,     0,     0,   190,     0,     0,     0,     0,   191,
       0,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,     0,     0,     0,   193,     0,     0,
       0,   194,   195,     0,   196,   197,     0,   198,   199,     0,
       0,   200,     0,     0,     0,   171,   172,   173,   174,   201,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,     0,     0,   189,     0,     0,
       0,     0,   190,     0,     0,     0,     0,   191,     0,   202,
     203,     0,   171,   172,   173,   174,     0,   175,   176,   177,
     178,     0,     0,   181,   182,   183,   184,     0,     0,   187,
     188,   192,     0,     0,     0,   193,     0,     0,     0,   194,
     195,     0,   196,   197,   191,   198,   199,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,   201,     0,   403,
     171,   172,   173,   174,     0,   175,   176,   177,   178,     0,
       0,   181,   182,   183,   184,     0,     0,   187,   188,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   203,     0,
       0,     0,   191,     0,     0,     0,     0,   171,   172,   173,
     174,     0,   175,   176,   177,   178,     0,   404,   181,   182,
     183,   184,     0,     0,   187,   188,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   203,     0,     0,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    24,    25,     0,     0,
       0,    26,   202,   203,    27,     0,    28,     0,     0,    29,
     149,     0,    89,    90,    91,     0,     0,    33,     0,    34,
       0,     0,    35,     0,     0,    36,     0,    37,    38,     0,
       0,    39,    40,    92,    41,    42,     0,     0,    43,   202,
     203,     0,    44,    45,    46,    47,     0,     0,     0,     0,
       0,    48,    49,    50,     0,    51,    52,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,     0,
      83,    63,     0,     0,    64,     0,     0,     0,    65,     0,
       0,    66,    67,     0,    93,    69,    23,    24,    25,     0,
       0,     0,    26,     0,     0,    27,     0,    28,     0,     0,
      29,     0,     0,    89,    90,    91,     0,     0,    33,     0,
      34,     0,     0,    35,     0,     0,    36,     0,    37,    38,
       0,     0,    39,    40,    92,    41,    42,     0,     0,    43,
       0,     0,     0,    44,    45,    46,    47,     0,     0,     0,
       0,     0,    48,    49,    50,     0,    51,    52,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,    61,
       0,    83,    63,     0,     0,    64,     0,     0,     0,    65,
       0,     0,    66,    67,     0,    93,    69,    23,    24,    25,
       0,     0,     0,    26,     0,     0,    27,     0,    28,     0,
       0,    29,     0,     0,    30,    31,    32,     0,     0,    33,
       0,    34,     0,     0,    35,     0,     0,    36,     0,    37,
      38,     0,     0,    39,    40,     0,    41,    42,     0,     0,
      43,     0,     0,     0,    44,    45,    46,    47,     0,     0,
       0,     0,     0,    48,    49,    50,     0,    51,    52,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,     0,    62,    63,     0,     0,    64,     0,     0,     0,
      65,     0,     0,    66,    67,     0,    68,    69,    23,    24,
      25,     0,     0,     0,    26,     0,     0,    27,     0,    28,
       0,     0,    29,     0,     0,    30,    31,    32,     0,     0,
      33,     0,    34,     0,     0,    35,     0,     0,    36,     0,
      37,    38,     0,     0,    39,    40,     0,    41,    42,     0,
       0,    43,     0,     0,     0,    44,    45,    46,    47,     0,
       0,     0,     0,     0,    48,    49,    50,     0,    51,    52,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,     0,    83,    63,     0,     0,    64,     0,     0,
       0,    65,     0,     0,    66,    67,     0,    68,    69
  };

  const short
  parser::yycheck_[] =
  {
      19,    20,    21,   312,   108,   236,    19,    20,    21,    77,
      78,   277,    80,   111,     8,     9,     8,     9,    10,    11,
     321,    13,    14,    15,    16,    10,    11,    43,    96,    14,
       6,    16,    36,    25,    26,    36,    99,   105,     8,     9,
      10,    11,    16,   155,    14,    47,    16,   110,    40,   366,
       4,     4,     6,     6,   371,    40,   365,     0,    77,    78,
      79,    80,    81,    40,    77,    78,    40,    80,    81,   167,
      40,   372,     3,    77,     5,     3,    77,    96,    80,    69,
      53,    54,   100,    96,    53,    54,   105,   353,    92,    42,
     109,    92,   105,   324,    98,   113,   109,    98,   120,   121,
       8,     9,    10,    11,    32,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   231,
     429,   115,   226,     7,   100,   193,    47,    35,   120,   121,
     149,     4,    40,     6,   451,   120,   121,   113,   111,     4,
      39,     6,   111,   120,   121,    33,   120,   121,    49,   168,
     120,   121,    47,   251,   463,   223,    64,    50,    49,    80,
      68,   101,    61,    51,    72,    73,    67,    75,    76,    42,
      78,    79,   191,    65,   193,    49,    67,    42,    71,   277,
     193,     4,    90,     6,   493,    80,     4,    86,     6,     8,
       9,    10,    11,    67,    13,    14,    15,    16,   217,   218,
      19,    20,    21,    22,   223,   218,    25,    26,   107,    36,
     223,    34,   120,   121,   114,   108,   116,   117,    27,   287,
       4,    40,   101,    27,     8,     9,    10,    11,    56,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    49,    16,    17,    30,   345,    57,    78,
      77,    35,     4,    57,     6,   353,    40,    66,    39,    40,
       5,    67,    66,   331,   114,    92,    47,   117,   287,     5,
       4,    98,     6,     4,   287,     6,   109,     3,   346,     5,
      64,    48,    63,    81,    68,    94,    97,    91,    72,    73,
      94,    75,    76,     3,    78,    79,     3,    78,    82,    80,
       6,   120,   121,   401,     4,    86,    90,     3,    89,    76,
       3,    78,   331,   112,    81,   101,   102,   103,   331,   115,
     339,   107,   115,     4,   110,     6,   107,   346,     4,     3,
       6,     5,     3,   346,   402,    48,   120,   121,     4,   437,
       6,    35,    29,     8,     9,    10,    11,   366,    13,    14,
      15,    16,   371,   366,    19,    20,    21,    22,   371,    80,
      25,    26,     4,    76,     6,    78,    74,     4,    81,     6,
      64,   469,    20,    21,    68,    40,     4,     4,     6,     6,
      81,    75,    76,   402,    74,     4,    80,     6,    32,   402,
      55,     4,     4,     6,     6,   414,    90,     3,     3,    74,
      95,    42,     6,     6,     4,     6,     4,    62,     5,     3,
      41,     3,     3,     3,   116,   103,     4,   116,   116,    62,
       4,     4,     4,   491,     4,   113,   114,   115,   116,     4,
       3,    70,   451,     4,   122,    34,     3,    48,   451,    48,
      70,    70,    89,     4,    70,   218,   302,    28,   218,    28,
      28,   331,   163,   313,   208,   120,   121,   109,   371,   511,
     152,   418,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,   161,    -1,    -1,   164,    -1,   491,    -1,
      -1,    -1,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,    -1,   192,    -1,   194,    -1,   196,   197,
      -1,    -1,   200,   201,   202,   203,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,   240,    -1,   242,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      64,    25,    26,    -1,    68,    -1,    -1,    -1,    72,    73,
      -1,    75,    76,   281,    78,    79,    40,   285,   286,    -1,
     288,   289,    -1,   291,    -1,    -1,    90,    -1,   296,    -1,
      -1,    55,    -1,    -1,    -1,   303,    -1,   305,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     318,    -1,    -1,   321,    -1,    -1,   120,   121,   326,    -1,
      -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   340,   341,    -1,    -1,    -1,    -1,    -1,   347,
      -1,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   359,    -1,    -1,    -1,    -1,   120,   121,    -1,    -1,
      -1,   369,    -1,    -1,   372,    -1,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,   396,   397,
      -1,    -1,    -1,    -1,     4,   403,   404,   405,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    72,    73,    -1,    75,    76,    -1,    78,    79,
      -1,    -1,    82,    -1,    -1,    -1,    -1,     4,    -1,    -1,
      90,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
     120,   121,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    72,    73,    -1,    75,    76,
      -1,    78,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    90,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,   120,   121,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      64,    25,    26,    -1,    68,    -1,    -1,    -1,    72,    73,
      -1,    75,    76,    -1,    78,    79,    40,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,     3,     4,
      -1,    55,    -1,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,   120,   121,    33,    -1,
      -1,    36,    37,    38,    -1,    -1,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    52,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    63,    64,
      -1,    66,    67,    -1,    -1,    70,   120,   121,    -1,    74,
      75,    76,    77,    78,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    99,   100,    -1,   102,   103,    -1,
     105,   106,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,     3,     4,    -1,    -1,    -1,
       8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    33,    -1,    -1,    36,    37,
      38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,
      58,    59,    60,    -1,    -1,    63,    64,    -1,    66,    67,
      -1,    -1,    70,    -1,    -1,    -1,    74,    75,    76,    77,
      78,    -1,    80,    -1,    -1,    83,    84,    85,    -1,    87,
      88,    -1,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    99,   100,    -1,   102,   103,    -1,   105,   106,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,     3,     4,    -1,    -1,    -1,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    33,    -1,    -1,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,
      -1,    -1,    63,    64,    -1,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    -1,    80,
      -1,    -1,    83,    84,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,   100,
      -1,   102,   103,    -1,   105,   106,    -1,    -1,    -1,   110,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,     3,
       4,    -1,    -1,    -1,     8,     9,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,    33,
      -1,    -1,    36,    37,    38,    -1,    -1,    41,    -1,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    51,    -1,    -1,
      54,    -1,    -1,    57,    58,    59,    60,    -1,    -1,    63,
      64,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    -1,    -1,    83,
      84,    85,    -1,    87,    88,    -1,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    99,   100,    -1,   102,   103,
      -1,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,     3,    -1,    -1,    -1,
      -1,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,    36,
      37,    38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    -1,    -1,    54,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    -1,    80,    -1,    -1,    83,    84,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    94,    95,    96,
      -1,    -1,    99,   100,    -1,   102,   103,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,    -1,   113,   114,   115,   116,
     117,   118,   119,     3,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    36,    37,    38,    -1,
      -1,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    52,    -1,    54,    -1,    -1,    57,    58,    59,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    78,    -1,
      80,    -1,    -1,    83,    84,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
     100,    -1,   102,   103,    -1,   105,   106,    -1,    -1,    -1,
     110,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
       3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      33,    -1,    -1,    36,    37,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    52,
      -1,    54,    -1,    -1,    57,    58,    59,    60,    -1,    -1,
      63,    64,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    80,    -1,    -1,
      83,    84,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,    -1,   102,
     103,    -1,   105,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,     3,     4,    -1,
      -1,    -1,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    51,    -1,    -1,    54,    -1,
      -1,    57,    58,    59,    60,    -1,    -1,    63,    64,    -1,
      66,    67,    -1,    -1,    70,    -1,    -1,    -1,    74,    75,
      76,    77,    78,    -1,    80,    -1,    -1,    83,    84,    85,
      -1,    87,    88,    -1,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    99,   100,    -1,   102,   103,    -1,   105,
     106,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,     3,     4,    -1,    -1,    -1,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    33,    -1,    -1,    36,    37,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,    58,
      59,    60,    -1,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    -1,    -1,    83,    84,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,    -1,   102,   103,    -1,   105,   106,    -1,    -1,
      -1,   110,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,     3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    33,    -1,    -1,    36,    37,    38,    -1,    -1,    41,
      -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    63,    64,    -1,    66,    67,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    -1,    80,    -1,
      -1,    83,    84,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,    -1,
     102,   103,    -1,   105,   106,    -1,    -1,    -1,   110,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,     3,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    33,    -1,
      -1,    36,    -1,    38,    -1,    -1,    41,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    51,    -1,    -1,    54,
      -1,    -1,    57,    58,    59,    60,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    77,    -1,    -1,    80,    -1,    -1,    83,    84,
      85,    -1,    87,    88,    -1,    90,    91,    92,    93,    94,
      95,    96,     3,    -1,    99,   100,    -1,   102,   103,    -1,
     105,   106,    -1,    -1,    -1,   110,    -1,    -1,   113,   114,
     115,   116,   117,   118,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    -1,    63,    64,    -1,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    94,    95,    96,     3,    -1,    99,   100,
      -1,   102,   103,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,   113,   114,    -1,   116,   117,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    33,    -1,    -1,    36,
      -1,    38,    -1,    -1,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    49,    -1,    51,    -1,    -1,    54,    -1,    -1,
      57,    -1,    59,    60,    -1,    -1,    63,    64,    -1,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    94,    95,    96,
       3,    -1,    99,   100,    -1,   102,   103,    -1,    -1,   106,
      -1,    -1,    -1,   110,    -1,    -1,   113,   114,    -1,   116,
     117,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      33,    -1,    -1,    36,    -1,    38,    -1,    -1,    41,    -1,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,    -1,
      63,    64,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    87,    88,    -1,    90,    91,    92,
      93,    94,    95,    96,    -1,    -1,    99,   100,    -1,   102,
     103,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,    -1,
     113,   114,    -1,   116,   117,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      73,    -1,    75,    76,    -1,    78,    79,    -1,    -1,    82,
      -1,    -1,    -1,     8,     9,    10,    11,    90,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    -1,   120,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    73,    -1,
      75,    76,    -1,    78,    79,    -1,    -1,    82,    -1,    -1,
      -1,     8,     9,    10,    11,    90,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,   111,    -1,    35,    -1,
      -1,    -1,    -1,    40,    -1,   120,   121,    -1,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    -1,    25,    26,    64,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    72,    73,    -1,    75,    76,
      40,    78,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,     9,    10,    11,   104,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,   120,   121,    30,    -1,    32,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
     120,   121,    -1,    68,    -1,    -1,    -1,    72,    73,    -1,
      75,    76,    -1,    78,    79,    -1,    -1,    82,    -1,    -1,
      -1,     8,     9,    10,    11,    90,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    40,    -1,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    72,    73,    -1,    75,    76,
      -1,    78,    79,    -1,    -1,    82,    -1,    -1,    -1,     8,
       9,    10,    11,    90,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    72,    73,    -1,    75,    76,    -1,    78,
      79,    -1,    -1,    82,    -1,    -1,    -1,     8,     9,    10,
      11,    90,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,   120,   121,    -1,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    64,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    73,    -1,    75,    76,    40,    78,    79,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,   104,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,   120,
     121,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,   120,   121,    -1,    68,
      -1,    -1,    -1,    72,    73,    -1,    75,    76,    -1,    78,
      79,    -1,    -1,    82,    -1,    -1,    -1,     8,     9,    10,
      11,    90,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,   120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    72,    73,    -1,    75,    76,    -1,    78,    79,    -1,
      -1,    82,    -1,    -1,    -1,     8,     9,    10,    11,    90,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,   120,
     121,    -1,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      26,    64,    -1,    -1,    -1,    68,    -1,    -1,    -1,    72,
      73,    -1,    75,    76,    40,    78,    79,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    55,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    20,    21,    22,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    -1,    55,    19,    20,
      21,    22,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,
      -1,    33,   120,   121,    36,    -1,    38,    -1,    -1,    41,
      42,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    51,
      -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    -1,    70,   120,
     121,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    87,    88,    -1,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    99,   100,    -1,
     102,   103,    -1,    -1,   106,    -1,    -1,    -1,   110,    -1,
      -1,   113,   114,    -1,   116,   117,    27,    28,    29,    -1,
      -1,    -1,    33,    -1,    -1,    36,    -1,    38,    -1,    -1,
      41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
      51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    70,
      -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    87,    88,    -1,    90,
      91,    92,    93,    94,    95,    96,    -1,    -1,    99,   100,
      -1,   102,   103,    -1,    -1,   106,    -1,    -1,    -1,   110,
      -1,    -1,   113,   114,    -1,   116,   117,    27,    28,    29,
      -1,    -1,    -1,    33,    -1,    -1,    36,    -1,    38,    -1,
      -1,    41,    -1,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    -1,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    87,    88,    -1,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    99,
     100,    -1,   102,   103,    -1,    -1,   106,    -1,    -1,    -1,
     110,    -1,    -1,   113,   114,    -1,   116,   117,    27,    28,
      29,    -1,    -1,    -1,    33,    -1,    -1,    36,    -1,    38,
      -1,    -1,    41,    -1,    -1,    44,    45,    46,    -1,    -1,
      49,    -1,    51,    -1,    -1,    54,    -1,    -1,    57,    -1,
      59,    60,    -1,    -1,    63,    64,    -1,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    87,    88,
      -1,    90,    91,    92,    93,    94,    95,    96,    -1,    -1,
      99,   100,    -1,   102,   103,    -1,    -1,   106,    -1,    -1,
      -1,   110,    -1,    -1,   113,   114,    -1,   116,   117
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    43,   123,   124,   154,   156,   178,   102,   103,   107,
     110,   149,   157,     0,     7,   101,    69,   101,    65,   147,
     147,   147,    78,    27,    28,    29,    33,    36,    38,    41,
      44,    45,    46,    49,    51,    54,    57,    59,    60,    63,
      64,    66,    67,    70,    74,    75,    76,    77,    83,    84,
      85,    87,    88,    90,    91,    92,    93,    94,    95,    96,
      99,   100,   102,   103,   106,   110,   113,   114,   116,   117,
     126,   127,   128,   151,   151,   151,    56,     5,     5,   109,
      81,     3,    32,   102,   126,   128,   128,   126,   128,    44,
      45,    46,    65,   116,   126,   127,   129,   167,   168,    97,
     146,     3,   155,     3,   128,   132,   133,   162,   166,     6,
     177,     3,     4,     8,     9,    12,    37,    38,    44,    45,
      46,    58,    78,    80,    87,   105,   115,   116,   118,   119,
     125,   126,   127,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   144,   145,   145,   152,   153,     3,   128,    42,
     165,   169,   167,   169,   175,   176,     4,   137,   145,   145,
     145,   111,   142,   145,     3,   145,     3,     3,     5,     4,
       6,     8,     9,    10,    11,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    30,
      35,    40,    64,    68,    72,    73,    75,    76,    78,    79,
      82,    90,   120,   121,    33,    51,   148,     4,     6,     8,
       9,   115,   130,   131,   116,   126,    39,    40,    47,    63,
      78,    80,    86,    89,   107,   164,   166,    39,    61,    86,
     107,     6,   175,   100,   113,   158,   159,   160,     4,   145,
      53,    54,   111,   142,   145,    27,    57,    66,    94,     4,
      10,    52,   137,   126,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   126,   145,     3,   126,   128,
      52,    78,   145,   145,   145,    35,    64,    68,    75,    76,
      80,    90,   145,   145,   145,   145,   112,   150,   152,   115,
     115,     4,     6,     3,   126,     3,    65,   125,   126,   127,
     130,    29,    80,    74,   128,    81,   161,    32,     3,    74,
      74,     3,   175,    95,     6,   158,   104,   145,   145,    53,
      54,    32,     6,     6,     4,     6,     4,   137,     4,     5,
      31,    55,     4,   137,   146,     3,     5,    62,    52,    55,
      55,   145,   145,     3,   126,   128,   145,   145,   145,    55,
     145,   131,   145,   145,   161,   148,     3,   171,    41,     3,
     145,     3,     3,   153,   158,   145,    54,   104,   145,   133,
     116,   116,   116,     4,   126,   145,   145,     4,     4,   137,
     126,   128,   145,    62,   145,   145,    31,    55,     4,   137,
     146,     3,     5,    55,    55,    55,   145,     4,     4,     4,
     161,   129,   170,    48,    76,    78,    81,   172,   173,   174,
      27,    57,    66,    91,    94,   145,     4,   170,   153,     4,
     145,    54,     4,     4,     4,     4,     4,     3,   145,   145,
     145,     4,     4,   137,   126,   128,   145,   145,   145,    34,
       4,     6,    70,   126,    48,    50,    71,   108,    48,    78,
     172,     4,     4,     4,    34,   161,     4,   137,     4,     3,
     129,    49,    67,    70,    36,    77,    92,    98,    36,    77,
      92,    98,    36,    77,    92,    98,    70,    48,    99,   110,
     163,    89,   161,     4,     4,     4,   137,    49,    67,    28,
      47,    80,    28,    47,    80,    28,    47,    80,    49,    67,
      70,   128,   161,     4,    49,    67,   171,   174
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   122,   123,   123,   124,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   138,   138,
     138,   138,   139,   139,   139,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   142,   142,   143,   143,   143,   143,   144,
     144,   144,   144,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   146,   147,   147,   148,   148,   148,   149,   149,   150,
     150,   151,   151,   151,   152,   153,   153,   154,   155,   155,
     155,   156,   157,   157,   157,   158,   158,   159,   159,   159,
     160,   160,   161,   161,   161,   161,   161,   161,   162,   162,
     163,   163,   163,   164,   164,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   166,   167,   168,   168,   169,   169,   169,   170,   170,
     171,   171,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   175,   175,   175,   175,   175,   176,
     176,   176,   177,   177,   178,   178
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     2,     1,     4,
       6,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     6,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     5,     5,
       5,     5,     6,     6,     6,     6,     1,     3,     4,     5,
       3,     4,     2,     2,     3,     5,     6,     4,     5,     5,
       5,     3,     7,     8,     6,     5,     6,     6,     6,     4,
       8,     9,     7,     4,     5,     6,     4,     5,     3,     4,
       6,     6,     6,     1,     1,     1,     5,     3,     1,     1,
       1,     1,     3,     6,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     0,     1,     1,     0,     1,     0,
       2,     3,     3,     1,     2,     1,     3,    11,     0,     2,
       3,     8,     0,     1,     1,     2,     1,     1,     3,     2,
       0,     1,     0,     3,     3,     3,     3,     3,     0,     1,
       0,     1,     1,     0,     2,     5,     6,     4,     2,     3,
       5,     3,     3,     3,     3,     3,     5,     3,     5,     7,
       0,     2,     2,     2,     4,     0,     2,     2,     1,     3,
       0,     3,     4,     4,     3,     3,     4,     4,     4,     3,
       3,     4,     4,     4,     3,     3,     4,     2,     1,     2,
       0,     1,     4,     4,     2,     5,     5,     3,     3,     3,
       1,     4,     4,     2,     7,     8,     6,     5,    10,     1,
       3,     2,     0,     2,     7,    10
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"(\"", "\")\"",
  "\".\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"~\"",
  "\"&\"", "\"%\"", "\"|\"", "\"||\"", "\"=\"", "\"==\"", "\">\"",
  "\">=\"", "\"<\"", "\"<=\"", "\"!=\"", "\"<>\"", "\"<<\"", "\">>\"",
  "\"ABORT\"", "\"ACTION\"", "\"ALWAYS\"", "\"AND\"", "\"AND BETWEEN\"",
  "\"AS\"", "\"ASC\"", "\"AUTOINCREMENT\"", "\"BETWEEN\"", "\"CASCADE\"",
  "\"CASE\"", "\"CAST\"", "\"CHECK\"", "\"COLLATE\"", "\"CONFLICT\"",
  "\"CONSTRAINT\"", "\"CREATE\"", "\"CURRENT_DATE\"", "\"CURRENT_TIME\"",
  "\"CURRENT_TIMESTAMP\"", "\"DEFAULT\"", "\"DEFERRABLE\"", "\"DEFERRED\"",
  "\"DELETE\"", "\"DESC\"", "\"DISTINCT\"", "\"ELSE\"", "\"END\"",
  "\"ESCAPE\"", "\"EXISTS\"", "\"FAIL\"", "\"FALSE\"", "\"FILTER\"",
  "\"FOLLOWING\"", "\"FOREIGN\"", "\"FROM\"", "\"GENERATED\"", "\"GLOB\"",
  "\"IF\"", "\"IGNORE\"", "\"IMMEDIATE\"", "\"IN\"", "\"INDEX\"",
  "\"INITIALLY\"", "\"INSERT\"", "\"IS\"", "\"ISNULL\"", "\"KEY\"",
  "\"LIKE\"", "\"MATCH\"", "\"NO\"", "\"NOT\"", "\"NOTNULL\"", "\"NULL\"",
  "\"ON\"", "\"OR\"", "\"OVER\"", "\"PARTITION\"", "\"PRECEDING\"",
  "\"PRIMARY\"", "\"RAISE\"", "\"RANGE\"", "\"REFERENCES\"", "\"REGEXP\"",
  "\"REPLACE\"", "\"RESTRICT\"", "\"RETURNING\"", "\"ROLLBACK\"",
  "\"ROWID\"", "\"ROWS\"", "\"SELECT\"", "\"SET\"", "\"STORED\"",
  "\"STRICT\"", "\"TABLE\"", "\"TEMP\"", "\"TEMPORARY\"", "\"THEN\"",
  "\"TRUE\"", "\"UNBOUNDED\"", "\"UNIQUE\"", "\"UPDATE\"", "\"USING\"",
  "\"VIRTUAL\"", "\"WHEN\"", "\"WHERE\"", "\"WITHOUT\"", "\"identifier\"",
  "\"numeric\"", "\"string literal\"", "\"quoted literal\"",
  "\"blob literal\"", "\"bind parameter\"", "\"->\"", "\"->>\"", "$accept",
  "sql", "statement", "literalvalue", "id",
  "allowed_keywords_as_identifier", "tableid", "columnid", "signednumber",
  "signednumber_or_numeric", "typename_namelist", "type_name",
  "unary_expr", "binary_expr", "like_expr", "exprlist_expr",
  "function_expr", "isnull_expr", "between_expr", "in_expr",
  "whenthenlist_expr", "case_expr", "raise_expr", "expr", "select_stmt",
  "optional_if_not_exists", "optional_sort_order", "optional_unique",
  "optional_where", "tableid_with_uninteresting_schema", "indexed_column",
  "indexed_column_list", "createindex_stmt",
  "optional_exprlist_with_paren", "createvirtualtable_stmt",
  "optional_temporary", "tableoption", "tableoptions_list",
  "optional_tableoptions_list", "optional_conflictclause",
  "optional_typename", "optional_storage_identifier",
  "optional_always_generated", "columnconstraint", "columnconstraint_list",
  "columndef", "columndef_list", "optional_constraintname",
  "columnid_list", "optional_columnid_with_paren_list", "fk_clause_part",
  "fk_clause_part_list", "optional_fk_clause", "tableconstraint",
  "tableconstraint_list", "optional_tableconstraint_list",
  "createtable_stmt", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   273,   273,   274,   278,   279,   280,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   300,   301,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   350,
     351,   352,   353,   354,   355,   359,   360,   361,   362,   363,
     364,   365,   369,   370,   374,   375,   379,   380,   384,   385,
     386,   390,   391,   392,   393,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   444,   445,   449,   450,
     451,   452,   456,   457,   458,   462,   463,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   486,   487,   491,   492,   493,   494,   498,
     499,   500,   501,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   531,   539,   540,   544,   545,   546,   554,   555,   559,
     560,   564,   565,   566,   570,   587,   588,   592,   607,   608,
     609,   613,   625,   626,   627,   631,   632,   636,   637,   638,
     642,   643,   647,   648,   649,   650,   651,   652,   656,   657,
     661,   662,   663,   667,   668,   672,   678,   685,   691,   693,
     699,   704,   709,   714,   719,   725,   730,   735,   740,   748,
     769,   770,   783,   787,   788,   792,   793,   794,   798,   799,
     803,   804,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   827,   828,
     832,   833,   834,   835,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   849,   855,   862,   869,   874,   882,
     883,   884,   888,   889,   893,   897
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 10 "sqlite3_parser.yy"
} } //  sqlb::parser 
#line 4900 "sqlite3_parser.cpp"

#line 918 "sqlite3_parser.yy"


void sqlb::parser::parser::error(const location_type& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}
