//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_STATEMENT_H
#define ROSETTA_SQL_STATEMENT_H
#include <chrono>
#include <variant>
#include <unordered_map>
#include "sql_statement_base.h"
namespace rosetta {
  class database_connection;
  class sql_statement : public sql_statement_base{
  public:
    sql_statement(database_connection& connection, const std::string& sql): sql_statement_base(sql), connection_(connection){}
    virtual ~sql_statement() = default;


  protected:
      database_connection& connection_;
  };

} // rosetta

#endif //ROSETTA_SQL_STATEMENT_H
