//
// Created by Hackman.Lo on 7/28/2023.
//

#include "builder/core/where_groups.h"
#include <sstream>
namespace rosetta::core {
    std::string where_groups::compile() {
        std::stringstream ss;

        if (!groups_.empty()) {

            for (auto &where_group: groups_) {
                ss << (where_group.is_or_? "OR ":"WHERE ");
                ss << where_group.compile();
            }
        }
        return ss.str();
    }

    where_group &where_groups::emplace(bool is_or) {
        return groups_.emplace_back(is_or);
    }

    bool where_groups::empty() {
        return groups_.empty();
    }
} // core