#include "../headers/PrintToken.h"

using namespace Sawoca;

PrintToken::PrintToken() : Token(PRINT) {}

std::string PrintToken::get_string_type() const{
    return std::string("PRINT");
}

Language::Values::ValueI* PrintToken::get_value() const{
    throw "PRINT tokens do not hold any value";
}