//
// Created by Hackman.Lo on 7/19/2023.
//

#ifndef ROSETTA_BIND_VISITOR_H
#define ROSETTA_BIND_VISITOR_H

#include <mysql/mysql.h>
#include "common/sql/support/sql_value.h"
#include <iostream>

namespace rosetta {

    struct bind_visitor {
        std::vector<core::sql_param_value> values_;

        MYSQL_BIND operator()(std::int64_t value) {
            MYSQL_BIND bind = {nullptr};
            core::sql_param_value &val = values_.emplace_back(value);
            bind.buffer_type = MYSQL_TYPE_LONGLONG;
            bind.buffer = (void *) &std::get<std::int64_t>(val);
            bind.buffer_length = sizeof(std::int64_t);
            return bind;
        }

        MYSQL_BIND operator()(bool value) {
            MYSQL_BIND bind = {nullptr};
            core::sql_param_value &val = values_.emplace_back(value);
            bind.buffer_type = MYSQL_TYPE_BIT;
            bind.buffer = (void *) &std::get<bool>(val);
            bind.buffer_length = sizeof(bool);
            return bind;
        }

        MYSQL_BIND operator()(long double value) {
            MYSQL_BIND bind = {nullptr};
            core::sql_param_value &val = values_.emplace_back(value);
            bind.buffer_type = MYSQL_TYPE_DOUBLE;
            bind.buffer = (void *) &std::get<long double>(val);
            bind.buffer_length = sizeof(long double);
            return bind;
        }

        MYSQL_BIND operator()(std::string value) {
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = MYSQL_TYPE_STRING;
            core::sql_param_value &val = values_.emplace_back(value);
            bind.buffer_length = value.length();
            auto& v = std::get<std::string>(val);
            bind.buffer = (void *) v.data();
            return bind;
        }

        MYSQL_BIND operator()(std::uint64_t value) {
            core::sql_param_value &val = values_.emplace_back(value);
            MYSQL_BIND bind = {nullptr};
            bind.is_unsigned = true;
            bind.buffer_type = MYSQL_TYPE_LONGLONG;
            bind.buffer = (void *) &std::get<std::uint64_t>(val);
            bind.buffer_length = sizeof(std::uint64_t);
            return bind;
        }

        MYSQL_BIND operator()(sahara::time::timestamp value) {
            MYSQL_BIND bind = {nullptr};
            bind.buffer_type = MYSQL_TYPE_VARCHAR;
            core::sql_param_value &val = values_.emplace_back(value.to_string().to_std());
            auto &v = std::get<std::string>(val);
            bind.buffer_length = v.length();
            bind.buffer = (void *) v.data();
            return bind;
        }
    };

} // rosetta

#endif //ROSETTA_BIND_VISITOR_H
