#include <boost/polymorphic_cast.hpp>
#include "mysql_impl/mysql_connection.h"
#include "mysql_impl/mysql_statement.h"
#include "exception/database_exception.h"
#include <sstream>

namespace rosetta {
  sql::mysql::MySQL_Driver *mysql_connection::driver_ = nullptr;

  mysql_connection::~mysql_connection() {
    std::cout << "Connection Closing" << std::endl;
  }

  std::shared_ptr<sql_statement_base> mysql_connection::prepared_statement(std::string_view sql) {
    return std::make_shared<mysql_statement>(*this, sql);
  }

  mysql_connection::mysql_connection(const sahara::string& host, unsigned short port, const sahara::string& username, const sahara::string& password, const sahara::string& database): database_connection(host, port, username, password, database) {
    if(driver_ == nullptr)
      driver_ = sql::mysql::get_mysql_driver_instance();

    if(driver_ == nullptr)
      throw sahara::exception::database_exception(5100, "No Driver Instance Found!");
    auto connstr = sahara::string::static_format("tcp://{}:{}", host_, port_);

    try{
      auto conn_ptr = driver_->connect(connstr.to_std(), username_.to_std(), password_.to_std());
      connection_ = std::unique_ptr<sql::Connection>(conn_ptr);
      auto stmt = connection_->createStatement();
      stmt->execute(("use " + database_).to_std());
      delete stmt;
    }catch (std::exception& e)
    {
      throw sahara::exception::database_exception(5101, "Connection:" + std::string(e.what()));
    }
  }

  void mysql_connection::begin_transaction() {
    connection_->setAutoCommit(false);
  }

  void mysql_connection::commit_transaction() {
    connection_->commit();
  }

  void mysql_connection::refresh() {
    try{
      std::shared_ptr<sql::PreparedStatement> stmt(connection_->prepareStatement("select 1"), [](sql::PreparedStatement* pointer){
        pointer->close();
        delete pointer;
      });
      if(stmt->execute())
      {
        last_active_ = std::chrono::steady_clock::now();
      }else{
        // TODO: Handle When Failed To Refresh
      }
    } catch (std::exception& e){
      std::cout << e.what() << std::endl;
    }
  }

  void mysql_connection::close() {
    connection_->close();
  }
}