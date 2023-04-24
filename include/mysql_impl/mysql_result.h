//
// Created by Hackman.Lo on 3/24/2023.
//

#ifndef ROSETTA_MYSQL_RESULT_H
#define ROSETTA_MYSQL_RESULT_H
#include "common/sql_result.h"
#include <string>
#include <cppconn/resultset.h>
namespace rosetta {

  struct result_deleter{
    void operator()(sql::ResultSet* ptr) {
      if(ptr != nullptr) {
        ptr->close();
        delete ptr;
      }
    }
  };

  class mysql_result : public sql_result{
  public:
    mysql_result(std::size_t affected, sql::ResultSet* result);
    size_t count() override;
      sahara::string column_name(std::size_t column) override;
      sahara::string column_type(std::size_t column) override;
      sahara::string column_type(const sahara::string &column) override;

    size_t column_index(const sahara::string &column) override;
  protected:
    string get_string(std::uint32_t row, std::size_t column) override;
    integer get_integer(std::uint32_t row, std::size_t column) override;
    boolean get_boolean(std::uint32_t row, std::size_t column) override;
    long_double get_double(std::uint32_t row, std::size_t column) override;
    unsigned_integer get_unsigned_integer(std::uint32_t row, std::size_t column) override;
  protected:
    size_t column_count() override;
    void _move_cursor(std::size_t cursor);
    std::unique_ptr<sql::ResultSet, result_deleter> result_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_RESULT_H
