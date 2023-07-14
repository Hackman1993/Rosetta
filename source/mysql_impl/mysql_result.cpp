////
//// Created by Hackman.Lo on 3/24/2023.
////
//
//#include "mysql_impl/mysql_result.h"
//#include "exception/database_exception.h"
//#include "common/sql_row.h"
//
//namespace rosetta {
//
//    mysql_result::mysql_result(std::size_t affected, sql::ResultSet *result) : sql_result(affected), result_(result) {
//    }
//
//    boolean mysql_result::get_boolean(std::uint32_t row, std::size_t column) {
//        _move_cursor(row);
//        return result_->isNull(column + 1) ? boolean(nullptr) : boolean(result_->getBoolean(column + 1));
//    }
//
//    long_double mysql_result::get_double(std::uint32_t row, std::size_t column) {
//        _move_cursor(row);
//        return result_->isNull(column + 1) ? long_double(nullptr) : long_double(result_->getDouble(column + 1));
//    }
//
//    string mysql_result::get_string(std::uint32_t row, std::size_t column) {
//        _move_cursor(row);
//        return result_->isNull(column + 1) ? string(nullptr) : string(result_->getString(column + 1).asStdString());
//    }
//
//    integer mysql_result::get_integer(std::uint32_t row, std::size_t column) {
//        _move_cursor(row);
//        return result_->isNull(column + 1) ? integer(nullptr) : integer(result_->getInt(column + 1));
//    }
//
//    unsigned_integer mysql_result::get_unsigned_integer(std::uint32_t row, std::size_t column) {
//        _move_cursor(row);
//        return result_->isNull(column + 1) ? unsigned_integer(nullptr) : unsigned_integer(result_->getUInt(column + 1));
//    }
//
//    size_t mysql_result::count() {
//        return result_->rowsCount();
//    }
//
//    size_t mysql_result::column_count() {
//        if (result_ && result_->getMetaData())
//            return result_->getMetaData()->getColumnCount();
//        return 0;
//    }
//
//    void mysql_result::_move_cursor(std::size_t cursor) {
//        if (!result_ || (cursor + 1) > result_->rowsCount())
//            throw sahara::exception::database_exception(5102, "Row Not Exists!");
//        result_->absolute(cursor + 1);
//    }
//
//    size_t mysql_result::column_index(const sahara::string &column) {
//        return (result_->findColumn(column.to_std()) - 1);
//    }
//
//    sahara::string mysql_result::column_name(std::size_t column) {
//        if (result_) return result_->getMetaData()->getColumnName(column + 1).asStdString();
//        return "";
//    }
//
//    sahara::string mysql_result::column_type(const sahara::string &column) {
//        return result_ ? result_->getMetaData()->getColumnTypeName(column_index(column) + 1).asStdString() : "";
//    }
//
//    sahara::string mysql_result::column_type(std::size_t column) {
//        return result_ ? result_->getMetaData()->getColumnTypeName(column + 1).asStdString() : "";
//    }
//} // rosetta