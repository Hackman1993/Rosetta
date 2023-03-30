//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_RESULT_H
#define ROSETTA_SQL_RESULT_H
#include <string>
#include <type_traits>
#include "sql_types.h"
namespace rosetta {
  template<typename ReturnType>
  concept DatabaseTypes =
      std::same_as<ReturnType, sql_bool> ||
      std::same_as<ReturnType, sql_int> ||
      std::same_as<ReturnType, sql_uint> ||
      std::same_as<ReturnType, sql_double> ||
      std::same_as<ReturnType, sql_long_double> ||
      std::same_as<ReturnType, sql_string> ||
      std::same_as<ReturnType, sql_int64> ||
      std::same_as<ReturnType, sql_uint64>;

  class sql_result {
  public:
    explicit sql_result(std::size_t affected_rows): affected_rows_(affected_rows){};

    [[nodiscard]] std::size_t affected_rows() const { return affected_rows_; };
    virtual std::size_t count() = 0;
    virtual std::size_t column_count() = 0;
    virtual std::size_t column_index(const std::string& column) = 0;
    virtual std::string column_name(std::size_t column) = 0;
    virtual std::string column_type(const std::string& column) = 0;
    virtual std::string column_type(std::size_t column) = 0;

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_uint>::value>::type* = 0){
      return get_uint32(row, column_index(column));
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_uint>::value>::type* = 0){
      return get_uint32(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_string>::value>::type* = 0){
      return get_string(row, column_index(column));
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_string>::value>::type* = 0){
      return get_string(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_long_double>::value>::type* = 0){
      return get_double(row, column_index(column));
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_long_double>::value>::type* = 0){
      return get_double(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_bool>::value>::type* = 0){
      return get_boolean(row, column_index(column));
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_bool>::value>::type* = 0){
      return get_boolean(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_int>::value>::type* = 0){
      return get_int32(row, column_index(column));
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_int>::value>::type* = 0){
      return get_int32(row, column);
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_uint64>::value>::type* = 0){
      return get_uint64(row, column_index(column));
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_uint64>::value>::type* = 0){
      return get_uint64(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, sql_int64>::value>::type* = 0){
      return get_int64(row, column_index(column));
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, sql_int64>::value>::type* = 0){
      return get_int64(row, column);
    }
  protected:
    virtual sql_bool get_boolean(std::uint32_t row, std::size_t col) = 0;
    virtual sql_long_double get_double(std::uint32_t row, std::size_t col) = 0;
    virtual sql_string get_string(std::uint32_t row, std::size_t col) = 0;
    virtual sql_int get_int32(std::uint32_t row, std::size_t col) = 0;
    virtual sql_uint get_uint32(std::uint32_t row, std::size_t col) = 0;
    virtual sql_uint64 get_uint64(std::uint32_t row, std::size_t col) = 0;
    virtual sql_int64 get_int64(std::uint32_t row, std::size_t col) = 0;

    std::size_t affected_rows_;
  };

} // rosetta

#endif //ROSETTA_SQL_RESULT_H
