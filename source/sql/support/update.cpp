//
// Created by Hackman.Lo on 7/17/2023.
//

#include <sstream>
#include "builder/update.h"

namespace rosetta::core {
    std::string update::compile() {
        std::stringstream ss;
        if (table_.name_.empty())
            throw std::runtime_error("table name is empty");
        ss << "UPDATE " << table_.name_ << " SET ";

        bool first = true;
        for (auto &column: columns_) {
            if (!first)
                ss << ",";
            else first = false;
            ss << column << " = ? ";
        }
        if(!wheres_.empty()){
            ss << "WHERE " << wheres_.compile();
        }
        return ss.str();
    }

    update::update(std::string table): use_table(std::move(table)){

    }

    update &update::set(const std::vector<std::string> &columns) {
        columns_ = columns;
        return *this;
    }
} // core