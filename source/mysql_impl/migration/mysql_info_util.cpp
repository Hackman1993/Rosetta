//
// Created by Hackman.Lo on 4/21/2023.
//

#include "mysql_impl/migration/mysql_info_util.h"

namespace rosetta {
    namespace migration {
        bool mysql_info_util::table_exists(std::string_view name) {
            return false;
        }

        sahara::types::nullable<table> mysql_info_util::table_info(std::string_view name) {
            return sahara::types::nullable<table>();
        }

        bool mysql_info_util::create_table(std::string_view name, std::string_view comment, std::string_view encoding) {
            return false;
        }

        bool mysql_info_util::field_exists(std::string_view name) {
            return false;
        }

        sahara::string mysql_info_util::get_field_sql(field_info &field) const {
            return sahara::string();
        }

        field_info mysql_info_util::get_field_info(std::string_view name) {
            return field_info();
        }
    } // rosetta
} // migration