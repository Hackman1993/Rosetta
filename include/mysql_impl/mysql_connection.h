//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_MYSQL_CONNECTION_H
#define ROSETTA_MYSQL_CONNECTION_H
#include "../common/database_connection.h"
#include <mysql/jdbc.h>
#include <utility>
namespace rosetta {

  class mysql_statement;
  class mysql_connection : public database_connection{
  public:
    mysql_connection(std::string_view host, unsigned short port, std::string_view username, std::string_view password, std::string_view database);
    void refresh() override;

    void begin_transaction() override;
    void commit_transaction() override;

    std::shared_ptr<sql_statement_base> prepared_statement(std::string_view sql) override;

    void close() override;

    ~mysql_connection() override;


  protected:
    static sql::mysql::MySQL_Driver *driver_;
    std::unique_ptr<sql::Connection> connection_;
    friend class mysql_statement;
  };

} // rosetta

#endif //ROSETTA_MYSQL_CONNECTION_H
