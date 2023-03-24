//
// Created by Hackman.Lo on 3/23/2023.
//

#ifndef ROSETTA_DATABASE_EXCEPTION_H
#define ROSETTA_DATABASE_EXCEPTION_H
#include "exception_base.h"
namespace rosetta {

    class database_exception : public rosetta::exception_base{
    public:
      database_exception(std::size_t code, std::string message): rosetta::exception_base(message), code_(code){}

    protected:

      std::size_t code_ = 0;
    };

} // rosetta

#endif //ROSETTA_DATABASE_EXCEPTION_H
