#include <sstream>
#include "common/sql/support/condition.h"
namespace rosetta::core{
    std::string condition::compile() {
        std::stringstream ss;
        ss << column_ << " " << operator_ << " " << value_ << " ";
        return ss.str();
    }

    std::string where_in_::compile() {
        if(!values_count_)
            return "";
        std::stringstream ss;
        ss << column_ << "IN (";
        for(auto i = 0; i < values_count_; i++){
            if(i != 0)
                ss << ",";
            ss  << "?";
        }
        ss << ") ";
        return ss.str();
    }

}