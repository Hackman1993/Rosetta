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

  template <typename ConnectionType, typename ResultType>
  class sql_statement : public sql_statement_base{
  public:
    sql_statement(ConnectionType& connection, std::string_view sql): sql_statement_base(sql), connection_(connection){}
    virtual ResultType execute() = 0;

  protected:
    ConnectionType& connection_;
  };

} // rosetta

#endif //ROSETTA_SQL_STATEMENT_H
