//
// Created by Hackman.Lo on 4/4/2023.
//

#ifndef ROSETTA_SQL_ROW_H
#define ROSETTA_SQL_ROW_H

#include <string>
#include <utility>
#include "sql_result.h"
#include <sahara/string/string.h>

namespace rosetta {
    class sql_row {
    public:
        virtual ~sql_row() = default;

        virtual std::size_t column_count() = 0;

        virtual sahara::string to_json() = 0;

        virtual rosetta::core::sql_param_value get_column(std::size_t column) = 0;

    };

} // rosetta

#endif //ROSETTA_SQL_ROW_H
