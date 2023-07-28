//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_ORDERBY_H
#define ROSETTA_USE_ORDERBY_H
#include <string>
#include <vector>
namespace rosetta::core {

    template<typename T>
    class use_orderby {
    public:
        T& order_desc(std::vector<std::string> columns){
            orderby_ = std::move(columns);
            asc_ = false;
            return static_cast<T&>(*this);
        }
        T& order_asc(std::vector<std::string> columns){
            orderby_ = std::move(columns);
            asc_ = true;
            return static_cast<T&>(*this);
        }

    protected:
        bool asc_ = true;
        std::vector<std::string> orderby_;
    };

} // core

#endif //ROSETTA_USE_ORDERBY_H
