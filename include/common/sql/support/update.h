//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_UPDATE_H
#define ROSETTA_UPDATE_H

#include <vector>
#include "builder.h"
#include "support.h"

namespace rosetta::core {

    class update : public builder , public use_table, public use_where {
    public:
        std::string compile() override;
        update(std::string table);
        update& set(const std::vector<std::string>& columns);
        update& where(const std::string& column, const std::string& operate, const std::string& value);

    protected:
        std::vector<std::string> columns_;
    };

} // core

#endif //ROSETTA_UPDATE_H
