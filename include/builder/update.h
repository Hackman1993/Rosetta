//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_UPDATE_H
#define ROSETTA_UPDATE_H

#include <vector>
#include "builder.h"
#include "use/use_table.h"
#include "use/use_where.h"

namespace rosetta::core {

    class update : public sql_base , public use_table, public use_where<update> {
    public:
        std::string compile() override;
        update(std::string table);
        update& set(const std::vector<std::string>& columns);

    protected:
        std::vector<std::string> columns_;
    };

} // core

#endif //ROSETTA_UPDATE_H
