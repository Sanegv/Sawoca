#include "../headers/RightParToken.h"

using namespace Sawoca;

RightPar_Token::RightPar_Token() : Token(RP) {}

std::string RightPar_Token::get_string_type() const{
    return std::string("RP");
}

const Language::Values::ValueI* RightPar_Token::get_value() const{
    throw std::string("RP tokens do not hold any value");
}