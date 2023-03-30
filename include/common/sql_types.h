//
// Created by Hackman.Lo on 3/30/2023.
//

#ifndef ROSETTA_SQL_TYPES_H
#define ROSETTA_SQL_TYPES_H
#include <memory>
#include <string>
#include <boost/lexical_cast.hpp>
namespace rosetta {
  template <typename BaseType>
  class sql_value{
  public:
    explicit sql_value(BaseType data): data_(std::make_unique<BaseType>(data)){};
    explicit sql_value() = default;
    virtual bool is_null(){ return (bool)data_; }
    operator BaseType(){
      if(data_) return *data_;
      return BaseType();
    }

    virtual std::string json_value(){
      if(data_) return boost::lexical_cast<std::string>(*data_);
      return "null";
    }
  protected:
    std::unique_ptr<BaseType> data_;
  };
  class sql_int : public sql_value<std::int32_t>{
  public:
    explicit sql_int(std::int32_t data) : sql_value<std::int32_t>(data){}
    sql_int() = default;
  };
  class sql_uint : public sql_value<std::uint32_t>{
  public:
    explicit sql_uint(std::uint32_t data) : sql_value<std::uint32_t>(data){}
    sql_uint() = default;
  };


  class sql_double: public sql_value<double>{
  public:
    explicit sql_double(double data) : sql_value<double>(data){}
    sql_double() = default;
  };
  class sql_long_double: public sql_value<long double>{
  public:
    explicit sql_long_double(long double data) : sql_value<long double>(data){}
    sql_long_double() = default;
  };

  class sql_string: public sql_value<std::string>{
  public:
    explicit sql_string(std::string data) : sql_value<std::string>(data){}
    sql_string() = default;
    std::string json_value() override{
      if(data_) return "\"" + boost::lexical_cast<std::string>(*data_) + "\"";
      return "null";
    }
  };

  class sql_int64 : public sql_value<std::int64_t>{
  public:
    explicit sql_int64(std::int64_t data) : sql_value<std::int64_t>(data){}
    sql_int64() = default;
  };


  class sql_uint64 : public sql_value<std::uint64_t>{
  public:
    explicit sql_uint64(std::uint64_t data) : sql_value<std::uint64_t>(data){}
    sql_uint64() = default;
  };

  class sql_bool : public sql_value<bool>{
  public:
    explicit sql_bool(bool data) : sql_value<bool>(data){}
    sql_bool() = default;
    std::string json_value() override{
      if(data_) return *data_? "true": "false";
      return "null";
    }
  };


} // rosetta

#endif //ROSETTA_SQL_TYPES_H
