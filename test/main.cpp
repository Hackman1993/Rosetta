#include <iostream>
//#include <rosetta.h>
#include <boost/url.hpp>
#include <common/sql/support/insert.h>
#include <common/sql/support/update.h>
#include "common/sql/support/del.h"
#include "common/sql/support/select.h"
#include "database_pool.h"
#include "mysql_impl/mysql_connection.h"
#include <mysql/mysql.h>
#include <common/sql_row.h>
using namespace std::chrono_literals;


int main() {

    try {
        rosetta::core::select select_builder({"user_id", "username", "password"});
        select_builder.from({{"t_user", ""}}).where("username", "=", "?");

        auto test = select_builder.compile();

        int a = 100;
        MYSQL *data = mysql_init(nullptr);
        data = mysql_real_connect(data, "127.0.0.1", "root", "hl97005497--", "science_society", 3306, nullptr, 0);
        //std::this_thread::sleep_for(std::chrono::seconds(30));

        rosetta::database_pool pool(10, "127.0.0.1", 3306, "root", "hl97005497--", "science_society");
        pool.initialize<rosetta::mysql_connection>();
        std::this_thread::sleep_for(1s);
        {
            auto test = pool.get_connection<rosetta::mysql_connection>();
            if (test) {
                int a = 0;
            }
        }
        {
        auto connection = pool.get_connection<rosetta::mysql_connection>();
        auto statement = connection->prepared_statement(test);
        statement->bind_param(std::string("admin"));
        statement->execute();
        auto result = statement->get();
        auto row = result->next();
        std::string uid = std::get<std::string>(row->get_column(0));
        std::string uname = std::get<std::string>(row->get_column(1));
        std::string pwd = std::get<std::string>(row->get_column(2));
        std::cout << uid.length() << ":" << uid.size() << std::endl;
        std::cout << uname.length() << ":" << uname.size() << std::endl;
        std::cout << pwd.length() << ":" << pwd.size() << std::endl;
        }

        while (true);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}