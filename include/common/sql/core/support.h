//
// Created by Hackman.Lo on 7/14/2023.
//

#ifndef ROSETTA_SUPPORT_H
#define ROSETTA_SUPPORT_H
#include "builder_base.h"
#include "grammar_base.h"
#include <sahara/types/nullable.h>
#include <sahara/string/string.h>
namespace rosetta::core {

    class sql_object{
    public:
        virtual sahara::string to_sql() const = 0;
    protected:
        sql_object() = default;
    };

    template <typename BaseType>
    class sql_value : public sql_object, public sahara::types::nullable<BaseType>{
    public:
        sql_value<BaseType>& operator = (const BaseType& value){
            *this = value;
            return *this;
        }
        sql_value<BaseType>& operator = (BaseType value){
            *this = value;
            return *this;
        }
        sql_value(const BaseType& value, std::string prefix = "", std::string suffix = "") : sahara::types::nullable<BaseType>(value), prefix_(std::move(prefix)), suffix_(std::move(suffix)){};
        sahara::string to_sql() const override{
            std::string data = this->is_null()? std::string("NULL"):std::to_string(std::get<BaseType>(*this));
            if(this->is_null())
                return data;
            return prefix_ + data + suffix_;
        }
    protected:
        std::string prefix_;
        std::string suffix_;
    };

    class sql_int: public sql_value<std::int32_t>{
    public:
        sql_int(std::int32_t value) : sql_value(value, "", ""){};
    };

    class sql_bool: public sql_value<bool>{
    public:
        sql_bool(bool value) : sql_value(value, "", ""){};
    };

    class sql_double: public sql_value<double>{
    public:
        sql_double(double value): sql_value(value, "", ""){};
    };

    class sql_date: public sql_value<sahara::time::timestamp>{
    public:
        sql_date(sahara::time::timestamp& value): sql_value(value, "'", "'"){};
    };
    class sql_timestamp: public sql_value<sahara::time::timestamp>{
    public:
        sql_timestamp(sahara::time::timestamp& value): sql_value(value, "'", "'"){};
    };

    typedef std::variant<sql_int, sql_bool, sql_double, sql_date, sql_timestamp> sql_value_variant;
} // rosetta

#endif //ROSETTA_SUPPORT_H
