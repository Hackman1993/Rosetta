//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_CONDITION_BASE_H
#define ROSETTA_CONDITION_BASE_H

#include "sql_base.h"
namespace rosetta::core{


    class condition_base : public sql_base{
    public:
        explicit condition_base(bool is_or) : is_or_(is_or) {};
        bool is_or_ = false;
    };
}
#endif //ROSETTA_CONDITION_BASE_H
