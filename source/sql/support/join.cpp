//
// Created by Hackman.Lo on 7/17/2023.
//

#include <sstream>
#include <utility>
#include "common/sql/support/join.h"

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
        ss << table_.name << (table_.alias.empty()? " ":" AS " + table_.alias + " ");
        if(callback_) callback_(*this);
        bool first = true;
        for(auto & on : ons_){
            if(first){
                ss << "ON ";
                first = false;
            }else{
                ss << "AND ";
            }
            ss << on->compile();
        }
        return ss.str();
    }

    joins::joins(alia table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback) : use_table(std::move(table)), type_(type), callback_(callback) {

    }

    joins::joins(const std::string &table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback) : use_table(table), type_(type), callback_(callback) {

    }

    joins &joins::on(const std::string &column, const std::string &operate, const std::string &value) {
        ons_.emplace_back(std::make_shared<condition>(column, operate, value));
        return *this;
    }

} // core