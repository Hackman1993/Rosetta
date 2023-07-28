//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_WHERE_H
#define ROSETTA_USE_WHERE_H

#include <functional>
#include "../core/where_groups.h"

namespace rosetta::core {

    template<typename T>
    class use_where {
    public:
        T &where(const std::string &column, const std::string &operate, const std::string &value) {
            wheres_.emplace(false).where(column, operate, value);
            return static_cast<T &>(*this);
        }

        T &where(const std::function<void(where_group &)> &handle) {
            auto &group = wheres_.emplace(false);
            if (handle) {
                handle(group);
            }
            return static_cast<T &>(*this);
        }

        T &where_in(const std::string &column, std::uint32_t count) {
            wheres_.emplace(false).where_in(column, count);
            return static_cast<T &>(*this);
        }

        T& or_(const std::string &column, const std::string &operate, const std::string &value){
            if(wheres_.empty())
                throw std::logic_error("or_ must be after where");
            wheres_.emplace(true).or_(column, operate, value);
            return static_cast<T &>(*this);
        }

    protected:
        where_groups wheres_;
    };

} // core

#endif //ROSETTA_USE_WHERE_H
