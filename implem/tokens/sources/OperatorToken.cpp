#include <memory>
#include "../headers/OperatorToken.h"

using namespace Sawoca;


Operator_Token::Operator_Token(
    char op, 
    std::unique_ptr<Operator_Token> LHS,
    std::unique_ptr<Operator_Token> RHS
) : Token(static_cast<Token_Type>(op)),
    op(op),
    LHS(std::move(LHS)), 
    RHS(std::move(RHS)) {
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
    switch (op) {    
		case '+': 
            return *LHS->get_value() + RHS->get_value();
		case '-': 
            return *LHS->get_value() - RHS->get_value();
		case '*': 
            return *LHS->get_value() * RHS->get_value();
		case '/': 
            return *LHS->get_value() / RHS->get_value();
    }
    return LHS->get_value() ;
}

std::string Operator_Token::get_string_type() const {
    return "OPERATOR";
}