//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_DATABASE_CONNECTION_BASE_H
#define ROSETTA_DATABASE_CONNECTION_BASE_H
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <functional>
#include "sql_result.h"
#include "sql_statement_base.h"
namespace rosetta {
  using namespace std::chrono_literals;

  class database_connection_base {
  public:
    database_connection_base(std::string_view host, unsigned short port, std::string_view username, std::string_view password, std::string_view database):
      host_(host), port_(port), database_(database), password_(password), username_(username), last_active_(std::chrono::steady_clock::now()){
      refresh_thread_ = std::make_unique<std::thread>(std::bind(&database_connection_base::refresh_worker, this));
    };
    virtual void refresh()  = 0;
    virtual void close(){};
    virtual ~database_connection_base() {
      shutdown_ = true;
      refresh_thread_->join();
      this->close();
      std::cout << "Connection Base Released" << std::endl;
    };
    virtual void begin_transaction() = 0;
    virtual void commit_transaction() = 0;
    virtual std::shared_ptr<sql_statement_base> prepared_statement(std::string_view sql) = 0;
  protected:
    virtual void refresh_worker(){
      while(!shutdown_){
        std::chrono::steady_clock::time_point current = std::chrono::steady_clock::now();
        if((current - last_active_) > refresh_period_) {
          refresh();
          last_active_ = std::chrono::steady_clock::now();
        }
        else {
          auto refresh_remain = refresh_period_ - (current - last_active_);
          std::this_thread::sleep_for(1s > refresh_remain? refresh_remain:1s);
        }
      }
    }
    std::string host_;
    unsigned short port_ = 0;
    std::string database_;
    std::string username_;
    std::string password_;

    bool shutdown_ = false;
    std::chrono::steady_clock::duration refresh_period_ = 30s;
    std::chrono::steady_clock::time_point last_active_;
    std::unique_ptr<std::thread> refresh_thread_;
  };

} // rosetta

#endif //ROSETTA_DATABASE_CONNECTION_BASE_H
