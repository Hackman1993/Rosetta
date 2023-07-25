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
#include <boost/json.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <sahara/log/log.h>
#include <spdlog/sinks/daily_file_sink.h>

using namespace std::chrono_literals;


int main() {
    try {
        sahara::log::add_sink(std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/general.log", 0, 0));
        sahara::log::set_level(spdlog::level::debug);
        throw std::runtime_error("test");
//        rosetta::database_pool pool(10, "127.0.0.1", 3306, "root", "hl97005497--", "go_member_sys");
//        pool.initialize<rosetta::mysql_connection>();
//        std::this_thread::sleep_for(1s);
//        {
//            auto test = pool.get_connection<rosetta::mysql_connection>();
//            if (test) {
//                int a = 0;
//            }
//        }
//        {
//            rosetta::core::select select_builder({"code"});
//            select_builder.from({{"t_permission", "a"}}).inner_join({"t_mid_role_permission", "b"},[&](auto &join){
//                join.on("a.permission_id", "=", "b.permission_id");
//            })
//            .inner_join({"t_mid_user_role", "c"}, [&](auto &join2){
//                join2.on("b.role_id", "=", "c.role_id");
//            }).inner_join(rosetta::core::alia{"t_user_access_token", "d"}, [&](auto &join3){
//                join3.on("c.user_id", "=", "d.fn_user_id");
//            })
//            .where("d.token", "=", "?");
//            auto test = select_builder.compile();
//            auto connection = pool.get_connection<rosetta::mysql_connection>();
//            auto s = select_builder.compile();
//
//            auto statement = connection->prepared_statement(select_builder.compile());
//            statement->bind_param(std::string("admin"));
//            statement->execute();
//            auto result = statement->get();
//            auto row = result->next();

//            std::uint64_t uid = std::get<std::uint64_t>(row->get_column(0));
//            std::string uname = std::get<std::string>(row->get_column(1));
//            std::string pwd = std::get<std::string>(row->get_column(2));
//            rosetta::core::sql_param_value vtoken = row->get_column(3);
//            std::string token;
//            if (vtoken.index() == 0) {
//                token = boost::uuids::to_string(boost::uuids::random_generator()());
//                statement->reset();
//                statement = connection->prepared_statement("INSERT INTO t_user_access_token(fn_user_id, token) VALUES (?, ?)");
//                if (statement) {
//                    statement->bind_param(uid);
//                    statement->bind_param(token);
//                    statement->execute();
//                }
//            } else {
//                token = std::get<std::string>(vtoken);
//            }
//        }

        //while (true);

    } catch (std::exception &e) {
        LOG_MODULE_DEBUG("rosetta", "{}", e.what());
    }
    return 0;
}