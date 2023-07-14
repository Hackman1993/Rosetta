//
// Created by Hackman.Lo on 4/21/2023.
//

#ifndef ROSETTA_INFO_UTIL_H
#define ROSETTA_INFO_UTIL_H

#include <string_view>
#include <sahara/string/string.h>
#include "field_info.h"

namespace rosetta {
    namespace migration {
        class table;
        class field_info;
        class info_util {
        public:
            virtual bool table_exists(const sahara::string& name) = 0;
            //virtual sahara::types::nullable<table> table_info(std::string_view name) = 0;
            virtual bool create_table(const sahara::string& name, const sahara::string& comment, const sahara::string& encoding) = 0;

            virtual bool field_exists(const sahara::string& name) = 0;
            virtual sahara::string get_field_sql(field_info &field) const = 0;
            virtual field_info get_field_info(const sahara::string& name) = 0;
        };

    } // rosetta
} // migration

#endif //ROSETTA_INFO_UTIL_H
