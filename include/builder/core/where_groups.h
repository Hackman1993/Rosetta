//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_WHERE_GROUPS_H
#define ROSETTA_WHERE_GROUPS_H

#include "where_group.h"

namespace rosetta::core {

    class where_groups : public sql_base{
    public:
        std::string compile() override;
        where_group& emplace(bool is_or);

        bool empty();

        std::vector<where_group> groups_;
    };

} // core

#endif //ROSETTA_WHERE_GROUPS_H
