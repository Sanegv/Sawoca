#include "../headers/EndToken.h"

using namespace Sawoca;

End_Token::End_Token() : Token(END) {}

std::string End_Token::get_string_type() const{
    return std::string("END");
}

const Language::Values::ValueI* End_Token::get_value() const{
    throw std::string("END tokens do not hold any value");
}