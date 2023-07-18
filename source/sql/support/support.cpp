//
// Created by Hackman.Lo on 7/17/2023.
//

#include <utility>

#include "common/sql/support/support.h"
#include "common/sql/support/condition.h"

namespace rosetta {
    namespace core {
        use_tables::use_tables(std::vector<std::string> tables) {
            for (auto &table: tables) {
                tables_.push_back({table, ""});
            }
        }

        use_tables::use_tables(std::vector<alia> tables) {
            tables_ = std::move(tables);
        }

        use_column_alias::use_column_alias(std::vector<std::string> columns) {
            for (auto &column: columns) {
                columns_.push_back({column, ""});
            }
        }

        use_column_alias::use_column_alias(std::vector<alia> columns) {
            for(auto &column:columns) {
                columns_.push_back(column);
            }
        }
    } // rosetta
} // core