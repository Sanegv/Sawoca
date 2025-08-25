#include "../headers/PrintToken.h"

using namespace Sawoca;

Print_Token::Print_Token() : Token(PRINT) {}

std::string Print_Token::get_string_type() const{
    return std::string("PRINT");
}

const Language::Values::ValueI* Print_Token::get_value() const{
    throw std::string("PRINT tokens do not hold any value");
}