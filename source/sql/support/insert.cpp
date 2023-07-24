//
// Created by Hackman.Lo on 7/17/2023.
//

#include <utility>
#include <sstream>
#include "common/sql/support/insert.h"

namespace rosetta::core {
    insert::insert(std::string table) : use_table(std::move(table)) {}

    insert &insert::columns(const std::vector<std::string> &columns) {
        columns_ = columns;
        return *this;
    }

    std::string insert::compile() {
        std::stringstream ss;
        std::stringstream values;
        if(table_.name_.empty())
            throw std::runtime_error("table name is empty");
        ss << "INSERT INTO " << table_.name_ << " (";
        bool first = true;
        if(columns_.empty())
            throw std::runtime_error("columns is empty");
        for(auto &column: columns_){
            if(!first) {
                ss << ",";
                values << ",";
            }
            else first = false;
            ss << column;
            values << "?";
        }
        ss << ") VALUES (" << values.str() << ")";
        return ss.str();
    }
} // core