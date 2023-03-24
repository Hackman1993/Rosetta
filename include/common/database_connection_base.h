//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_DATABASE_CONNECTION_BASE_H
#define ROSETTA_DATABASE_CONNECTION_BASE_H
#include <string>
#include "sql_result.h"
#include "sql_statement_base.h"
namespace rosetta {

  class database_connection_base {
  public:
    database_connection_base(std::string_view host, unsigned short port, std::string_view database, std::string_view username, std::string_view password):
      host_(host), port_(port), database_(database), password_(password), username_(username){};

    virtual bool connect() = 0;
    virtual ~database_connection_base() {};
  protected:
    std::string host_;
    unsigned short port_ = 0;
    std::string database_;
    std::string username_;
    std::string password_;
  };

} // rosetta

#endif //ROSETTA_DATABASE_CONNECTION_BASE_H
