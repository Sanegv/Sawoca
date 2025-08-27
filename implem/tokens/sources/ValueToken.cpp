#include "../headers/ValueToken.h"

using namespace Sawoca;

Value_Token::Value_Token(Value* value) : 
    Token(VALUE), value(value) {}

Value_Token::~Value_Token(){
    delete value;
}

const Value* Value_Token::get_value() const {
    return value;
}

std::string Value_Token::get_string_type( )const {
    return value->get_string_type();
}

Value_Type Value_Token::get_value_type() const{
    return value->get_type();
}