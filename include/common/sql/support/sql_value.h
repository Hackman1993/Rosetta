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
    using string = sahara::types::nullable<sahara::string>;
    using unsigned_integer = sahara::types::nullable<std::uint64_t>;
    using timestamp = sahara::types::nullable<sahara::time::timestamp>;

    using sql_value = std::variant<std::reference_wrapper<long_double>, std::reference_wrapper<boolean>, std::reference_wrapper<integer>,
            std::reference_wrapper<string>, std::reference_wrapper<unsigned_integer>, std::reference_wrapper<timestamp>>;

    using sql_param_value = std::variant<long double, bool, std::int64_t, std::string, std::uint64_t , timestamp, nullptr_t>;

} // core

#endif //ROSETTA_SQL_VALUE_H
