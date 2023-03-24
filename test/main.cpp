#include <iostream>
#include <rosetta.h>
#include <boost/url.hpp>
#include "mysql_impl/mysql_connection.h"
#include "mysql_impl/mysql_statement.h"

int main() {
//  rosetta::route_item item("/route/{param1}/{param2}/bacba");
//  std::string_view str = "/route/dga2/param2/bacba";


  try{
    rosetta::mysql_connection connection("127.0.0.1", 3306, "science_society", "root","hl97005497--");
    connection.connect();
    auto statement = connection.prepared_statement("select * from t_user where user_id = ?");
    statement.bind_param("user_id", "002d1a7cb7814a3bbefe43039d13a03c");

  } catch (std::exception& e){
    std::cout<< e.what()<< std::endl;
  }
  return 0;
}




//
//int main(int argc, char* argv[])
//{
//  auto const address = boost::asio::ip::make_address("0.0.0.0");
//  auto const port = static_cast<unsigned short>(82);
//  auto const doc_root = std::make_shared<std::string>("./wwwroot");
//  auto const threads = std::max<int>(1, 10);
//
//  rosetta::http_server server("0.0.0.0", 8082);
//  server.listen("0.0.0.0", 8083);
//  server.run(1);
//
//  return 0;
//}