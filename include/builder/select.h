//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_SELECT_H
#define ROSETTA_SELECT_H

#include "join.h"
#include "builder.h"
#include "use/use_where.h"
#include "use/use_limit.h"
#include "use/use_distinct.h"
#include "use/use_column_alias.h"
#include "use/use_joins.h"
#include "use/use_orderby.h"
namespace rosetta::core {
    class select : public sql_base, public use_tables, public use_limit, public use_distinct,
            public use_column_alias, public use_where<select>, public use_joins<select>, public use_orderby<select>{
    public:
        select(std::initializer_list<std::string> columns);
        select(std::vector<alia> columns);

        select& distinct(bool distinct = true);
        select& from(std::initializer_list<alia> tables);
        std::string compile() override;
    protected:

    };

} // core

#endif //ROSETTA_SELECT_H
