#include "../headers/OperatorToken.h"

using namespace Sawoca;


Operator_Token::Operator_Token(char op) 
	: Token(static_cast<Token_Type>(op)), op(op) {
    switch (op) {
		case '+': 
		case '-': 
		case '*': 
		case '/': 
        case L_OR:
        case L_AND:
        case EQ:
        case NEQ:
        case L_NOT:
            break;
        default:
            throw std::string("unknown operator.");
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
    case L_OR:
        return "OR";
    case L_AND:
        return "AND";
    case L_NOT:
        return "NOT";
    case EQ:
        return "EQUALS";
    case NEQ:
        return "NOT EQUALS";
    default:
        throw std::string("unknown operator type");
    }
}
