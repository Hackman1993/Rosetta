//
// Created by Hackman.Lo on 7/28/2023.
//
#include "builder/core/where_in.h"
#include <sstream>
namespace rosetta::core{
    std::string where_in_::compile() {
        if(!values_count_)
            return "";
        std::stringstream ss;
        ss << column_ << " IN (";
        for(auto i = 0; i < values_count_; i++){
            if(i != 0)
                ss << ",";
            ss  << "?";
        }
        ss << ") ";
        return ss.str();
    }
}