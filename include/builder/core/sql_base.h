//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_SQL_BASE_H
#define ROSETTA_SQL_BASE_H
#include <string>
namespace rosetta::core {
    struct alia{
        std::string name_;
        std::string alias_;
    };

    class sql_base {
    public:
        virtual std::string compile() = 0;
        virtual ~sql_base() = default;
    };

    enum E_JOIN_TYPE {
        JOIN_TYPE_INNER, JOIN_TYPE_LEFT, JOIN_TYPE_RIGHT, JOIN_TYPE_FULL
    };
} // core

#endif //ROSETTA_SQL_BASE_H
