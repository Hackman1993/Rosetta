#include <boost/polymorphic_cast.hpp>
#include "mysql_impl/mysql_connection.h"
#include "mysql_impl/mysql_statement.h"
#include <sahara/exception/database_exception.h>
#include <sstream>
#include <mysql/mysql.h>

namespace rosetta {

    mysql_connection::~mysql_connection() {
        std::cout << "Connection Closing" << std::endl;
    }

    std::shared_ptr<sql_statement_base> mysql_connection::prepared_statement(const std::string &sql) {
        MYSQL_STMT *statement = mysql_stmt_init(connection_.get());
        if(!statement) return nullptr;
        if(int ret = mysql_stmt_prepare(statement, sql.data(), sql.length()))
            throw sahara::exception::database_exception(5101, std::format("Statement Prepare Failed with error:{}", mysql_stmt_error(statement)));
        return std::make_shared<mysql_statement>(*this, sql, statement);
    }

    mysql_connection::mysql_connection(const std::string &host, unsigned short port, const std::string &username, const std::string &password, const std::string &database) : database_connection(host, port, username, password, database) {
        MYSQL *connection = mysql_init(nullptr);
        if (!connection)
            throw sahara::exception::database_exception(5100, "Connection Initialize Failed");
        connection = mysql_real_connect(connection, host_, username_, password_, database_, port_, nullptr, 0);
        if (!connection) {
            std::string message = std::format("Connection Failed to {}:{} with username:{} and password:{} to database:{} with error:{}", host_, port_, username_, password_, database_, mysql_error(connection));
            throw sahara::exception::database_exception(5100, message);
        }

        connection_ = std::shared_ptr<MYSQL>(connection, [](MYSQL *connection) {
            mysql_close(connection);
        });
        connected_ = true;
    }

    void mysql_connection::begin_transaction() {
        mysql_autocommit(connection_.get(), false);
    }

    void mysql_connection::commit_transaction() {
        if (!mysql_commit(connection_.get()))
            throw sahara::exception::database_exception(5102, "Commit Transaction Failed");
    }

    void mysql_connection::refresh() {
        try {
            auto query_result = mysql_query(connection_.get(), "select 1");
            if (query_result) {
                throw sahara::exception::database_exception(5103, "Connection Refresh Failed");
            } else {
                last_active_ = std::chrono::steady_clock::now();
            }
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    void mysql_connection::close() {
        mysql_close(connection_.get());
    }
}