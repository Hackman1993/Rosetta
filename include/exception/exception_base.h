//
// Created by Hackman.Lo on 3/10/2023.
//

#ifndef OBELISK_EXCEPTION_BASE_H
#define OBELISK_EXCEPTION_BASE_H
#include <string>
namespace rosetta{
  class exception_base :public std::exception{
  public:
    exception_base(std::string str_what) : what_(str_what){};
    const char *what() const override {
      return what_.c_str();
    }

  protected:
    std::string what_;
  };
}

#endif //OBELISK_EXCEPTION_BASE_H
