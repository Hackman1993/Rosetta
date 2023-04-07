//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_DATABASE_CONNECTION_H
#define ROSETTA_DATABASE_CONNECTION_H
#include <string>
#include "sql_result.h"
#include "database_connection_base.h"
namespace rosetta {

  template <class StatementType>
  class database_connection : public database_connection_base{
  public:
    database_connection(std::string_view host, unsigned short port, std::string_view username, std::string_view password, std::string_view database) : database_connection_base(host, port, username, password, database){};
    virtual void begin_transaction() = 0;
    virtual void commit_transaction() = 0;
    virtual void refresh() = 0;
    virtual std::shared_ptr<StatementType> prepared_statement(std::string_view sql) = 0;
  protected:
  };

} // rosetta

#endif //ROSETTA_DATABASE_CONNECTION_H
