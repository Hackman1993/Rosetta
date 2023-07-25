//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_CONDITION_H
#define ROSETTA_CONDITION_H
#include <utility>
#include "sql_value.h"
#include "operate_base.h"
namespace rosetta::core {

    class condition : public operate_base{
    public:
        condition(std::string column, std::string operate, std::string value) :
            column_(std::move(column)), operator_(std::move(operate)), value_(std::move(value)) {};
        std::string compile() override;
    protected:
        std::string column_;
        std::string operator_;
        std::string value_;
    };

    class where_in : public operate_base{
    public:
        where_in(std::string column, std::uint32_t count) : column_(std::move(column)), values_count_(count) {};
        std::string compile() override;
    protected:
        std::string column_;
        std::uint32_t values_count_ = 0;
    };

} // core

#endif //ROSETTA_CONDITION_H
