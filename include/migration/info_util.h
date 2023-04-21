//
// Created by Hackman.Lo on 4/21/2023.
//

#ifndef ROSETTA_INFO_UTIL_H
#define ROSETTA_INFO_UTIL_H

#include <string_view>
#include <types/nullable.h>
#include <string/string.h>
#include "field_info.h"

namespace rosetta {
    namespace migration {
        class table;
        class field_info;
        class info_util {
        public:
            virtual bool table_exists(std::string_view name) = 0;
            virtual sahara::types::nullable<table> table_info(std::string_view name) = 0;
            virtual bool create_table(std::string_view name, std::string_view comment, std::string_view encoding) = 0;

            virtual bool field_exists(std::string_view name) = 0;
            virtual sahara::string get_field_sql(field_info &field) const = 0;
            virtual field_info get_field_info(std::string_view name) = 0;
        };

    } // rosetta
} // migration

#endif //ROSETTA_INFO_UTIL_H
