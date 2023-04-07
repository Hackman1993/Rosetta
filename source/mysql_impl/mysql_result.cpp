//
// Created by Hackman.Lo on 3/24/2023.
//

#include "mysql_impl/mysql_result.h"
#include "exception/database_exception.h"
#include "common/sql_row.h"
namespace rosetta {

  mysql_result::mysql_result(std::size_t affected, sql::ResultSet *result) : sql_result(affected), result_(result){
  }

  sql_bool mysql_result::get_boolean(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_bool():sql_bool(result_->getBoolean(column+1));
  }

  sql_long_double mysql_result::get_double(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_long_double():sql_long_double(result_->getDouble(column+1));
  }

  sql_string mysql_result::get_string(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_string():sql_string(result_->getString(column+1));
  }

  sql_int mysql_result::get_int32(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_int():sql_int(result_->getInt(column+1));
  }

  sql_uint mysql_result::get_uint32(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_uint():sql_uint(result_->getUInt(column+1));
  }

  sql_uint64 mysql_result::get_uint64(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_uint64():sql_uint64(result_->getUInt64(column+1));
  }

  sql_int64 mysql_result::get_int64(std::uint32_t row, std::size_t column) {
    _move_cursor(row);
    return result_->isNull(column+1)? sql_int64():sql_int64(result_->getInt64(column+1));
  }

  size_t mysql_result::count() {
    return result_->rowsCount();
  }

  size_t mysql_result::column_count() {
    if(result_ && result_->getMetaData())
      return result_->getMetaData()->getColumnCount();
    return 0;
  }

  void mysql_result::_move_cursor(std::size_t cursor) {
    if(!result_ || (cursor + 1) > result_->rowsCount() )
      throw database_exception(5102, "Row Not Exists!");
    result_->absolute(cursor + 1);
  }

  size_t mysql_result::column_index(const std::string &column) {
    std::cout << result_->findColumn(column) << std::endl;
    return (result_->findColumn(column) - 1);
  }

  std::string mysql_result::column_name(std::size_t column) {
    if(result_) return result_->getMetaData()->getColumnName(column + 1);
    return "";
  }

  std::string mysql_result::column_type(const std::string &column) {
    return result_? result_->getMetaData()->getColumnTypeName(column_index(column)+1):"";
  }

  std::string mysql_result::column_type(std::size_t column) {
    return result_? result_->getMetaData()->getColumnTypeName(column+1):"";
  }
} // rosetta