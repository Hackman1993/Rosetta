//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_JOIN_H
#define ROSETTA_JOIN_H
#include <functional>
#include "use/use_on.h"
#include "use/use_table.h"

namespace rosetta::core {
    class joins : public sql_base, public use_table, public use_on<joins>{
    public:
        joins(const std::string &table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback);
        joins(alia table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback);
        std::string compile() override;
    protected:
        E_JOIN_TYPE type_ = JOIN_TYPE_INNER;
        std::function<void (joins&)> callback_;
    };

} // core

#endif //ROSETTA_JOIN_H
