////
//// Created by Hackman.Lo on 3/23/2023.
////
//
//#ifndef ROSETTA_MYSQL_STATEMENT_H
//#define ROSETTA_MYSQL_STATEMENT_H
//#include "common/sql_statement.h"
//#include <unordered_map>
//namespace rosetta {
//
//  class mysql_connection;
//  class mysql_result;
//  class mysql_statement : public sql_statement{
//  public:
//    mysql_statement(mysql_connection& connection, const sahara::string& sql);
//    std::shared_ptr<sql_result> execute() override;
//
//    void bind_param(std::uint32_t param_id, rosetta::string data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::integer data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::boolean data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::timestamp data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::long_double data) override;
//
//    void bind_param(std::uint32_t param_id, rosetta::unsigned_integer data) override;
//
//    ~mysql_statement();
//  private:
//  };
//
//} // rosetta
//
//#endif //ROSETTA_MYSQL_STATEMENT_H
