#include "../headers/PrintToken.h"

using namespace Sawoca;

PrintToken::PrintToken() : Token(PRINT) {}

std::string PrintToken::get_string_type() const{
    return std::string("PRINT");
}

const Language::Values::ValueI* PrintToken::get_value() const{
    throw std::string("PRINT tokens do not hold any value");
}