//
// Created by Hackman.Lo on 7/28/2023.
//
#include "builder/core/limit.h"

namespace rosetta::core{
    std::string limit::compile() {
        return "LIMIT " + std::to_string(limit_) + " ";
    }
}