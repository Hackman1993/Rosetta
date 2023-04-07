#include "common/sql_row.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

namespace rosetta{
  std::string sql_row::to_json() {
    std::stringstream sstream;
    sstream << "{";
    bool first_column = true;
    for(int i = 0; i < column_count(); i++){
      if(first_column) first_column = false;
      else sstream << ",";

      sstream << "\"" << column_name(i) << "\":";
      std::string type = column_type(i);
      if(
          boost::iequals(type,"varchar")||
          boost::iequals(type,"char")||
          boost::iequals(type, "timestamp")||
          boost::iequals(type, "datetime")
          ) sstream << get<rosetta::sql_string>(i).json_value();
      else if(
          boost::iequals(type,"tinyint") ||
          boost::iequals(type,"int")
          ) sstream << get<rosetta::sql_string>(i).json_value();
      else{
        std::cout << "Unhandled Sql Type:" << type << std::endl;
        sstream << "null";
      }
    }
    sstream << "}";
    return sstream.str();
  }
}