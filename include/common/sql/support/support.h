//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_SUPPORT_H
#define ROSETTA_SUPPORT_H
#include <string>
#include <memory>
#include <vector>
#include "operate_base.h"
#include "condition.h"

namespace rosetta::core {
    class use_table{
    public:
        use_table(alia table) : table_(table){};
        use_table(std::string table) : table_({std::move(table)}){};
        use_table(std::string table, std::string alias) : table_({std::move(table), std::move(alias)}){};
    protected:
        alia table_;
    };

    class use_tables{
    public:
        use_tables(std::vector<std::string> tables);
        use_tables(std::vector<alia> tables);
    protected:
        std::vector<alia> tables_;
    };


    class use_where{
    protected:
        std::vector<std::shared_ptr<operate_base>> wheres_;
    };

    class use_on{
    protected:
        std::vector<std::shared_ptr<operate_base>> ons_;
    };

    class use_distinct{
    protected:
        bool distinct_ = false;
    };

    class use_limit{
    protected:
        std::shared_ptr<limit> limit_;
    };

    class use_column_alias{
    public:
        use_column_alias(std::vector<std::string> columns);
        use_column_alias(std::vector<alia> columns);
    protected:
        std::vector<alia> columns_;
    };
} // core

#endif //ROSETTA_SUPPORT_H
