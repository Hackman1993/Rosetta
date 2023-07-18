//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_RESULT_H
#define ROSETTA_SQL_RESULT_H

#include <string>
#include <type_traits>
#include <memory>
#include <sahara/string/string.h>

namespace rosetta {
    class sql_row;

    class sql_result : std::enable_shared_from_this<sql_result> {
    public:
        explicit sql_result(std::size_t affected_rows) : affected_rows_(affected_rows) {};

        [[nodiscard]] std::size_t affected_rows() const { return affected_rows_; };

        virtual std::size_t count() = 0;

        virtual std::size_t column_count() = 0;

        virtual std::size_t column_index(const sahara::string &column) = 0;

        virtual sahara::string column_name(std::size_t column) = 0;

        virtual sahara::string column_type(const sahara::string &column) = 0;

        virtual sahara::string column_type(std::size_t column) = 0;

        virtual std::unique_ptr<sql_row> get_row(std::uint32_t row);

        sahara::string to_json();

    protected:
//    virtual boolean get_boolean(std::uint32_t row, std::size_t col) = 0;
//    virtual long_double get_double(std::uint32_t row, std::size_t col) = 0;
//    virtual string get_string(std::uint32_t row, std::size_t col) = 0;
//    virtual integer get_integer(std::uint32_t row, std::size_t col) = 0;
//    virtual unsigned_integer get_unsigned_integer(std::uint32_t row, std::size_t col) = 0;

        std::size_t affected_rows_;
    };

} // rosetta

#endif //ROSETTA_SQL_RESULT_H
