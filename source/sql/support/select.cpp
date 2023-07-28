//
// Created by Hackman.Lo on 7/17/2023.
//

#include <sstream>
#include <utility>
#include "builder/select.h"
namespace rosetta {
    namespace core {
        std::string select::compile() {
            std::stringstream ss;
            ss << "SELECT ";
            if(distinct_)
                ss << "DISTINCT ";
            if(columns_.empty())
                ss << "* ";

            bool first = true;
            for(auto &column : columns_){
                if(first)
                    first = false;
                else ss << ",";

                ss << column.name_ ;
                if(!column.alias_.empty()) ss << " AS " << column.alias_;
            }
            ss << " FROM ";
            if(tables_.empty())
                throw std::logic_error("Tables are empty");

            first = true;
            for(auto &table : tables_){
                if(first)
                    first = false;
                else ss << ",";
                ss << table.name_;
                if(!table.alias_.empty()) ss << " AS " << table.alias_;
                ss << " ";
            }

            if(!joins_.empty()){
                for(auto &join: joins_){
                    ss << join.compile();
                }
            }

            if(!wheres_.empty()){
                ss << wheres_.compile() << " ";
            }

            return ss.str();
        }

//        select &select::where(const std::string &column, const std::string &operate, const std::string &value) {
//
////            auto where_condition = std::make_shared<condition::condition>(column, operate, value);
////            wheres_.emplace_back(where_condition);
//            return *this;
//        }

        select::select(std::initializer_list<std::string> columns) : use_column_alias(columns), use_tables(std::vector<alia>{}){}

        select::select(std::vector<alia> columns) : use_column_alias(std::move(columns)), use_tables(std::vector<alia>{}){}

        select &select::from(std::initializer_list<alia> tables) {
            for(auto &table: tables) tables_.push_back(table);
            return *this;
        }
        select &select::distinct(bool distinct){
            distinct_ = distinct;
            return *this;
        }

    } // rosetta
} // core