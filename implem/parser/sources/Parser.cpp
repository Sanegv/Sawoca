#include "../headers/Parser.h"
#include "../../tokens/headers/Token.h"
#include "../../values/headers/Double.h"
#include "../../values/headers/Bool.h"
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

const Bool* cast_to_bool(const Value* const v){
    if(!v)
        throw std::string("nullptr dereference");

    const Bool* const bp = dynamic_cast<const Bool* const>(v);
    if(!bp)
        throw std::string("unknown type");

    return bp;	
}

Value* copy_val(const Value* val){
	switch (val->get_type()) {
		case DOUBLE:{
			const Double* v = cast_to_double(val);
			Double* d = new Double(v->get_val());
			if(!d)
				throw std::string("memory allocation failed");
			return d;
		}
		case BOOL:{
			const Bool* v = cast_to_bool(val);
			Bool* b = new Bool(v->get_val());
			if(!b)
				throw std::string("memory allocation failed");
			return b;
		}
		default:
			throw std::string("unknown type");
	}
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
	case VALUE:
	{
		const Value* val = dynamic_cast<const Value*>(tok->get_value());
		it++;
		return copy_val(val);	
	}
	case NAME:{
		std::string name = get_name(tok);
        it++;
		tok = cast_token(it);

		//assignment
		if(tok->get_type() == ASSIGN){
			const Double* right = cast_to_double(logical(true, it));
			if(const Value* v = table[name]){
				table.erase(table.find(name));
				delete v;
			}
			table[name] = right;
		}

		if(!table[name])
			throw std::string("unknown variable \"" + name + "\"");
		const Value* val = dynamic_cast<const Value*>(tok->get_value());
		return copy_val(val);
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
		Value* e = logical(true, it);
		if(cast_token(it)->get_type() != RP)
			throw std::string("expected ')'");

		it++;
		return e;
	}
	case L_NOT:{
		Value* val = cast_to_value(prim(true, it));
		Value* result = !(*val);
		delete val;
		return result;
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

Value* Parser::relational(
	bool get, 
	std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Value* left = expr(get, it);
	Value* right = nullptr;

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case LESSER:{
			right = expr(true, it);
			Value* tmp = *cast_to_value(left) < *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		case LESS_EQ:{
			right = expr(true, it);
			Value* tmp = *cast_to_value(left) <= *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		case GREATER:{
			right = expr(true, it);
			Value* tmp = *cast_to_value(left) > *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		case GREAT_EQ:{
			right = expr(true, it);
			Value* tmp = *cast_to_value(left) >= *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		default:
			return left;
		}
	}
}


Value* Parser::equality(
	bool get, 
	std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Value* left = relational(get, it);
	Value* right = nullptr;

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case EQ:{
			right = relational(true, it);
			Value* tmp = *cast_to_value(left) == *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		case NEQ:{
			right = relational(true, it);
			Value* tmp = *cast_to_value(left) != *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		default:
			return left;
		}
	}
}

Value* Parser::logical(
	bool get, 
	std::vector<Language::Tokens::TokenI*>::iterator& it
){
	Value* left = equality(get, it);
	Value* right = nullptr;

	while(true){
        Token* tok = cast_token(it);
		switch(tok->get_type()){
		case L_OR:{
			right = equality(true, it);
			Value* tmp = *cast_to_value(left) || *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
		case L_AND:{
			right = equality(true, it);
			Value* tmp = *cast_to_value(left) && *right;
			delete right;
			delete left;
			left = tmp;
			break;
		}
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
		Value* eval = logical(false, it);
        std::cout << cast_to_value(eval)->string() << "\n";
		delete eval;
	}
}
