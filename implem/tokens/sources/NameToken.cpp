#include "../headers/NameToken.h"
#include <stdexcept>
#include <typeinfo>

using namespace Sawoca;

Name_Token::Name_Token(
        std::string name,
        std::map<std::string, const Language::Values::ValueI*>& variables
    ) : Token(NAME), name(name), variables(variables){}

std::string Name_Token::get_string_type() const{
    return "NAME";
}

const Language::Values::ValueI* Name_Token::get_value() const{
    try {
        const Language::Values::ValueI* result = variables.at(name);
        return result;
    } catch (const std::out_of_range& e){
        throw "unknown variable: " + name;
    }
}

std::string Name_Token::get_name(){
    return name;
}