//
// Created by Hackman.Lo on 4/21/2023.
//

#include "migration/mysql_impl/mysql_info_util.h"

namespace rosetta {
    namespace migration {
        bool mysql_info_util::table_exists(const sahara::string& name) {
            return false;
        }

//        sahara::types::nullable<table> mysql_info_util::table_info(std::string_view name) {
//            return sahara::types::nullable<table>();
//        }

        bool mysql_info_util::create_table(const sahara::string& name, const sahara::string& comment, const sahara::string& encoding) {
            return false;
        }

        bool mysql_info_util::field_exists(const sahara::string& name) {
            return false;
        }

        sahara::string mysql_info_util::get_field_sql(field_info &field) const {
            return sahara::string();
        }

        field_info mysql_info_util::get_field_info(const sahara::string& name) {
            return field_info();
        }
    } // rosetta
} // migration