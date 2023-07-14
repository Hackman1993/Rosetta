//
// Created by Hackman.Lo on 7/14/2023.
//

#ifndef ROSETTA_OPERATORS_H
#define ROSETTA_OPERATORS_H
#include <string>
#include <utility>
namespace rosetta {

    class sql_operator_base {};

    class sql_comparison: public sql_operator_base{
    public:
        sql_comparison(std::string operator_): operator_(std::move(operator_)) {}
    protected:
        std::string operator_;
    };
} // rosetta

#endif //ROSETTA_OPERATORS_H
