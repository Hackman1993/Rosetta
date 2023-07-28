//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_JOINS_H
#define ROSETTA_USE_JOINS_H
#include "builder/join.h"
namespace rosetta {
    namespace core {
        template <typename T>
        class use_joins {
        public:
            T& inner_join(const alia& table, const std::function<void (joins&)>& callback){
                joins_.emplace_back(table, JOIN_TYPE_INNER, callback);
                return static_cast<T &>(*this);
            };
            T& left_join(const alia& table, const std::function<void (joins&)>& callback){
                joins_.emplace_back(table, JOIN_TYPE_LEFT, callback);
                return static_cast<T &>(*this);
            };
            T& right_join(const alia& table, const std::function<void (joins&)>& callback){
                joins_.emplace_back(table, JOIN_TYPE_RIGHT, callback);
                return static_cast<T &>(*this);
            };

            T& full_join(const alia& table, const std::function<void (joins&)>& callback){
                joins_.emplace_back(table, JOIN_TYPE_FULL, callback);
                return static_cast<T &>(*this);
            };

        protected:
            std::vector<joins> joins_;

        };

    } // rosetta
} // core

#endif //ROSETTA_USE_JOINS_H
