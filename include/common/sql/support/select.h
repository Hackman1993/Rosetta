//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_SELECT_H
#define ROSETTA_SELECT_H

#include "builder.h"
#include "support.h"
#include "join.h"

namespace rosetta::core {

    class select : public builder, public use_where, public use_tables, public use_limit, public use_distinct, public use_column_alias{
    public:
        select(std::initializer_list<std::string> columns);
        select(std::vector<alia> columns);

        select& distinct(bool distinct = true);
        select& from(std::initializer_list<alia> tables);
        std::string compile() override;
        select& where(const std::string& column, const std::string& operate, const std::string& value);
        select& where_in(const std::string& column, std::uint32_t value);

        select& inner_join(const alia& table, const std::function<void (joins&)>& callback);
        select& left_join(const alia& table, const std::function<void (joins&)>& callback);
    protected:
        std::vector<joins> joins_;
    };

} // core

#endif //ROSETTA_SELECT_H
