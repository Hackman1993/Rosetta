#include <sstream>
#include "common/sql/support/condition.h"
namespace rosetta::core{
    std::string condition::compile() {
        std::stringstream ss;
        ss << column_ << operator_ << value_ << " ";
        return ss.str();
    }

}