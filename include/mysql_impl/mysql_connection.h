//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_MYSQL_CONNECTION_H
#define ROSETTA_MYSQL_CONNECTION_H
#include "../common/database_connection.h"
#include <utility>
struct MYSQL;
namespace rosetta {

  class mysql_statement;
  class mysql_connection : public database_connection<mysql_statement>{
  public:
    mysql_connection(const std::string& host, unsigned short port, const std::string& username, const std::string& password, const std::string& database);

    void refresh() override;
    void begin_transaction() override;
    void commit_transaction() override;

    std::shared_ptr<mysql_statement> prepared_statement(const std::string& sql) override;

    void close() override;

    ~mysql_connection() override;


  protected:
    std::shared_ptr<MYSQL> connection_;
    std::shared_ptr<mysql_statement> statement_;
    bool connected_ = false;
    friend class mysql_statement;
  };

} // rosetta

#endif //ROSETTA_MYSQL_CONNECTION_H
