//
// Created by Hackman.Lo on 4/4/2023.
//

#ifndef ROSETTA_SQL_ROW_H
#define ROSETTA_SQL_ROW_H
#include <string>
#include <utility>
#include "sql_result.h"
namespace rosetta {
  class sql_row {
  public:
    sql_row(sql_result& result, std::uint32_t row) : result_(result), row_(row){};


    template <typename ResultType>
    ResultType get(std::string col_name){
      return result_.template get<ResultType>(row_ ,col_name);
    }

    template <typename ResultType>
    ResultType get(std::uint32_t col_name){
      return result_.template get<ResultType>(row_ ,col_name);
    }

    std::size_t column_count(){
      return result_.column_count();
    }

    std::string column_name(std::uint32_t column) {
      return result_.column_name(column);
    }

    std::string column_type(std::uint32_t column) {
      return result_.column_type(column);
    }

    std::string to_json();


  protected:
    sql_result& result_;
    std::uint32_t row_;
  };

} // rosetta

#endif //ROSETTA_SQL_ROW_H
