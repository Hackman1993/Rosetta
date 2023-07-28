//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_DEL_H
#define ROSETTA_DEL_H

#include <utility>
#include "builder.h"
#include "update.h"

namespace rosetta::core {

    class del : public sql_base, public use_table, public use_where<del>{
    public:
        del(std::string table): use_table(std::move(table)){}

        std::string compile() override;
    };

} // core

#endif //ROSETTA_DEL_H
