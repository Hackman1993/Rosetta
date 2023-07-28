#include "builder/use/use_table.h"
namespace rosetta::core{
    use_tables::use_tables(std::vector<std::string> tables) {
        for (auto &table: tables) {
            tables_.push_back({table, ""});
        }
    }

    use_tables::use_tables(std::vector<alia> tables) {
        tables_ = std::move(tables);
    }
}