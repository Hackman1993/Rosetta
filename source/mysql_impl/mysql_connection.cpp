#include "pool/mysql_impl/mysql_connection.h"
#include "pool/mysql_impl/mysql_statement.h"
#include <sahara/exception/database_exception.h>
#include <sstream>
#include <mysql/mysql.h>
#include <sahara/log/log.h>

namespace rosetta {

    mysql_connection::~mysql_connection() {
    }

    std::shared_ptr<mysql_statement> mysql_connection::prepared_statement(const std::string &sql) {
        MYSQL_STMT *statement = mysql_stmt_init(connection_.get());
        if(!statement) return nullptr;

        if(mysql_stmt_prepare(statement, sql.data(), sql.length()))
            throw sahara::exception::database_exception(mysql_stmt_error(statement), mysql_stmt_errno(statement));
        return std::make_shared<mysql_statement>(*this, sql, statement);
    }

    mysql_connection::mysql_connection(const std::string &host, unsigned short port, const std::string &username, const std::string &password, const std::string &database) : database_connection(host, port, username, password, database) {
        MYSQL *connection = mysql_init(nullptr);
        if (!connection){
            throw sahara::exception::database_exception("Connection Initialize Failed", 5100);
        }
        connection = mysql_real_connect(connection, host_, username_, password_, database_, port_, nullptr, 0);
        if (!connection){
            throw sahara::exception::database_exception(mysql_error(connection), 5100);
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
        if (mysql_commit(connection_.get()))
            throw sahara::exception::database_exception("Commit Transaction Failed", mysql_errno(connection_.get()));
    }

    void mysql_connection::refresh() {
        try {
            if(auto val = mysql_more_results(connection_.get())){
                if(val == 1){
                    mysql_next_result(connection_.get());
                }
            }
            if (mysql_query(connection_.get(), "select 1")) {
                throw sahara::exception::database_exception(mysql_error(connection_.get()), mysql_errno(connection_.get()));
            } else {
                MYSQL_RES* res = mysql_store_result(connection_.get());
                mysql_free_result(res);
                last_active_ = std::chrono::steady_clock::now();
            }
        } catch (std::exception &e) {
            LOG_MODULE_DEBUG("rosetta", "{}", e.what());
        }
    }

    void mysql_connection::close() {
        mysql_close(connection_.get());
    }
}