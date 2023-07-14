//
// Created by Hackman.Lo on 7/13/2023.
//

#ifndef ROSETTA_QUERY_BUILDER_H
#define ROSETTA_QUERY_BUILDER_H
#include <utility>
#include <boost/algorithm/string.hpp>
#include "types.h"
namespace rosetta {


    class query_builder {
    public:
        query_builder();

        query_builder& from(const std::vector<sahara::string>& tables);
        query_builder& select(const std::vector<sahara::string>& columns);
        query_builder& update(const std::unordered_map<sahara::string, sql_value_variant>& columns);
        query_builder& del(const std::unordered_map<sahara::string, sahara::string>& columns);
        std::string insert(const std::unordered_map<sahara::string, sql_value_variant>& columns, const std::string& table);
    protected:
        std::string compile_insert_(const std::unordered_map<sahara::string, sql_value_variant>& data, const std::string& table);

        void compile_update_(std::unordered_map<std::string, sql_value_variant>& data){
            std::stringstream ss;
            ss << "UPDATE " << tables_[0] << " SET ";
            bool first = true;
            for(auto& column : data){
                if(!first)
                    ss << ",";
                else first = false;
                ss << column.first << " = " << prepared_parameter_();
            }
            ss << " WHERE ";
            first = true;
            for(auto& column : data){
                if(!first)
                    ss << " AND ";
                else first = false;
                ss << column.first << " = " << prepared_parameter_();
            }
        }

        virtual std::string prepared_parameter_(){
            return "?";
        }

        virtual std::string compile_wheres_(){
            return "";
        }

        ACTION_TYPE action_type_ = AT_UNSET;
        std::vector<sahara::string> tables_;
        std::vector<std::string> select_columns_;
        std::vector<std::string> where_group_;

    };

} // rosetta

#endif //ROSETTA_QUERY_BUILDER_H
