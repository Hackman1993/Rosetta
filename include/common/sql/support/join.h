//
// Created by Hackman.Lo on 7/17/2023.
//

#ifndef ROSETTA_JOIN_H
#define ROSETTA_JOIN_H
#include "operate_base.h"
#include "builder.h"
#include "support.h"
#include <functional>
namespace rosetta::core {
    enum E_JOIN_TYPE {
        JOIN_TYPE_INNER, JOIN_TYPE_LEFT, JOIN_TYPE_RIGHT, JOIN_TYPE_FULL
    };

    class joins : public builder, public use_table, public use_on{
    public:
        joins(const std::string &table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback);
        joins(alia table, E_JOIN_TYPE type, const std::function<void(joins &)> &callback);

        joins& on(const std::string& column, const std::string& operate, const std::string& value);

        std::string compile() override;
    protected:
        E_JOIN_TYPE type_ = JOIN_TYPE_INNER;
        std::function<void (joins&)> callback_;
    };

} // core

#endif //ROSETTA_JOIN_H
