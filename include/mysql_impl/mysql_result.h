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

  public:
    bool get_boolean(std::uint32_t row, const std::string &attr) override;

    long double get_double(std::uint32_t row, const std::string &attr) override;

    std::string get_string(std::uint32_t row, const std::string &attr) override;

    int32_t get_int32(std::uint32_t row, const std::string &attr) override;

    uint32_t get_uint32(std::uint32_t row, const std::string &attr) override;

    int64_t get_uint64(std::uint32_t row, const std::string &attr) override;

    uint64_t get_int64(std::uint32_t row, const std::string &attr) override;

  protected:
    std::unique_ptr<sql::ResultSet> result_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_RESULT_H
