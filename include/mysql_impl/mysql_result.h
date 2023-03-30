//
// Created by Hackman.Lo on 3/24/2023.
//

#ifndef ROSETTA_MYSQL_RESULT_H
#define ROSETTA_MYSQL_RESULT_H
#include "common/sql_result.h"
#include <string>
#include <mysql/jdbc.h>
namespace rosetta {

  class mysql_result : public sql_result{
  public:
    mysql_result(std::size_t affected, sql::ResultSet* result);
    size_t count() override;
    std::string column_name(std::size_t column) override;

    std::string column_type(const std::string &column) override;

    std::string column_type(std::size_t column) override;
    size_t column_index(const std::string &column) override;
  protected:
    sql_bool get_boolean(std::uint32_t row, std::size_t column) override;

    sql_long_double get_double(std::uint32_t row, std::size_t column) override;

    sql_string get_string(std::uint32_t row, std::size_t column) override;

    sql_int get_int32(std::uint32_t row, std::size_t column) override;

    sql_uint get_uint32(std::uint32_t row, std::size_t column) override;

    sql_uint64 get_uint64(std::uint32_t row, std::size_t column) override;

    sql_int64 get_int64(std::uint32_t row, std::size_t column) override;

  protected:
    size_t column_count() override;

  protected:
  public:


  protected:
    void _move_cursor(std::size_t cursor);
    std::unique_ptr<sql::ResultSet> result_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_RESULT_H
