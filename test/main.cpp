#include <iostream>
#include <rosetta.h>
#include <boost/url.hpp>
using namespace std::chrono_literals;
int main() {
  try{
    rosetta::database_pool pool(10, "127.0.0.1", 3306, "root","hl97005497--", "science_society");
    pool.initialize<rosetta::mysql_connection>();
    std::this_thread::sleep_for(1s);
    {
      auto test = pool.get_connection<rosetta::mysql_connection>();
      if(test) {
        int a = 0;
      }
    }
    auto connection = pool.get_connection<rosetta::mysql_connection>();
    auto statement = connection->prepared_statement("select * from t_user");
    //statement.bind_param(1, "002d1a7cb7814a3bbefe43039d13a03c");
    auto result = statement->execute();
    auto count = result->get<rosetta::string>(1, "user_id");
    while(true);

  } catch (std::exception& e){
    std::cout<< e.what()<< std::endl;
  }
  return 0;
}