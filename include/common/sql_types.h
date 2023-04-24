//
// Created by Hackman.Lo on 3/30/2023.
//

#ifndef ROSETTA_SQL_TYPES_H
#define ROSETTA_SQL_TYPES_H

#include "types/nullable.h"
#include "time/timestamp.h"
#include <string/string.h>

namespace rosetta {
  using long_double = sahara::types::nullable<long double>;
  using boolean = sahara::types::nullable<bool>;
  using integer = sahara::types::nullable<std::int64_t>;
  using string = sahara::types::nullable<sahara::string>;

  using unsigned_integer = sahara::types::nullable<std::uint64_t>;
  using timestamp = sahara::types::nullable<sahara::time::timestamp>;

  using sql_varint_value = std::variant<long_double, boolean, integer, string, unsigned_integer, timestamp>;
}

#endif //ROSETTA_SQL_TYPES_H
