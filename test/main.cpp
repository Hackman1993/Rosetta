#include <iostream>
#include <rosetta.h>
#include <boost/url.hpp>

using namespace std::chrono_literals;
int main() {
//  rosetta::route_item item("/route/{param1}/{param2}/bacba");
//  std::string_view str = "/route/dga2/param2/bacba";


  try{
    rosetta::database_pool pool(10, "127.0.0.1", 3306, "root","hl97005497--", "science_society");
    pool.initialize<rosetta::mysql_connection>();
    std::this_thread::sleep_for(10s);
    {
      auto test = pool.get_connection<rosetta::mysql_connection>();
      if(test) {
        int a = 0;
      }
    }
//    rosetta::mysql_connection connection("127.0.0.1", 3306, "science_society", "root","hl97005497--");
//    connection.connect();
//    auto statement = connection.prepared_statement("select * from t_user");
//    //statement.bind_param(1, "002d1a7cb7814a3bbefe43039d13a03c");
//    auto result = statement.execute();
//    auto count = result.get<std::string>(1, "user_id");
    while(true);

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