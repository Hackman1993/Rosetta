//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_WHERE_IN_H
#define ROSETTA_WHERE_IN_H
#include <string>
#include "condition_base.h"

namespace rosetta::core {
    class where_in_ : public condition_base{
    public:
        where_in_(std::string column, std::uint32_t count, bool is_or = false) : condition_base(is_or), column_(std::move(column)), values_count_(count) {}

        std::string compile() override;
    protected:
        std::string column_;
        std::uint32_t values_count_ = 0;
    };

} // core

#endif //ROSETTA_WHERE_IN_H
