//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_SQL_VALUE_H
#define ROSETTA_SQL_VALUE_H
#include <string>
#include <variant>
#include <sahara/time/timestamp.h>
namespace rosetta::core {
    using sql_param_value = std::variant<nullptr_t, double, bool, std::int64_t, std::string, std::uint64_t , sahara::time::timestamp>;
} // core

#endif //ROSETTA_SQL_VALUE_H
