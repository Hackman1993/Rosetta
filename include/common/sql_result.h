//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_RESULT_H
#define ROSETTA_SQL_RESULT_H
#include <string>
namespace rosetta {

  class sql_result {
  public:
    sql_result(std::size_t affected_rows): affected_rows_(affected_rows){};
  protected:
    std::size_t affected_rows_;
  };

} // rosetta

#endif //ROSETTA_SQL_RESULT_H
