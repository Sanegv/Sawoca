#include "../headers/AssignToken.h"

using namespace Sawoca;

Assign_Token::Assign_Token() : Token(ASSIGN) {}

std::string Assign_Token::get_string_type() const{
    return std::string("ASSIGN");
}

const Language::Values::ValueI* Assign_Token::get_value() const{
    throw std::string("ASSIGN tokens do not hold any value");
}