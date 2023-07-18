//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_MYSQL_STATEMENT_H
#define ROSETTA_MYSQL_STATEMENT_H
#include "common/sql_statement.h"
#include <unordered_map>
#include <mysql/mysql.h>
namespace rosetta {

  class mysql_connection;
  class mysql_result;
  class mysql_statement : public sql_statement{
  public:
    mysql_statement(mysql_connection& connection, const std::string& sql, MYSQL_STMT* statement);
    std::shared_ptr<sql_result> execute() override;
    void bind_param(rosetta::core::sql_value value) override;

//    void bind_param(std::uint32_t param_id, rosetta::string data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::integer data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::boolean data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::timestamp data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::long_double data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::unsigned_integer data) override;

    ~mysql_statement();
  private:
      std::shared_ptr<MYSQL_STMT> statement_;
      std::vector<MYSQL_BIND> bind_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_STATEMENT_H
