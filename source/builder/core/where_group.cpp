//
// Created by Hackman.Lo on 7/28/2023.
//

#include "builder/core/where_in.h"
#include "builder/core/where_group.h"
#include "builder/core/where_condition.h"
#include <stdexcept>
#include <sstream>
namespace rosetta::core {
    void where_group::where(const std::string &column, const std::string &operate, const std::string &value) {
        conditions_.emplace_back(std::make_shared<where_condition>(column, operate, value));
    }

    void where_group::or_(const std::string &column, const std::string &operate, const std::string &value) {
        conditions_.emplace_back(std::make_shared<where_condition>(column, operate, value, true));
    }

    std::string where_group::compile() {
        std::stringstream ss;
        bool first = true;
        if(conditions_.size() > 1)
            ss << "(";
        // The first condition only will be where, so we don't have to worry about the first condition is or_.
        for(auto &where : conditions_){
            if(first){
                first = false;
            }else{
                ss << (is_or_ ? "OR " : "AND ");
            }
            ss << where->compile();
        }
        if(conditions_.size() > 1)
            ss << ")";
        ss << " ";
        return ss.str();
    }

    void where_group::where_in(const std::string &column, std::uint32_t count) {
        conditions_.emplace_back(std::make_shared<where_in_>(column, count, false));
    }
} // core