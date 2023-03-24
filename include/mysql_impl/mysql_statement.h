//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_MYSQL_STATEMENT_H
#define ROSETTA_MYSQL_STATEMENT_H
#include "common/sql_statement.h"
#include <mysql/jdbc.h>
#include <unordered_map>
namespace rosetta {

  class mysql_connection;
  class mysql_result;
  class mysql_statement : public sql_statement<mysql_connection, mysql_result>{
  public:
    mysql_statement(mysql_connection& connection, std::string_view sql);

    void bind_param(std::string_view type, std::string_view data) override;

    void bind_param(std::string_view type, uint64_t data) override;
    void bind_param(std::string_view type, int64_t data);

    mysql_result execute() override;

    ~mysql_statement();
  private:
    std::unique_ptr<sql::PreparedStatement> statement_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_STATEMENT_H
