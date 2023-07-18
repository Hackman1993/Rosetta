//
// Created by Hackman.Lo on 7/14/2023.
//

#ifndef ROSETTA_TYPES_H
#define ROSETTA_TYPES_H
#include <sahara/string/string.h>
#include <sahara/types/nullable.h>
namespace rosetta {

    enum CONDITION_TYPE{
        CT_EQUAL,
        CT_NOT_EQUAL,
        CT_LESS_THAN,
        CT_GREAT_THAN,
        CT_LESS_THAN_OR_EQUAL,
        CT_GREAT_THAN_OR_EQUAL,
        CT_IS_NULL,
        CT_IS_NOT_NULL,
        CT_LIKE,
        CT_NOT_LIKE,
        CT_IN,
        CT_NOT_IN,
    };



} // rosetta

#endif //ROSETTA_TYPES_H
