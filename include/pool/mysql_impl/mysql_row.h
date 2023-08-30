//
// Created by Hackman.Lo on 7/20/2023.
//

#ifndef ROSETTA_MYSQL_ROW_H
#define ROSETTA_MYSQL_ROW_H

#include <mysql/mysql.h>

#include <utility>
#include "../sql_row.h"
namespace rosetta {

    struct mysql_cell_data{
        mysql_cell_data(std::shared_ptr<unsigned char> data, unsigned long length, bool is_null) : data_(std::move(data)), length_(std::make_shared<unsigned long>(length)), is_null_(std::make_shared<bool>(is_null)) {}
        std::shared_ptr<unsigned char> data_;
        std::shared_ptr<unsigned long> length_;
        std::shared_ptr<bool> is_null_;
    };

    class mysql_row : public sql_row{
    public:
        mysql_row(std::vector<MYSQL_BIND> bind, std::vector<mysql_cell_data> meta);

        virtual ~mysql_row();

        size_t column_count() override;

        core::sql_param_value get_column(std::size_t column) override;

        sahara::string to_json() override;
    protected:
        std::vector<MYSQL_BIND> bind_;
        std::vector<mysql_cell_data> meta_;
    };



} // rosetta

#endif //ROSETTA_MYSQL_ROW_H
