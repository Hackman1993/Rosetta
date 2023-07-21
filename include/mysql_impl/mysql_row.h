//
// Created by Hackman.Lo on 7/20/2023.
//

#ifndef ROSETTA_MYSQL_ROW_H
#define ROSETTA_MYSQL_ROW_H

#include <mysql/mysql.h>
#include "../common/sql_row.h"
namespace rosetta {

    class mysql_row : public sql_row{
    public:
        mysql_row(std::vector<MYSQL_BIND> bind, std::vector<std::shared_ptr<unsigned char>> data, std::vector<unsigned long> length);

        ~mysql_row() override = default;

        size_t column_count() override;

        core::sql_param_value get_column(std::size_t column) override;

        sahara::string to_json() override;
    protected:
        std::vector<MYSQL_BIND> bind_;
        std::vector<std::shared_ptr<unsigned char>> data_;
        std::vector<unsigned long> length_;
    };

} // rosetta

#endif //ROSETTA_MYSQL_ROW_H
