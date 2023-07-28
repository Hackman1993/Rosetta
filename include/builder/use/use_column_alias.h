//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_COLUMN_ALIAS_H
#define ROSETTA_USE_COLUMN_ALIAS_H
#include <vector>
#include "../core/sql_base.h"
namespace rosetta::core {

    class use_column_alias {
    public:
        use_column_alias(std::vector <std::string> columns);

        use_column_alias(std::vector <alia> columns);

    protected:
        std::vector <alia> columns_;
    };

} // core

#endif //ROSETTA_USE_COLUMN_ALIAS_H
