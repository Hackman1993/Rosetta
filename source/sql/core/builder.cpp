#include "common/sql/builder.h"

namespace rosetta{
    builder& builder::distinct() {
        distinct_ = true;
        return *this;
    }
}