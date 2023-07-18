//
// Created by Hackman.Lo on 7/18/2023.
//

#ifndef ROSETTA_SQL_VALUE_H
#define ROSETTA_SQL_VALUE_H

#include <sahara/types/nullable.h>

namespace rosetta::core {

    using long_double = sahara::types::nullable<long double>;
    using boolean = sahara::types::nullable<bool>;
    using integer = sahara::types::nullable<std::int64_t>;
    using string = sahara::types::nullable<std::string>;
    using unsigned_integer = sahara::types::nullable<std::uint64_t>;
    using timestamp = sahara::types::nullable<sahara::time::timestamp>;

    using sql_value = std::variant<long_double, boolean, integer, string, unsigned_integer, timestamp>;

} // core

#endif //ROSETTA_SQL_VALUE_H
