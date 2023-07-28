//
// Created by Hackman.Lo on 7/28/2023.
//
#include "builder/core/where_condition.h"
namespace rosetta::core{
    std::string where_condition::compile() {
        return column_ + " " + operator_ + " " + value_;
    }
}