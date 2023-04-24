#include "common/sql_row.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
namespace rosetta{
    sahara::string sql_row::to_json() {
    std::stringstream sstream;
    sstream << "{";
    bool first_column = true;
    for(int i = 0; i < column_count(); i++){
      if(first_column) first_column = false;
      else sstream << ",";

      sstream << "\"" << column_name(i).to_std() << "\":";
        sahara::string type = column_type(i);
      if(
          type.iequals("varchar")||
          type.iequals("char")||
          type.iequals( "timestamp")||
          type.iequals( "datetime")
          ) sstream << get<rosetta::string>(i).json().to_std();
      else if(
          type.iequals("tinyint") ||
          type.iequals("int")
          ) sstream << get<rosetta::string>(i).json().to_std();
      else{
        std::cout << "Unhandled Sql Type:" << type.to_std() << std::endl;
        sstream << "null";
      }
    }
    sstream << "}";
    return sstream.str();
  }
}