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
        rosetta::core::select select_builder({"code", "permission_id"});
        select_builder.distinct().from({{"t_permission", "a"}}).inner_join(rosetta::core::alia{"t_mid_role_permission", "b"}, [&](rosetta::core::joins &join) {
            join.on("a.permission_id", "=", "b.mid_permission_id");
        }).inner_join(rosetta::core::alia{"t_mid_user_role", "c"}, [&](auto &join) {
            join.on("b.mid_role_id", "=", "c.mid_role_id");
        }).where("c.mid_user_id", "=", "?");


        int a = 100;
        MYSQL *data = mysql_init(nullptr);
        data = mysql_real_connect(data, "127.0.0.1", "root", "hl97005497--", "science_societ", 3306, nullptr, 0);

        rosetta::database_pool pool(10, "127.0.0.1", 3306, "root", "hl97005497--", "science_society");
        pool.initialize<rosetta::mysql_connection>();
        std::this_thread::sleep_for(1s);
        {
            auto test = pool.get_connection<rosetta::mysql_connection>();
            if (test) {
                int a = 0;
            }
        }
        auto connection = pool.get_connection<rosetta::mysql_connection>();
        auto statement = connection->prepared_statement("select date_,longtext_ from t_test");
        statement->execute();
        auto result = statement->get();
        auto row1 = result->next();
        auto val1 = row1->get_column(1);
        auto row2 = result->next();
        auto val2 = row2->get_column(1);


        while (true);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}