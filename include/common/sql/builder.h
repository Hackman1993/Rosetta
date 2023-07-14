//
// Created by Hackman.Lo on 7/14/2023.
//

#ifndef ROSETTA_BUILDER_H
#define ROSETTA_BUILDER_H
#include "grammar.h"
namespace rosetta {

    class builder : public core::builder_base {
    public:
        virtual ~builder() = default;
        virtual builder& distinct();
        virtual
    protected:
        grammar grammar_;
        bool distinct_ = false;

    };

} // rosetta

#endif //ROSETTA_BUILDER_H
