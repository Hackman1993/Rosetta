//
// Created by Hackman.Lo on 7/13/2023.
//

#ifndef ROSETTA_JOIN_H
#define ROSETTA_JOIN_H
#include <sahara/string/string.h>
namespace rosetta {
    enum E_JOIN_TYPE{
        JOIN_TYPE_INNER,
        JOIN_TYPE_LEFT,
        JOIN_TYPE_RIGHT,
        JOIN_TYPE_FULL
    };

    struct join {
        sahara::string table_;
        E_JOIN_TYPE join_type_ = JOIN_TYPE_INNER;

    };

} // rosetta

#endif //ROSETTA_JOIN_H
