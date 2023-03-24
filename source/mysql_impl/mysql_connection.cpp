#include <boost/polymorphic_cast.hpp>
#include "mysql_impl/mysql_connection.h"
#include "mysql_impl/mysql_statement.h"
#include "exception/database_exception.h"

namespace rosetta {
  sql::mysql::MySQL_Driver *mysql_connection::driver_ = nullptr;



  bool mysql_connection::connect() {
//    mysql_ = mysql_init(nullptr);
//    mysql_ = mysql_real_connect(mysql_, host_.c_str(), username_.c_str(), password_.c_str(), database_.c_str(), port_, nullptr, 0);
//    return mysql_ == nullptr;
    return true;
  }

  mysql_connection::~mysql_connection() {
    //mysql_close(mysql_);
  }

  mysql_statement mysql_connection::prepared_statement(std::string_view sql) {
    return mysql_statement(*this, sql);
  }

  mysql_connection::mysql_connection(std::string_view host, unsigned short port, std::string_view database, std::string_view username, std::string_view password): database_connection(host, port, database, username, password) {
    if(driver_ == nullptr)
      driver_ = sql::mysql::get_mysql_driver_instance();

    if(driver_ == nullptr)
      throw database_exception(5100, "No Driver Instance Found!");
    std::stringstream sstream;
    sstream << "tcp://" << host << ":" << port;
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
}