#include "common/sql/support/builder.h"

namespace rosetta{

//
//    builder::builder() {}
//
//    void builder::compile_update_(std::unordered_map<std::string, core::sql_value_variant> &data) {
//        std::stringstream ss;
////        ss << "UPDATE " << tables_[0] << " SET ";
////        bool first = true;
////        for(auto& column : data){
////            if(!first)
////                ss << ",";
////            else first = false;
////            ss << column.first << " = " << prepared_parameter_();
////        }
////        ss << " WHERE ";
////        first = true;
////        for(auto& column : data){
////            if(!first)
////                ss << " AND ";
////            else first = false;
////            ss << column.first << " = " << prepared_parameter_();
////        }
//    }
//
//    std::string builder::compile_insert_() {
//        if(tables_.empty())
//            throw std::runtime_error("No table specified");
//        std::stringstream values;
//        std::stringstream ss;
//
//        ss << "INSERT INTO " << tables_[0].table << " (";
//        bool first = true;
//        for(auto& column : data){
//            if(!first)
//            {
//                ss << ",";
//                values << ",";
//            }
//            else first = false;
//            ss << column.first;
//            values << prepared_parameter_();
//        }
//        ss << ") VALUES (" << values.str() << ")";
//        return ss.str();
//    }
//
//    std::string builder::prepared_parameter_() {
//        return "?";
//    }
//
//    std::string builder::compile_wheres_() {
//        return "";
//    }
//
//    builder& builder::insert(const std::string &table) {
//
//        tables_.insert(tables_.begin(), {table, ""});
//        return *this;
//    }
//
//    builder &builder::update(const std::unordered_map<sahara::string, core::sql_value_variant> &columns) {
//        std::stringstream ss;
////        ss << "UPDATE " << tables_[0] << " SET ";
////        bool first = true;
////        for(auto& column : columns){
////            if(!first)
////                ss << ",";
////            else first = false;
////            ss << column.first << " = " << prepared_parameter_();
////        }
////        ss << " WHERE ";
////        first = true;
////        for(auto& column : columns){
////            if(!first)
////                ss << " AND ";
////            else first = false;
////            ss << column.first << " = " << prepared_parameter_();
////        }
//        return *this;
//    }
//
//    builder &builder::from(std::vector<core::sql_query_table> tables) {
//        tables_.swap(tables);
//        return *this;
//    }
//
//    builder &builder::select(std::vector<core::sql_query_column> columns) {
//        return *this;
//    }
//
//    builder &builder::del(std::vector<core::sql_query_table> tables) {
//        tables_.swap(tables);
//        return *this;
//    }
}