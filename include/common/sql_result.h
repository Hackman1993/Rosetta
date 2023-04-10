//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_RESULT_H
#define ROSETTA_SQL_RESULT_H
#include <string>
#include <type_traits>
#include "sql_types.h"

namespace rosetta {
  class sql_row;
  template<typename ReturnType>
  concept DatabaseTypes =
      std::same_as<ReturnType, boolean> ||
      std::same_as<ReturnType, unsigned_integer> ||
      std::same_as<ReturnType, long_double> ||
      std::same_as<ReturnType, string> ||
      std::same_as<ReturnType, integer>;

  class sql_result : std::enable_shared_from_this<sql_result>{
  public:
    explicit sql_result(std::size_t affected_rows): affected_rows_(affected_rows){};

    [[nodiscard]] std::size_t affected_rows() const { return affected_rows_; };
    virtual std::size_t count() = 0;
    virtual std::size_t column_count() = 0;
    virtual std::size_t column_index(const std::string& column) = 0;
    virtual std::string column_name(std::size_t column) = 0;
    virtual std::string column_type(const std::string& column) = 0;
    virtual std::string column_type(std::size_t column) = 0;
    virtual std::unique_ptr<sql_row> get_row(std::uint32_t row);


    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, boolean>::value>::type* = 0){
      return get_boolean(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, boolean>::value>::type* = 0){
      return get_boolean(row, column_index(column));
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, integer>::value>::type* = 0){
      return get_integer(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, integer>::value>::type* = 0){
      return get_integer(row, column_index(column));
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, unsigned_integer>::value>::type* = 0){
      return get_unsigned_integer(row, column);
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, unsigned_integer>::value>::type* = 0){
      return get_unsigned_integer(row, column_index(column));
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, string>::value>::type* = 0){
      return get_string(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, string>::value>::type* = 0){
      return get_string(row, column_index(column));
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, std::size_t column, typename std::enable_if<std::is_same<ReturnType, long_double>::value>::type* = 0){
      return get_double(row, column);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& column, typename std::enable_if<std::is_same<ReturnType, long_double>::value>::type* = 0){
      return get_double(row, column_index(column));
    }

    std::string to_json();
  protected:
    virtual boolean get_boolean(std::uint32_t row, std::size_t col) = 0;
    virtual long_double get_double(std::uint32_t row, std::size_t col) = 0;
    virtual string get_string(std::uint32_t row, std::size_t col) = 0;
    virtual integer get_integer(std::uint32_t row, std::size_t col) = 0;
    virtual unsigned_integer get_unsigned_integer(std::uint32_t row, std::size_t col) = 0;

    std::size_t affected_rows_;
  };

} // rosetta

#endif //ROSETTA_SQL_RESULT_H
