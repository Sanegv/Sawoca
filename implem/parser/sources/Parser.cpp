#include "../headers/Parser.h"
#include "../../tokens/headers/Token.h"
#include "../../values/headers/Double.h"
#include "../../values/headers/Value.h"
#include "../../tokens/headers/NameToken.h"
#include <vector>
#include <iostream>

using namespace Sawoca;

//\cond PRIVATE
Token* cast_token(std::vector<Language::Tokens::TokenI*>::iterator it){
    Token* tok = dynamic_cast<Token*>(*it);
    if(!tok)
        throw std::string("unhandled token type");
    return tok;
}

Value* cast_to_value(Value* v){
    if(!v)
        throw std::string("nullptr dereference");

    Value* vp = dynamic_cast<Value*>(v);
    if(!vp)
        throw std::string("unknown type");

    return vp;
}

const Double* cast_to_double(const Value* const v){
    if(!v)
        throw std::string("nullptr dereference");

    const Double* const dp = dynamic_cast<const Double* const>(v);
    if(!dp)
        throw std::string("unknown type");

    return dp;
}



std::string get_name(Language::Tokens::TokenI* tok){
    if(!tok){
        throw std::string("nullptr dereference");
	}

	Name_Token* ntok = dynamic_cast<Name_Token*>(tok);
	if(!ntok)
		throw std::string("unknown type");
	return ntok->get_name();
}
//\endcond

Parser::Parser(
		std::map<std::string, const Value*>& variables
) : table(variables) {}

Value* Parser::prim(
    bool get,
    std::vector<Language::Tokens::TokenI*>::iterator& it
){
	if(get)
		it++;

    Token* tok = cast_token(it);

	switch(tok->get_type()) {
	case NUMBER:
	{
		const Value* val = dynamic_cast<const Value*>(tok->get_value());
		const Double* v = cast_to_double(val);
		it++;
		Double* d = new Double(v->get_val());
		if(!d)
			throw std::string("memory allocation failed");
		return d;
	}
	case NAME:{
		std::string name = get_name(tok);
        it++;
		tok = cast_token(it);

		//assignment
		if(tok->get_type() == ASSIGN){
			const Double* right = cast_to_double(expr(true, it));
			if(const Value* v = table[name]){
				table.erase(table.find(name));
				delete v;
			}
			table[name] = right;
		}

		if(!table[name])
			throw std::string("unknown variable \"" + name + "\"");
		Double* d = new Double(cast_to_double(table[name])->get_val());
		if(!d)
			throw std::string("memory allocation failed");
		return d;
	}
	case MINUS:{
		Value* val = cast_to_value(prim(true, it));
		Value* result = -(*val);
		delete val;
		return result;
	}
	case PLUS:
		return prim(true, it);
	case LP:{
		Value* e = expr(true, it);
		if(cast_token(it)->get_type() != RP)
			throw std::string("expected ')'");

		it++;
		return e;
	}
	default:
		throw std::string("expected primary");
	}
}

Value* Parser::term(
    bool get,
    std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Value* left = prim(get, it);
	Value* right = nullptr;

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case MUL:
			right = prim(true, it);
			*left *= *right;
			delete right;
			break;
		case DIV:
			right = prim(true, it);
            *left /= *right;
			delete right;
            break;
		default:
			return left;
		}
	}
}

Value* Parser::expr(
    bool get, 
    std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Value* left = term(get, it);
	Value* right = nullptr;

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case PLUS:
			right = term(true, it);
			*cast_to_value(left) += *right;
			delete right;
			break;
		case MINUS:
			right = term(true, it);
			*cast_to_value(left) -= *right;
			delete right;
			break;
		default:
			return left;
		}
	}
}

void Parser::parse(std::vector<Language::Tokens::TokenI*> tokens){
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
		Value* eval = expr(false, it);
        std::cout << cast_to_value(eval)->string() << "\n";
		delete eval;
	}
}
