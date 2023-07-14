//
// Created by Hackman.Lo on 7/13/2023.
//

#include "common/builder/query_builder.h"

namespace rosetta {

    query_builder::query_builder(){}

    std::string query_builder::insert(const std::unordered_map<sahara::string, sql_value_variant>& columns, const std::string& table) {
        if(action_type_!=AT_UNSET)
            throw std::runtime_error("Cannot insert into a query that already has an action type set.");
        action_type_ = AT_INSERT;
        auto data = compile_insert_(columns, table);
        return data;
    }

    query_builder &query_builder::from(const std::vector<sahara::string>& tables) {
        tables_ = tables;
        return *this;
    }

    query_builder &query_builder::select(const std::vector<sahara::string> &columns) {
        if(action_type_!=AT_UNSET)
            throw std::runtime_error("Cannot insert into a query that already has an action type set.");
        action_type_ = AT_SELECT;
        return *this;
    }

    query_builder &query_builder::update(const std::unordered_map<sahara::string, sql_value_variant> &columns) {
        if(action_type_!=AT_UNSET)
            throw std::runtime_error("Cannot insert into a query that already has an action type set.");
        action_type_ = AT_UPDATE;
        return *this;
    }

    query_builder &query_builder::del(const std::unordered_map<sahara::string, sahara::string>& columns) {
        if(action_type_!=AT_UNSET)
            throw std::runtime_error("Cannot insert into a query that already has an action type set.");
        action_type_ = AT_DELETE;
        return *this;
    }

    std::string query_builder::compile_insert_(const std::unordered_map<sahara::string, sql_value_variant> &data, const std::string &table) {
        std::stringstream values;
        std::stringstream ss;
        ss << "INSERT INTO " << table << " (";
        bool first = true;
        for(auto& column : data){
            if(!first)
            {
                ss << ",";
                values << ",";
            }
            else first = false;
            ss << column.first;
            values << prepared_parameter_();
        }
        ss << ") VALUES (" << values.str() << ")";
        return ss.str();
    }


} // rosetta