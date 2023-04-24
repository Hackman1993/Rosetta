#include <iostream>
#include "common/sql_result.h"
#include "common/sql_row.h"
#include <string>
#include <sstream>
namespace rosetta {
  std::unique_ptr<sql_row> sql_result::get_row(std::uint32_t row) {
    if(row < 0 || row > count()-1) return nullptr;
    return std::make_unique<sql_row>(*this, row);
  }

    sahara::string sql_result::to_json() {
    std::stringstream sstream;
    sstream << "[";
    bool first_row = true;
    for(int i =0; i< count(); i++){
      if(first_row) first_row = false;
      else sstream << ",";
      sstream << get_row(i)->to_json().to_std();
    }
    sstream << "]";
    return sstream.str();
  }
}