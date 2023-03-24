//
// Created by Hackman.Lo on 3/24/2023.
//

#include "mysql_impl/mysql_result.h"

namespace rosetta {

  mysql_result::mysql_result(std::size_t affected, sql::ResultSet *result) : sql_result(affected), result_(result){

  }
} // rosetta