////
//// Created by Hackman.Lo on 3/23/2023.
////
//
//#include "mysql_impl/mysql_statement.h"
//
//#include <utility>
//#include <iostream>
//#include "mysql_impl/mysql_connection.h"
//#include "mysql_impl/mysql_result.h"
////#include "exception/database_exception.h"
//#include "common/sql_statement.h"
//
//#include <boost/algorithm/string.hpp>
//
//namespace rosetta {
//  mysql_statement::mysql_statement(mysql_connection &connection, const sahara::string& sql): sql_statement(connection, sql) {
////    if(connection_.mysql_ == nullptr)
////      throw exceptions::database_exception(100003, "Session Not Connected!");
////    stmt_ = mysql_stmt_init(connection_.mysql_);
////    if(stmt_ == nullptr) return;
////    auto error_code = mysql_stmt_prepare(stmt_, statement_.c_str(), statement_.length());
////    if(error_code != 0)
////      throw exceptions::database_exception(error_code, mysql_stmt_error(stmt_));
//  }
//
//  mysql_statement::~mysql_statement() {
//
//  }
//
//  std::shared_ptr<sql_result> mysql_statement::execute() {
//    if(sql_.istart_with("select")){
//      auto result = statement_->executeQuery();
//      return std::make_unique<mysql_result>(0, result);
//    }else {
//      auto result = statement_->executeUpdate();
//      return std::make_unique<mysql_result>(result, nullptr);
//    }
//
//  }
//
//  void mysql_statement::bind_param(std::uint32_t param_id, rosetta::string data) {
//    if(data.is_null())  return statement_->setNull(param_id+1, 0);
//    auto str = std::get<sahara::string>(data);
//
//    // TODO:: Fix
//    //statement_->setString(param_id+1, str);
//  }
//
//  void mysql_statement::bind_param(std::uint32_t param_id, rosetta::integer data) {
//    if(data.is_null())  return statement_->setNull(param_id+1, 0);
//    statement_->setInt64(param_id+1, std::get<int64_t>(data));
//  }
//
//  void mysql_statement::bind_param(std::uint32_t param_id, rosetta::boolean data) {
//    if(data.is_null())  return statement_->setNull(param_id+1, 0);
//    statement_->setBoolean(param_id+1, std::get<bool>(data));
//  }
//
//  void mysql_statement::bind_param(std::uint32_t param_id, rosetta::timestamp data) {
//    if(data.is_null())  return statement_->setNull(param_id+1, 0);
//    statement_->setDateTime(param_id+1, std::get<sahara::time::timestamp>(data).to_string().to_std());
//  }
//
//  void mysql_statement::bind_param(std::uint32_t param_id, rosetta::long_double data) {
//    if(data.is_null())  return statement_->setNull(param_id+1, 0);
//    statement_->setDouble(param_id+1, (double)std::get<long double>(data));
//  }
//
//  void mysql_statement::bind_param(std::uint32_t param_id, rosetta::unsigned_integer data) {
//    if(data.is_null())  return statement_->setNull(param_id+1, 0);
//    statement_->setUInt64(param_id+1, std::get<std::uint64_t>(data));
//  }
//} // rosetta

#include "mysql_impl/mysql_statement.h"
#include "mysql_impl/mysql_connection.h"
#include "mysql_impl/mysql_result.h"
#include <iostream>
namespace rosetta{


    mysql_statement::mysql_statement(mysql_connection& connection, const std::string &sql, MYSQL_STMT* statement): sql_statement(connection, sql) {
        statement_ = std::shared_ptr<MYSQL_STMT>(statement, [&](MYSQL_STMT* stmt){
            std::cout << "MYSQL_STMT_CLOSE" << std::endl;
            mysql_stmt_close(stmt);
        });
    }

    mysql_statement::~mysql_statement() {
        std::cout << "MYSQL_STMT_FREE_RESULT" << std::endl;
        mysql_stmt_free_result(statement_.get());

    }

    void mysql_statement::execute() {
        std::cout << "MYSQL_STMT_BIND_PARAM" << std::endl;
        if(mysql_stmt_bind_param(statement_.get(), bind_.data()))
            throw std::logic_error(mysql_stmt_error(statement_.get()));
        std::cout << "MYSQL_STMT_EXECUTE" << std::endl;
        if(mysql_stmt_execute(statement_.get())){
            std::cout << mysql_stmt_error(statement_.get()) << std::endl;
            unsigned long long ** v = (unsigned long long **)bind_[0].buffer;
            std::cout << **v <<std::endl;
            throw std::logic_error(mysql_stmt_error(statement_.get()));
        }
        visitor_.values_.clear();
        bind_.clear();
    }

    void mysql_statement::bind_param(rosetta::core::sql_param_value value) {
        auto bind = std::visit(visitor_, value);
        bind_.push_back(bind);
    }

    std::shared_ptr<sql_result> mysql_statement::get() {
        return std::make_shared<mysql_result>(statement_);
    }

    void mysql_statement::reset() {
        if(mysql_stmt_reset(statement_.get())){
            std::cout << mysql_stmt_error(statement_.get()) << std::endl;
        }

    }


}

