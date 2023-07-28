//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_TABLE_H
#define ROSETTA_USE_TABLE_H
#include <vector>
#include "../core/sql_base.h"
namespace rosetta::core {

    class use_table {
    public:
        explicit use_table(alia table) : table_(std::move(table)) {};

        explicit use_table(std::string table) : table_({std::move(table)}) {};

        use_table(std::string table, std::string alias) : table_({std::move(table), std::move(alias)}) {};

    protected:
        alia table_;
    };

    class use_tables {
    public:
        use_tables(std::vector<std::string> tables);

        use_tables(std::vector<alia> tables);

    protected:
        std::vector<alia> tables_;
    };

} // core

#endif //ROSETTA_USE_TABLE_H
