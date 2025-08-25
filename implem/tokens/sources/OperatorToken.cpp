#include "../headers/OperatorToken.h"

using namespace Sawoca;


Operator_Token::Operator_Token(char op) 
	: Token(static_cast<Token_Type>(op)), op(op) {
    switch (op) {
		case '+': 
		case '-': 
		case '*': 
		case '/': 
            break;
        default:
            throw std::string("unknown operator: ") + op;
    }
}

const Language::Values::ValueI* Operator_Token::get_value() const {
	throw std::string("cannot get value of operator");
}

std::string Operator_Token::get_string_type() const {
    switch (op) {
    case '+':
        return "PLUS";
    case '-':
        return "MINUS";
    case '*':
        return "MUL";
    case '/':
        return "DIV";
    default:
        throw "unknown operator type";
    }
}
