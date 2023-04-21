//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_STATEMENT_H
#define ROSETTA_SQL_STATEMENT_H
#include <variant>
#include <unordered_map>
#include <chrono>
#include "sql_statement_base.h"
namespace rosetta {
  class database_connection_base;
  class sql_statement : public sql_statement_base{
  public:
    sql_statement(database_connection_base& connection, std::string_view sql): sql_statement_base(sql), connection_(connection){}


  protected:
    database_connection_base& connection_;
  };

} // rosetta

#endif //ROSETTA_SQL_STATEMENT_H
