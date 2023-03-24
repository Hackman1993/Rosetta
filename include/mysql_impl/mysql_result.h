//
// Created by Hackman.Lo on 3/24/2023.
//

#ifndef ROSETTA_MYSQL_RESULT_H
#define ROSETTA_MYSQL_RESULT_H
#include "common/sql_result.h"
#include <string>
#include <mysql/jdbc.h>
namespace rosetta {

  class mysql_result : sql_result{
  public:
    mysql_result(std::size_t affected, sql::ResultSet* result);
  protected:

    std::unique_ptr<sql::ResultSet> result_;
  };

} // rosetta

#endif //ROSETTA_MYSQL_RESULT_H
