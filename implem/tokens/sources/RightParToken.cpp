#include "../headers/RightParToken.h"

using namespace Sawoca;

RightParToken::RightParToken() : Token(RP) {}

std::string RightParToken::get_string_type() const{
    return std::string("RP");
}

const Language::Values::ValueI* RightParToken::get_value() const{
    throw std::string("RP tokens do not hold any value");
}