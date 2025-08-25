#include "../headers/LeftParToken.h"

using namespace Sawoca;

LeftPar_Token::LeftPar_Token() : Token(LP) {}

std::string LeftPar_Token::get_string_type() const{
    return std::string("LP");
}

const Language::Values::ValueI* LeftPar_Token::get_value() const{
    throw std::string("LP tokens do not hold any value");
}