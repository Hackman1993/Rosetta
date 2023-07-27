////
//// Created by Hackman.Lo on 3/24/2023.
////
//
//#include <sahara/exception/database_exception.h>
//#include "mysql_impl/mysql_result.h"
//#include "common/sql_row.h"
//
//namespace rosetta {
//
//    mysql_result::mysql_result(std::size_t affected, sql::ResultSet *result) : sql_result(affected), result_(result) {
//    }
////
////    boolean mysql_result::get_boolean(std::uint32_t row, std::size_t column) {
////        _move_cursor(row);
////        return result_->isNull(column + 1) ? boolean(nullptr) : boolean(result_->getBoolean(column + 1));
////    }
////
////    long_double mysql_result::get_double(std::uint32_t row, std::size_t column) {
////        _move_cursor(row);
////        return result_->isNull(column + 1) ? long_double(nullptr) : long_double(result_->getDouble(column + 1));
////    }
////
////    string mysql_result::get_string(std::uint32_t row, std::size_t column) {
////        _move_cursor(row);
////        return result_->isNull(column + 1) ? string(nullptr) : string(result_->getString(column + 1).asStdString());
////    }
////
////    integer mysql_result::get_integer(std::uint32_t row, std::size_t column) {
////        _move_cursor(row);
////        return result_->isNull(column + 1) ? integer(nullptr) : integer(result_->getInt(column + 1));
////    }
////
////    unsigned_integer mysql_result::get_unsigned_integer(std::uint32_t row, std::size_t column) {
////        _move_cursor(row);
////        return result_->isNull(column + 1) ? unsigned_integer(nullptr) : unsigned_integer(result_->getUInt(column + 1));
////    }
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
//        mysql_field
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

#include <utility>
#include <iostream>

#include "mysql_impl/mysql_result.h"
#include "mysql_impl/mysql_row.h"

rosetta::mysql_result::mysql_result(std::shared_ptr<MYSQL_STMT>& statement) : statement_(statement){
    column_meta_ = mysql_stmt_result_metadata(statement_.get());
}

size_t rosetta::mysql_result::count() {
    if(row_count_ == nullptr)
    {
        if(mysql_stmt_store_result(statement_.get()))
            throw std::logic_error(mysql_stmt_error(statement_.get()));
        row_count_ = std::make_shared<std::uint64_t>(mysql_stmt_num_rows(statement_.get()));
    }

    return *row_count_;
}

sahara::string rosetta::mysql_result::column_name(std::size_t column) {
    if(column >= column_meta_->field_count)
        throw std::logic_error("Column Index Out Of Range!");
    return column_meta_->fields[column].name;
}

sahara::string rosetta::mysql_result::column_type(std::size_t column) {
    if(column >= column_meta_->field_count)
        throw std::logic_error("Column Index Out Of Range!");
    switch (column_meta_->fields[column].type){
        case MYSQL_TYPE_DECIMAL:
            return "decimal";
        case MYSQL_TYPE_TINY:
            return "tiny";
        case MYSQL_TYPE_SHORT:
            return "short";
        case MYSQL_TYPE_LONG:
            return "long";
        case MYSQL_TYPE_FLOAT:
            return "float";
        case MYSQL_TYPE_DOUBLE:
            return "double";
        case MYSQL_TYPE_NULL:
            return "null";
        case MYSQL_TYPE_TIMESTAMP:
            return "timestamp";
        case MYSQL_TYPE_LONGLONG:
            return "long long";
        case MYSQL_TYPE_INT24:
            return "int24";
        case MYSQL_TYPE_DATE:
            return "date";
        case MYSQL_TYPE_TIME:
            return "time";
        case MYSQL_TYPE_DATETIME:
            return "datetime";
        case MYSQL_TYPE_YEAR:
            return "year";
        case MYSQL_TYPE_NEWDATE:
            return "new date";
        case MYSQL_TYPE_VARCHAR:
            return "varchar";
        case MYSQL_TYPE_BIT:
            return "bit";
        case MYSQL_TYPE_TIMESTAMP2:
            return "timestamp2";
        case MYSQL_TYPE_DATETIME2:
            return "datetime2";
        case MYSQL_TYPE_TIME2:
            return "time2";
        case MYSQL_TYPE_TYPED_ARRAY:
            return "typed array";
        case MYSQL_TYPE_INVALID:
            return "invalid";
        case MYSQL_TYPE_BOOL:
            return "bool";
        case MYSQL_TYPE_JSON:
            return "json";
        case MYSQL_TYPE_NEWDECIMAL:
            return "new decimal";
        case MYSQL_TYPE_ENUM:
            return "enum";
        case MYSQL_TYPE_SET:
            return "set";
        case MYSQL_TYPE_TINY_BLOB:
            return "tiny blob";
        case MYSQL_TYPE_MEDIUM_BLOB:
            return "medium blob";
        case MYSQL_TYPE_LONG_BLOB:
            return "long blob";
        case MYSQL_TYPE_BLOB:
            return "blob";
        case MYSQL_TYPE_VAR_STRING:
            return "var string";
        case MYSQL_TYPE_STRING:
            return "string";
        case MYSQL_TYPE_GEOMETRY:
            return "geometry";
    }
    return "unknown";
}

sahara::string rosetta::mysql_result::column_type(const sahara::string &column) {
    return column_type(column_index(column));
}

size_t rosetta::mysql_result::column_index(const sahara::string &column) {
    if(!columns_.contains(column.to_std()))
        throw std::logic_error("Column Not Exists!");
    return columns_[column.to_std()];
}

size_t rosetta::mysql_result::column_count() {
    return mysql_stmt_field_count(statement_.get());
}

size_t rosetta::mysql_result::affected_rows() {
    return mysql_stmt_affected_rows(statement_.get());
}

std::shared_ptr<rosetta::sql_row> rosetta::mysql_result::next() {
    std::vector<MYSQL_BIND> binder_;
    std::vector<mysql_cell_data> meta_;
    for(int i = 0; i < column_meta_->field_count; ++i){
        MYSQL_BIND bind = {0};
        bind.buffer_type = column_meta_->fields[i].type;
        columns_.emplace(column_meta_->fields[i].name, i);
        unsigned long length = column_meta_->fields[i].length;
        switch (column_meta_->fields[i].type) {
            case MYSQL_TYPE_TIMESTAMP:
                length = sizeof(MYSQL_TIME);
                break;
        }
        bind.buffer_length = std::min<std::uint64_t>(length, 1024*1024*1);
        std::shared_ptr<unsigned char> buffer(new unsigned char[bind.buffer_length], [](unsigned char *p){});
        memset(buffer.get(), 0, bind.buffer_length);
        bind.buffer = buffer.get();
        auto &data = meta_.emplace_back(buffer, 0, false);
        bind.length = data.length_.get();
        bind.is_null = data.is_null_.get();
        binder_.push_back(bind);
    }
    if(mysql_stmt_bind_result(statement_.get(), binder_.data()))
        throw std::logic_error(mysql_stmt_error(statement_.get()));

    if(mysql_stmt_fetch(statement_.get()))
        return nullptr;
    return std::make_shared<rosetta::mysql_row>(binder_, meta_);
}

rosetta::mysql_result::~mysql_result() {
}

