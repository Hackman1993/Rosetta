//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_USE_LIMIT_H
#define ROSETTA_USE_LIMIT_H

#include "../core/limit.h"
#include <memory>

namespace rosetta::core {

    class use_limit {
    protected:
        std::shared_ptr<limit> limit_;
    };

} // core

#endif //ROSETTA_USE_LIMIT_H
