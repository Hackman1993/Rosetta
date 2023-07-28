//
// Created by Hackman.Lo on 7/17/2023.
//

#include <sstream>
#include <utility>
#include "builder/join.h"

namespace rosetta::core {
    std::string joins::compile() {
        std::stringstream ss;
        switch (type_) {
            case JOIN_TYPE_INNER:
                ss << "INNER JOIN ";
                break;
            case JOIN_TYPE_FULL:
                ss << "FULL JOIN ";
                break;
            case JOIN_TYPE_LEFT:
                ss << "LEFT JOIN ";
                break;
            case JOIN_TYPE_RIGHT:
                ss << "RIGHT JOIN ";
                break;
        }
        ss << table_.name_ << (table_.alias_.empty()? " ":" AS " + table_.alias_ + " ");
        if(!ons_.empty()){
            ss << "ON " << ons_.compile();
        }
        return ss.str();
    }

    joins::joins(alia table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback) : use_table(std::move(table)), type_(type), callback_(callback) {
        if(callback_) callback_(*this);
    }

    joins::joins(const std::string &table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback) : use_table(table), type_(type), callback_(callback) {

    }

} // core