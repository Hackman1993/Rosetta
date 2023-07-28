//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_RESULT_H
#define ROSETTA_SQL_RESULT_H

#include <string>
#include <type_traits>
#include <memory>
#include <sahara/string/string.h>
#include "../core/sql_value.h"
namespace rosetta {
    class sql_row;

    class sql_result : std::enable_shared_from_this<sql_result> {
    public:
        sql_result(){};

        virtual std::size_t affected_rows() = 0;

        virtual std::size_t count() = 0;

        virtual std::size_t column_count() = 0;

        virtual std::size_t column_index(const sahara::string &column) = 0;

        virtual sahara::string column_name(std::size_t column) = 0;

        virtual sahara::string column_type(const sahara::string &column) = 0;

        virtual sahara::string column_type(std::size_t column) = 0;

        virtual std::shared_ptr<sql_row> next() = 0;

        //sahara::string to_json();
    protected:
    };

} // rosetta

#endif //ROSETTA_SQL_RESULT_H
