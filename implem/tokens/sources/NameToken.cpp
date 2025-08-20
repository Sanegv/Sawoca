#include "../headers/NameToken.h"

using namespace Sawoca;

Name_Token::Name_Token(
        std::string name,
        std::map<std::string, Language::Values::ValueI*>& variables
    ) : Token(NAME), name(name), variables(variables){}

std::string Name_Token::get_string_type() const{
    return "NAME";
}

Language::Values::ValueI* Name_Token::get_value() const{
    return variables[name];
}