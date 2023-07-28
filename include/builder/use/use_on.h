//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_ON_H
#define ROSETTA_USE_ON_H
#include <sstream>
#include <functional>
#include "../core/where_groups.h"
namespace rosetta::core {

    template<typename T>
    class use_on {
    public:
        T &on(const std::string &column, const std::string &operate, const std::string &value) {
            ons_.emplace(false).where(column, operate, value);
            return static_cast<T &>(*this);
        }

        T &on(const std::function<void(where_group &)> &handle) {
            auto& group = ons_.emplace(false);
            if(handle) {
                handle(group);
            }
            return static_cast<T &>(*this);
        }
    protected:
        where_groups ons_;
    };

} // core

#endif //ROSETTA_USE_WHERE_H
