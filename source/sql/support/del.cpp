//
// Created by Hackman.Lo on 7/17/2023.
//

#include <sstream>
#include "builder/del.h"

namespace rosetta::core {
    std::string del::compile() {
        std::stringstream ss;
        std::stringstream values;
        ss << "DELETE FROM " << table_.name_ << " ";

        if(!wheres_.empty()){
            ss << "WHERE " << wheres_.compile();
        }
        return ss.str();
    }
} // core