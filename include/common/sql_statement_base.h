//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef OBELISK_SQL_STATEMENT_BASE_H
#define OBELISK_SQL_STATEMENT_BASE_H

#include <string>
#include <utility>

namespace rosetta {

  class sql_statement_base {
  public:
    explicit sql_statement_base(std::string_view statement): sql_(statement){}
    virtual void bind_param(std::string_view type, std::string_view data) = 0;
    virtual void bind_param(std::string_view type, uint64_t data) = 0;
    virtual std::string_view to_string(){ return sql_; };
  protected:
    std::string sql_;
  };

} // rosetta

#endif //OBELISK_SQL_STATEMENT_BASE_H
