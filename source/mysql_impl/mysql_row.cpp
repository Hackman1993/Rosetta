//
// Created by Hackman.Lo on 7/20/2023.
//

#include "mysql_impl/mysql_row.h"

namespace rosetta {
    size_t mysql_row::column_count() {
        return 0;
    }

    sahara::string mysql_row::to_json() {
        return sahara::string();
    }

    mysql_row::mysql_row(std::vector<MYSQL_BIND> bind, std::vector<mysql_cell_data> meta): bind_(std::move(bind)), meta_(std::move(meta)){

    }

    core::sql_param_value mysql_row::get_column(std::size_t column) {
        if(column >= bind_.size())
            throw std::out_of_range("column out of range");
        core::sql_param_value value = nullptr;
        if(meta_[column].is_null_)
            return value;
        switch(bind_[column].buffer_type)
        {
            case MYSQL_TYPE_LONG:
            case MYSQL_TYPE_INT24:
            case MYSQL_TYPE_SHORT:
            case MYSQL_TYPE_LONGLONG:
                value = *(unsigned long long *)meta_[column].data_.get();
                break;
            case MYSQL_TYPE_BLOB:
                value = std::string((const char*)meta_[column].data_.get(), strlen((const char*)meta_[column].data_.get()));
                break;
            case MYSQL_TYPE_STRING:
                value = std::string((const char*)meta_[column].data_.get(), strlen((const char*)meta_[column].data_.get()));
                break;
            case MYSQL_TYPE_VAR_STRING:
                value = std::string((const char*)meta_[column].data_.get(), strlen((const char*)meta_[column].data_.get()));
                break;
            case MYSQL_TYPE_TIMESTAMP:
                auto *time= (MYSQL_TIME *)meta_[column].data_.get();
                sahara::string str = sahara::string::static_format("{:04d}-{:02d}-{:02d} {:02d}:{:02d}:{:02d}.{}", time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
                sahara::time::timestamp ts = sahara::time::timestamp::from_string(str);
                value = ts;
                break;
//            case MYSQL_TYPE_DECIMAL:
//                break;
//            case MYSQL_TYPE_TINY:
//                break;
//            case MYSQL_TYPE_FLOAT:
//                break;
//            case MYSQL_TYPE_DOUBLE:
//                break;
//            case MYSQL_TYPE_NULL:
//                break;
//            case MYSQL_TYPE_DATE:
//                break;
//            case MYSQL_TYPE_TIME:
//                break;
//            case MYSQL_TYPE_DATETIME:
//                break;
//            case MYSQL_TYPE_YEAR:
//                break;
//            case MYSQL_TYPE_NEWDATE:
//                break;
//            case MYSQL_TYPE_VARCHAR:
//                break;
//            case MYSQL_TYPE_BIT:
//                break;
//            case MYSQL_TYPE_TIMESTAMP2:
//                break;
//            case MYSQL_TYPE_DATETIME2:
//                break;
//            case MYSQL_TYPE_TIME2:
//                break;
//            case MYSQL_TYPE_TYPED_ARRAY:
//                break;
//            case MYSQL_TYPE_INVALID:
//                break;
//            case MYSQL_TYPE_BOOL:
//                break;
//            case MYSQL_TYPE_JSON:
//                break;
//            case MYSQL_TYPE_NEWDECIMAL:
//                break;
//            case MYSQL_TYPE_ENUM:
//                break;
//            case MYSQL_TYPE_SET:
//                break;
//            case MYSQL_TYPE_TINY_BLOB:
//                break;
//            case MYSQL_TYPE_MEDIUM_BLOB:
//                break;
//            case MYSQL_TYPE_LONG_BLOB:
//                break;
//            case MYSQL_TYPE_GEOMETRY:
//                break;
        }

        return value;
    }

} // rosetta