//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_INSERT_H
#define ROSETTA_INSERT_H
#include <string>
#include <vector>
#include "support.h"
#include "builder.h"

namespace rosetta::core {

    class insert : public builder, public use_table {
    public:
        insert(std::string table);

        insert& columns(const std::vector<std::string>& columns);

        std::string compile() override;

    protected:
        std::vector<std::string> columns_;
    };

} // core

#endif //ROSETTA_INSERT_H
