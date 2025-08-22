#include "../headers/NumberToken.h"
#include "../../values/headers/Double.h"

using namespace Sawoca;

Number_Token::Number_Token() : Token(NUMBER), value(new Double()) {
    if(!value)
        throw "memory allocation failed";
    }

Number_Token::Number_Token(double d) :
    Token(NUMBER), value(new Double(d)) {
        if(!value)
            throw "memory allocation failed";
    }

Number_Token::Number_Token(Language::Values::ValueI* value) : 
    Token(NUMBER), value(value) {}

Number_Token::~Number_Token(){
    delete value;
}

const Language::Values::ValueI* Number_Token::get_value() const {
    return value;
}

std::string Number_Token::get_string_type( )const {
    return "NUMBER";
}