#include "../headers/Parser.h"
#include "../../tokens/headers/Token.h"
#include "../../values/headers/Double.h"
#include "../../values/headers/Value.h"
#include <vector>
#include <iostream>

using namespace Sawoca;

//\cond PRIVATE
void init_table(std::map<std::string, Language::Values::ValueI*>* table){
	if(table){
		(*table)["pi"] = new Double(3.1415926535897932385);
		(*table)["e"]  = new Double(2.7182818284590452354);
	}
}

Token* cast_token(std::vector<Language::Tokens::TokenI*>::iterator it){
    Token* tok = dynamic_cast<Token*>(*it);
    if(!tok)
        throw "unhandled token type";
    return tok;
}

const Double* const cast_to_double(const Language::Values::ValueI* const v){
    if(!v)
        throw "nullptr dereference";

    const Double* const dp = dynamic_cast<const Double* const>(v);
    if(!dp)
        throw "unknown type";

    return dp;
}
//\endcond

Parser::Parser(
		std::map<std::string, Language::Values::ValueI*>& variables
) : table(variables) {
	init_table(&table);
}

Language::Values::ValueI* Parser::prim(
    bool get,
    std::vector<Language::Tokens::TokenI*>::iterator& it
){
	if(get)
		it++;

    Token* tok = cast_token(it);

	switch(tok->get_type()) {
	case NUMBER:
	{
		const Double* v = cast_to_double(tok->get_value());
		it++;
		return new Double(v->get_val());
	}
	case NAME: 
	{
		const Double* v = dynamic_cast<const Double*>(tok->get_value());
        it++;
		if(tok->get_type() == ASSIGN)
				v = cast_to_double(expr(true, it));
		return new Double(v->get_val());
	}
	case MINUS:
		return -(*prim(true, it));
	case PLUS:
		return prim(true, it);
	case LP:
	{
		Language::Values::ValueI* e = expr(true, it);
		if(cast_token(it)->get_type() != RP)
			throw "expected ')'";

		it++;
		return e;
	}
	default:
		throw "expected primary";
	}
}

Language::Values::ValueI* Parser::term(
    bool get,
    std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Language::Values::ValueI* left = prim(get, it);

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case MUL:
			*left *= *prim(true, it);
			break;
		case DIV:
            *left /= *prim(true, it);
            break;
		default:
			return left;
		}
	}
}

Language::Values::ValueI* Parser::expr(
    bool get, 
    std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Language::Values::ValueI* left = term(get, it);

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case PLUS:
			*left += *term(true, it);
			break;
		case MINUS:
			*left -= *term(true, it);
			break;
		default:
			return left;
		}
	}
}

int Parser::parse(std::vector<Language::Tokens::TokenI*> tokens){
    for(
        std::vector<Language::Tokens::TokenI*>::iterator it = tokens.begin();
        it != tokens.end();
        it++
    ){
        Token* tok = cast_token(it);
		if(tok->get_type() == END)
			break;
		if(tok->get_type() == PRINT)
			continue;
        std::cout << static_cast<Value*>(expr(false, it))->string() << "\n";
	}

	return number_of_errors;
}
