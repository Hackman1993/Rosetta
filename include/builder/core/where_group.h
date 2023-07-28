//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_WHERE_GROUP_H
#define ROSETTA_WHERE_GROUP_H
#include <string>
#include <vector>
#include <memory>
#include "condition_base.h"

namespace rosetta::core {

    class where_group : public condition_base{
    public:
        where_group(bool is_or = true) : condition_base(is_or) {}

        void where(const std::string &column, const std::string &operate, const std::string &value);
        void where_in(const std::string &column, std::uint32_t count);

        void or_(const std::string &column, const std::string &operate, const std::string &value);


        std::string compile();

    protected:
        std::vector <std::shared_ptr<condition_base>> conditions_;
    };

} // core

#endif //ROSETTA_WHERE_GROUP_H
