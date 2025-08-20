#include "../headers/EndToken.h"

using namespace Sawoca;

EndToken::EndToken() : Token(END) {}

std::string EndToken::get_string_type() const{
    return std::string("END");
}

Language::Values::ValueI* EndToken::get_value() const{
    throw "END tokens do not hold any value";
}