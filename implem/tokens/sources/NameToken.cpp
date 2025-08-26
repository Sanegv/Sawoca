#include "../headers/NameToken.h"
#include <stdexcept>

using namespace Sawoca;

Name_Token::Name_Token(
        std::string name,
        std::map<std::string, const Value*>& variables
    ) : Token(NAME), name(name), variables(variables){}

std::string Name_Token::get_string_type() const{
    return "NAME";
}

const Value* Name_Token::get_value() const{
    try {
        const Value* result = variables.at(name);
        return result;
    } catch (const std::out_of_range& e){
        throw "unknown variable: " + name;
    }
}

std::string Name_Token::get_name(){
    return name;
}