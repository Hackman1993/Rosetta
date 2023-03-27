#include <boost/polymorphic_cast.hpp>
#include "mysql_impl/mysql_connection.h"
#include "mysql_impl/mysql_statement.h"
#include "exception/database_exception.h"

namespace rosetta {
  sql::mysql::MySQL_Driver *mysql_connection::driver_ = nullptr;

  mysql_connection::~mysql_connection() {
    std::cout << "Connection Closing" << std::endl;
  }

  mysql_statement mysql_connection::prepared_statement(std::string_view sql) {
    return mysql_statement(*this, sql);
  }

  mysql_connection::mysql_connection(std::string_view host, unsigned short port, std::string_view username, std::string_view password, std::string_view database): database_connection(host, port, username, password, database) {
    if(driver_ == nullptr)
      driver_ = sql::mysql::get_mysql_driver_instance();

    if(driver_ == nullptr)
      throw database_exception(5100, "No Driver Instance Found!");
    std::stringstream sstream;
    sstream << "tcp://" << host_ << ":" << port_;
    try{
      auto conn_ptr = driver_->connect(sstream.str(), username_, password_);
      connection_ = std::unique_ptr<sql::Connection>(conn_ptr);
      auto stmt = connection_->createStatement();
      stmt->execute("use " + database_);
      delete stmt;
    }catch (std::exception& e)
    {
      throw database_exception(5101, "Connection:" + std::string(e.what()));
    }
  }

  void mysql_connection::begin_transaction() {
    connection_->setAutoCommit(false);
  }

  void mysql_connection::commit_transaction() {
    connection_->commit();
  }

  void mysql_connection::refresh() {
    std::cout << "refresh" << std::endl;
  }

  void mysql_connection::close() {
    connection_->close();
  }
}