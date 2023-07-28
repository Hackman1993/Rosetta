//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_WHERE_CONDITION_H
#define ROSETTA_WHERE_CONDITION_H
#include <string>
#include "condition_base.h"
namespace rosetta::core {

    class where_condition : public condition_base {
    public:
        where_condition(std::string column, std::string operator_, std::string value, bool is_or = false) : condition_base(is_or), column_(std::move(column)), operator_(std::move(operator_)), value_(std::move(value)) {};

        std::string compile() override;
        std::string column_;
        std::string operator_;
        std::string value_;
    };

} // core

#endif //ROSETTA_WHERE_CONDITION_H
