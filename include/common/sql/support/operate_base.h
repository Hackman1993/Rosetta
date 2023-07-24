//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_OPERATE_BASE_H
#define ROSETTA_OPERATE_BASE_H

#include <string>
#include <utility>

namespace rosetta::core {

    class operate_base {
    public:
        virtual std::string compile() = 0;
    };

    class limit : public operate_base {
    public:
        virtual std::string compile() override {
            return "LIMIT " + std::to_string(limit_);
        }
    protected:
        std::uint32_t limit_ = 0;
    };

    struct alia{
        std::string name_;
        std::string alias_;
    };

} // core

#endif //ROSETTA_OPERATE_BASE_H
