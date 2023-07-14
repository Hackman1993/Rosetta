//
// Created by Hackman.Lo on 4/21/2023.
//

#ifndef ROSETTA_MYSQL_INFO_UTIL_H
#define ROSETTA_MYSQL_INFO_UTIL_H
#include "migration/info_util.h"
namespace rosetta {
    namespace migration {

        class mysql_info_util : public info_util{
        public:
            bool table_exists(const sahara::string& name) override;

            //sahara::types::nullable<table> table_info(std::string_view name) override;

            bool create_table(const sahara::string& name, const sahara::string& comment, const sahara::string& encoding) override;

            bool field_exists(const sahara::string& name) override;

            sahara::string get_field_sql(field_info &field) const override;

            field_info get_field_info(const sahara::string& name) override;
        };

    } // rosetta
} // migration

#endif //ROSETTA_MYSQL_INFO_UTIL_H
