//
// Created by Hackman.Lo on 7/28/2023.
//

#ifndef ROSETTA_LIMIT_H
#define ROSETTA_LIMIT_H
#include "sql_base.h"
namespace rosetta {
    namespace core {

        class limit : public sql_base {
        public:
            virtual std::string compile() override;
        protected:
            std::uint32_t limit_ = 0;
        };

    } // rosetta
} // core

#endif //ROSETTA_LIMIT_H
