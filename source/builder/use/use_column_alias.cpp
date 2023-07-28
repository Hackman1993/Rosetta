//
// Created by Hackman.Lo on 7/28/2023.
//

#include "builder/use/use_column_alias.h"

namespace rosetta::core {
    use_column_alias::use_column_alias(std::vector<std::string> columns) {
        for (auto &column: columns) {
            columns_.push_back({column, ""});
        }
    }

    use_column_alias::use_column_alias(std::vector<alia> columns) {
        for (auto &column: columns) {
            columns_.push_back(column);
        }
    }
} // core