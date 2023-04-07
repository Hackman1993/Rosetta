#include <iostream>
#include "common/sql_result.h"
#include "common/sql_row.h"
#include "boost/algorithm/string.hpp"
namespace rosetta {
  std::unique_ptr<sql_row> sql_result::get_row(std::uint32_t row) {
    if(row < 0 || row > count()-1) return nullptr;
    return std::make_unique<sql_row>(*this, row);
  }

  std::string sql_result::to_json() {
    std::stringstream sstream;
    sstream << "[";
    bool first_row = true;
    for(int i =0; i< count(); i++){
      if(first_row) first_row = false;
      else sstream << ",";
      sstream << get_row(i)->to_json();
    }
    sstream << "]";
    return sstream.str();
  }
}