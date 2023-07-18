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
namespace rosetta{
    struct visitor{
        MYSQL_BIND operator()(const rosetta::core::integer& value){
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = value.is_null()? MYSQL_TYPE_NULL : MYSQL_TYPE_LONGLONG;
            bind.buffer = value.is_null()? nullptr : (void*)&std::get<std::int64_t>(value);
            bind.buffer_length = sizeof(std::int64_t);
            return bind;
        }

        MYSQL_BIND operator()(const rosetta::core::boolean& value){
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = value.is_null()? MYSQL_TYPE_NULL : MYSQL_TYPE_BIT;
            bind.buffer = value.is_null()? nullptr : (void*)&std::get<bool>(value);
            bind.buffer_length = sizeof(bool);
            return bind;
        }

        MYSQL_BIND operator()(const rosetta::core::long_double & value){
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = value.is_null()? MYSQL_TYPE_NULL : MYSQL_TYPE_DOUBLE;
            bind.buffer = value.is_null()? nullptr : (void*)&std::get<long double>(value);
            bind.buffer_length = sizeof(long double);
            return bind;
        }

        MYSQL_BIND operator()(const rosetta::core::string & value){
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = value.is_null()? MYSQL_TYPE_NULL : MYSQL_TYPE_VARCHAR;
            if(!value.is_null()){
                auto& actual_value = std::get<std::string>(value);
                bind.buffer_length = actual_value.length();
                bind.buffer = value.is_null()? nullptr : data;
            }
            return bind;
        }

        MYSQL_BIND operator()(const rosetta::core::unsigned_integer & value){
            MYSQL_BIND bind = {nullptr};
            bind.is_unsigned = true;
            bind.buffer_type = value.is_null()? MYSQL_TYPE_NULL : MYSQL_TYPE_LONGLONG;
            bind.buffer = value.is_null()? nullptr : (void*)&std::get<std::uint64_t>(value);
            bind.buffer_length = sizeof(std::uint64_t);
            return bind;
        }

        MYSQL_BIND operator()(const rosetta::core::timestamp & value){
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = value.is_null()? MYSQL_TYPE_NULL : MYSQL_TYPE_DOUBLE;
            if(!value.is_null()){
                auto actual_value = std::get<sahara::time::timestamp>(value).to_string().to_std();
                bind.buffer_length = actual_value.length();
                bind.buffer = actual_value.data();
            }
            return bind;
        }
    };

    mysql_statement::mysql_statement(mysql_connection& connection, const std::string &sql, MYSQL_STMT* statement): sql_statement(connection, sql) {
        statement_ = std::shared_ptr<MYSQL_STMT>(statement, [](MYSQL_STMT* stmt){
            mysql_stmt_close(stmt);
        });
    }

    mysql_statement::~mysql_statement() {

    }

    std::shared_ptr<sql_result> mysql_statement::execute() {
        auto ret = mysql_stmt_bind_param(statement_.get(), bind_.data());
        auto test2 = mysql_stmt_error(statement_.get());
        auto test = mysql_stmt_execute(statement_.get());

        return nullptr;
    }

    void mysql_statement::bind_param(rosetta::core::sql_value value) {
        auto bind = std::visit(visitor(), value);
        bind_.push_back(bind);
    }

}

