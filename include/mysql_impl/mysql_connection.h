////
//// Created by Hackman.Lo on 3/23/2023.
////
//
//#ifndef ROSETTA_MYSQL_CONNECTION_H
//#define ROSETTA_MYSQL_CONNECTION_H
//#include "../common/database_connection.h"
//#include <utility>
//struct MYSQL;
//namespace rosetta {
//
//  class mysql_statement;
//  class mysql_connection : public database_connection{
//  public:
//    mysql_connection(const sahara::string& host, unsigned short port, const sahara::string& username, const sahara::string& password, const sahara::string& database);
//    void refresh() override;
//
//    void begin_transaction() override;
//    void commit_transaction() override;
//
//    std::shared_ptr<sql_statement_base> prepared_statement(const sahara::string& sql) override;
//
//    void close() override;
//
//    ~mysql_connection() override;
//
//
//  protected:
//    std::unique_ptr<MYSQL> connection_;
//    bool connected_ = false;
//    friend class mysql_statement;
//  };
//
//} // rosetta
//
//#endif //ROSETTA_MYSQL_CONNECTION_H
