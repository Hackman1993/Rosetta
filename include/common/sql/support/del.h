//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_DEL_H
#define ROSETTA_DEL_H

#include <utility>

#include "support.h"
#include "builder.h"
#include "update.h"

namespace rosetta::core {

    class del : public builder, public use_table, public use_where{
    public:
        del(std::string table): use_table(std::move(table)){}

        std::string compile() override;
        del& where(const std::string& column, const std::string& operate, const std::string& value);
    };

} // core

#endif //ROSETTA_DEL_H
