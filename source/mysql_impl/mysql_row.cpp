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

    mysql_row::mysql_row(std::vector<MYSQL_BIND> bind, std::vector<std::shared_ptr<unsigned char>> data, std::vector<unsigned long> length): bind_(std::move(bind)), data_(std::move(data)), length_(length){

    }

    core::sql_param_value mysql_row::get_column(std::size_t column) {
        if(column >= bind_.size())
            throw std::out_of_range("column out of range");
        core::sql_param_value value = nullptr;
        switch(bind_[column].buffer_type)
        {
            case MYSQL_TYPE_BLOB:
                value = std::string((const char*)data_[column].get(), length_[column]);
                break;
            case MYSQL_TYPE_TIMESTAMP:
                MYSQL_TIME *time= (MYSQL_TIME *)data_[column].get();
                sahara::string str = sahara::string::static_format("{:04d}-{:02d}-{:02d} {:02d}:{:02d}:{:02d}.{}", time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
                sahara::time::timestamp ts = sahara::time::timestamp::from_string(str);
                value = ts;
                break;


        }

        return value;
    }

} // rosetta