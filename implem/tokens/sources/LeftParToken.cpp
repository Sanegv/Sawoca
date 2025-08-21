#include "../headers/LeftParToken.h"

using namespace Sawoca;

LeftParToken::LeftParToken() : Token(LP) {}

std::string LeftParToken::get_string_type() const{
    return std::string("LP");
}

const Language::Values::ValueI* LeftParToken::get_value() const{
    throw std::string("LP tokens do not hold any value");
}