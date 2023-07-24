//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_DATABASE_CONNECTION_H
#define ROSETTA_DATABASE_CONNECTION_H
#include <string>
#include "sql_result.h"
#include "database_connection_base.h"
namespace rosetta {
  class database_connection : public database_connection_base{
  public:
    database_connection(const std::string &host, unsigned short port, const std::string &username, const std::string &password, const std::string &database) : database_connection_base(host, port, username, password, database){};


  protected:
  };

} // rosetta

#endif //ROSETTA_DATABASE_CONNECTION_H
