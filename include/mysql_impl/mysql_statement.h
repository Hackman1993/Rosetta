//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_MYSQL_STATEMENT_H
#define ROSETTA_MYSQL_STATEMENT_H
#include "common/sql_statement.h"
#include <cppconn/prepared_statement.h>
#include <unordered_map>
namespace rosetta {

  class mysql_connection;
  class mysql_result;

  struct statement_deleter{
    void operator()(sql::PreparedStatement* ptr) {
      if(ptr != nullptr) {
        ptr->close();
        delete ptr;
      }
    }
  };
  class mysql_statement : public sql_statement{
  public:
    mysql_statement(mysql_connection& connection, std::string_view sql);
    std::shared_ptr<sql_result> execute() override;

    void bind_param(std::uint32_t param_id, rosetta::string data) override;

    void bind_param(std::uint32_t param_id, rosetta::integer data) override;

    void bind_param(std::uint32_t param_id, rosetta::boolean data) override;

    void bind_param(std::uint32_t param_id, rosetta::timestamp data) override;

    void bind_param(std::uint32_t param_id, rosetta::long_double data) override;

    void bind_param(std::uint32_t param_id, rosetta::unsigned_integer data) override;

    ~mysql_statement();
  private:
    std::unique_ptr<sql::PreparedStatement, statement_deleter> statement_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_STATEMENT_H
