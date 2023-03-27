//
// Created by Hackman.Lo on 3/24/2023.
//

#include "mysql_impl/mysql_result.h"
#include "exception/database_exception.h"

namespace rosetta {

  mysql_result::mysql_result(std::size_t affected, sql::ResultSet *result) : sql_result(affected), result_(result){
  }

  bool mysql_result::get_boolean(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getBoolean(attr);
  }

  long double mysql_result::get_double(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getDouble(attr);
  }

  std::string mysql_result::get_string(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getString(attr);
  }

  int32_t mysql_result::get_int32(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getInt(attr);
  }

  uint32_t mysql_result::get_uint32(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getUInt(attr);
  }

  int64_t mysql_result::get_uint64(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getInt64(attr);
  }

  uint64_t mysql_result::get_int64(std::uint32_t row, const std::string &attr) {
    if(!result_ || (row + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(row + 1);
    return result_->getUInt64(attr);
  }

  size_t mysql_result::count() {
    return result_->rowsCount();
  }
} // rosetta