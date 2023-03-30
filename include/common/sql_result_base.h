//
// Created by Hackman.Lo on 3/30/2023.
//

#ifndef ROSETTA_SQL_RESULT_BASE_H
#define ROSETTA_SQL_RESULT_BASE_H

namespace rosetta{
  class sql_result_base{

  protected:
    std::size_t affected_rows_;
    virtual sql_bool get_boolean(std::uint32_t row, std::size_t col) = 0;
    virtual sql_long_double get_double(std::uint32_t row, std::size_t col) = 0;
    virtual sql_string get_string(std::uint32_t row, std::size_t col) = 0;
    virtual sql_int get_int32(std::uint32_t row, std::size_t col) = 0;
    virtual sql_uint get_uint32(std::uint32_t row, std::size_t col) = 0;
    virtual sql_uint64 get_uint64(std::uint32_t row, std::size_t col) = 0;
    virtual sql_int64 get_int64(std::uint32_t row, std::size_t col) = 0;
  };
}

#endif //ROSETTA_SQL_RESULT_BASE_H
