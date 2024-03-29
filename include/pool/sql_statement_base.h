//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef OBELISK_SQL_STATEMENT_BASE_H
#define OBELISK_SQL_STATEMENT_BASE_H

#include <string>
#include <utility>
#include <sahara/string/string.h>
#include "../core/sql_value.h"
namespace rosetta {
  class sql_result;
  class sql_statement_base {
  public:
    explicit sql_statement_base(const std::string& statement): sql_(statement){}
    virtual ~sql_statement_base()  = default;

    virtual sahara::string& to_string(){ return sql_; };
    virtual void execute() = 0;
    virtual void reset() = 0;
    virtual void bind_param(rosetta::core::sql_param_value value) = 0;
    virtual std::shared_ptr<sql_result> get() = 0;

//    virtual void bind_param(std::uint32_t param_id, rosetta::string data) = 0;
//    virtual void bind_param(std::uint32_t param_id, rosetta::integer data) = 0;
//    virtual void bind_param(std::uint32_t param_id, rosetta::boolean data) = 0;
//    virtual void bind_param(std::uint32_t param_id, rosetta::timestamp data) = 0;
//    virtual void bind_param(std::uint32_t param_id, rosetta::long_double data) = 0;
//    virtual void bind_param(std::uint32_t param_id, rosetta::unsigned_integer data) = 0;
  protected:
      sahara::string sql_;
  };

} // rosetta

#endif //OBELISK_SQL_STATEMENT_BASE_H
