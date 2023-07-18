//
// Created by Hackman.Lo on 7/17/2023.
//

#include <sstream>
#include "common/sql/support/del.h"

namespace rosetta::core {
    std::string del::compile() {
        std::stringstream ss;
        std::stringstream values;
        ss << "DELETE FROM " << table_.name << " ";
        bool first = true;

        for(auto &where : wheres_){
            if(!first)
                ss << " AND ";
            else {
                first = false;
                ss << "WHERE ";
            }
            ss << where->compile();
        }

        return ss.str();
    }

    del &del::where(const std::string &column, const std::string &operate, const std::string &value) {
        auto where_condition = std::make_shared<condition>(column, operate, value);
        wheres_.emplace_back(where_condition);
        return *this;
    }
} // core