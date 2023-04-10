//
// Created by Hackman.Lo on 3/30/2023.
//

#ifndef ROSETTA_SQL_TYPES_H
#define ROSETTA_SQL_TYPES_H
#include "nullable_types.h"
#include "time/timestamp.h"
namespace rosetta {
  using long_double = sahara::nullable_type<long double>;
  using boolean = sahara::nullable_type<bool>;
  using integer = sahara::nullable_type<std::int64_t>;
  using string = sahara::nullable_type<std::string>;
  using unsigned_integer = sahara::nullable_type<std::uint64_t>;
  using timestamp = sahara::nullable_type<sahara::time::timestamp>;
}

#endif //ROSETTA_SQL_TYPES_H
