//#include <boost/polymorphic_cast.hpp>
//#include "mysql_impl/mysql_connection.h"
//#include "mysql_impl/mysql_statement.h"
//#include <sahara/exception/database_exception.h>
//#include <sstream>
//#include <mysql/mysql.h>
//namespace rosetta {
//
//    mysql_connection::~mysql_connection() {
//        std::cout << "Connection Closing" << std::endl;
//    }
//
//    std::shared_ptr<sql_statement_base> mysql_connection::prepared_statement(const sahara::string &sql) {
//        //return std::make_shared<mysql_statement>(*this, sql);
//        return nullptr;
//    }
//
//    mysql_connection::mysql_connection(const sahara::string &host, unsigned short port, const sahara::string &username, const sahara::string &password, const sahara::string &database) : database_connection(host, port, username, password, database) {
//        mysql_init(connection_.get());
//        try {
//            mysql_real_connect(connection_.get(), host_, username_, password_, database_, port_, nullptr, 0);
//        } catch (std::exception &e) {
//            throw sahara::exception::database_exception(5101, "Connection:" + std::string(e.what()));
//        }
//    }
//
//    void mysql_connection::begin_transaction() {
//        mysql_autocommit(connection_.get(), false);
//    }
//
//    void mysql_connection::commit_transaction() {
//        if(!mysql_commit(connection_.get()))
//            throw sahara::exception::database_exception(5102, "Commit Transaction Failed");
//    }
//
//    void mysql_connection::refresh() {
//        try {
//            auto query_result = mysql_query(connection_.get(), "select 1");
//            if (query_result != 0) {
//                throw sahara::exception::database_exception(5103, "Connection Refresh Failed");
//            } else {
//                last_active_ = std::chrono::steady_clock::now();
//            }
//        } catch (std::exception &e) {
//            std::cout << e.what() << std::endl;
//        }
//    }
//
//    void mysql_connection::close() {
//        mysql_close(connection_.get());
//    }
//}