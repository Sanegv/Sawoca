#include "../headers/AssignToken.h"

using namespace Sawoca;

AssignToken::AssignToken() : Token(ASSIGN) {}

std::string AssignToken::get_string_type() const{
    return std::string("ASSIGN");
}

const Language::Values::ValueI* AssignToken::get_value() const{
    throw std::string("ASSIGN tokens do not hold any value");
}