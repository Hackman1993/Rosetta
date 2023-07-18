//
// Created by Hackman.Lo on 3/24/2023.
//

#ifndef ROSETTA_MYSQL_RESULT_H
#define ROSETTA_MYSQL_RESULT_H
#include "common/sql_result.h"
#include <string>
#include <mysql/mysql.h>
namespace rosetta {

  class mysql_result : public sql_result{
  public:
    size_t count() override;
      sahara::string column_name(std::size_t column) override;
      sahara::string column_type(std::size_t column) override;
      sahara::string column_type(const sahara::string &column) override;

    size_t column_index(const sahara::string &column) override;
  protected:
    size_t column_count() override;
    void _move_cursor(std::size_t cursor);
    MYSQL_RES* result_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_RESULT_H
