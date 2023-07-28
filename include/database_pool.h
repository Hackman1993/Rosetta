//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef OBELISK_DATABASE_POOL_H
#define OBELISK_DATABASE_POOL_H

#include <thread>
#include <queue>
#include <iostream>
#include <boost/thread.hpp>
#include <condition_variable>
#include <boost/polymorphic_pointer_cast.hpp>
#include <utility>
#include <sahara/log/log.h>
#include "pool/database_connection_base.h"
namespace rosetta {
    using namespace std::chrono_literals;

    class database_pool {
    public:
        database_pool(std::size_t pool_size, sahara::string host, std::uint16_t port, sahara::string username, sahara::string password, sahara::string database) : host_(std::move(host)), username_(std::move(username)), password_(std::move(password)), database_(std::move(database)), port_(port), max_conn_(pool_size) {

        }

        template<typename Connection>
        void initialize() {
            connection_generation_thread_ = std::make_unique<boost::thread>([&]() {
                std::mutex mutex_;
                std::unique_lock lock_(mutex_);
                while (!shutdown_) {
                    connections_cv_.wait(lock_, [this] { return connections_.size() < max_conn_; });
                    try {
                        while (connections_.size() < max_conn_) {
                            std::unique_lock lock(connections_mutex_);
                            connections_.push_back(std::shared_ptr<Connection>(new Connection(host_, port_, username_, password_, database_), std::bind(&database_pool::deletor<Connection>, this, std::placeholders::_1)));
                        }
                    } catch (std::exception &e) {
                        LOG_MODULE_DEBUG("rosetta", "{}", e.what());
                    }
                }
            });
        }

        template<class Connection>
        void deletor(Connection *connection) {
            if (shutdown_) {
                delete connection;
                return;
            }
            std::unique_lock lock(connections_mutex_);
            connections_.push_back(std::shared_ptr<Connection>(connection, std::bind(&database_pool::deletor<Connection>, this, std::placeholders::_1)));
        }

        template<typename Connection>
        std::shared_ptr<Connection> get_connection() {
            std::unique_lock lock(connections_mutex_);
            if (!connections_.empty()) {
                auto conn = std::move(connections_.back());
                connections_.pop_back();
                connections_cv_.notify_one();
                return boost::polymorphic_pointer_downcast<Connection>(conn);
            } else return nullptr;
        }

        ~database_pool() {
            shutdown_ = true;
            connection_generation_thread_->join();
        }

    protected:
        bool shutdown_ = false;
        std::size_t max_conn_ = 0;

        std::mutex connections_mutex_;
        std::condition_variable connections_cv_;
        std::unique_ptr<boost::thread> connection_generation_thread_;

        sahara::string host_;
        std::uint16_t port_;
        sahara::string username_;
        sahara::string password_;
        sahara::string database_;
        std::vector<std::shared_ptr<database_connection_base>> connections_;
    };
}


#endif //OBELISK_DATABASE_POOL_H
