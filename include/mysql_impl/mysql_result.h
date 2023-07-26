//
// Created by Hackman.Lo on 3/24/2023.
//

#ifndef ROSETTA_MYSQL_RESULT_H
#define ROSETTA_MYSQL_RESULT_H

#include "common/sql_result.h"
#include <string>
#include <unordered_map>
#include <mysql/mysql.h>

namespace rosetta {

    class mysql_result : public sql_result {
    public:
        mysql_result(std::shared_ptr<MYSQL_STMT>& statement);
        size_t count() override;
        std::shared_ptr<sql_row> next() override;
        virtual ~mysql_result();

    public:
        sahara::string column_name(std::size_t column) override;

        size_t affected_rows() override;

        sahara::string column_type(std::size_t column) override;

        sahara::string column_type(const sahara::string &column) override;

        size_t column_index(const sahara::string &column) override;

    protected:
        size_t column_count() override;

        std::shared_ptr<MYSQL_STMT>& statement_;
        std::unordered_map<std::string, std::uint16_t> columns_;
        MYSQL_RES *column_meta_;
        std::shared_ptr<std::uint64_t> row_count_ = nullptr;
    };

} // rosetta

#endif //ROSETTA_MYSQL_RESULT_H
