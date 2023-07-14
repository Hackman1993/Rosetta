//
// Created by Hackman.Lo on 4/21/2023.
//

#ifndef ROSETTA_TABLE_H
#define ROSETTA_TABLE_H

#include <string/string.h>


namespace rosetta::migration {


    class table {
    public:
        table(const sahara::string& name ,const sahara::string& comment, const sahara::string& encoding): name_(name), encoding_(encoding), comment_(comment){};
        virtual sahara::string sql() = 0;
    protected:
        sahara::string name_;
        sahara::string encoding_;
        sahara::string comment_;
    };
} // rosetta::migration

#endif //ROSETTA_TABLE_H
