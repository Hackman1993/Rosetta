//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_SQL_RESULT_H
#define ROSETTA_SQL_RESULT_H
#include <string>
#include <type_traits>

namespace rosetta {
  template<typename ReturnType>
  concept DatabaseTypes =
      std::same_as<ReturnType, std::uint32_t> ||
      std::same_as<ReturnType, std::int32_t> ||
      std::same_as<ReturnType, long double> ||
      std::same_as<ReturnType, std::string> ||
      std::same_as<ReturnType, bool> ||
      std::same_as<ReturnType, std::uint64_t> ||
      std::same_as<ReturnType, std::int64_t>
      ;

  class sql_result {
  public:
    explicit sql_result(std::size_t affected_rows): affected_rows_(affected_rows){};

    [[nodiscard]] std::size_t affected_rows() const { return affected_rows_; };
    virtual std::size_t count() = 0;
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, std::uint32_t>::value>::type* = 0){
      return get_uint32(row, attr);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, std::string>::value>::type* = 0){
      return get_string(row, attr);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, long double>::value>::type* = 0){
      return get_double(row, attr);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, bool>::value>::type* = 0){
      return get_boolean(row, attr);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, std::int32_t>::value>::type* = 0){
      return get_int32(row, attr);
    }

    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, std::uint64_t>::value>::type* = 0){
      return get_uint64(row, attr);
    }
    template<DatabaseTypes ReturnType>
    ReturnType get(std::uint32_t row, const std::string& attr, typename std::enable_if<std::is_same<ReturnType, std::int64_t>::value>::type* = 0){
      return get_int64(row, attr);
    }
  protected:
    virtual bool get_boolean(std::uint32_t row, const std::string& attr) = 0;
    virtual long double get_double(std::uint32_t row, const std::string& attr) = 0;
    virtual std::string get_string(std::uint32_t row, const std::string& attr) = 0;
    virtual std::int32_t get_int32(std::uint32_t row, const std::string& attr) = 0;
    virtual std::uint32_t get_uint32(std::uint32_t row, const std::string& attr) = 0;
    virtual std::int64_t get_uint64(std::uint32_t row, const std::string& attr) = 0;
    virtual std::uint64_t get_int64(std::uint32_t row, const std::string& attr) = 0;

    std::size_t affected_rows_;
  };

} // rosetta

#endif //ROSETTA_SQL_RESULT_H
