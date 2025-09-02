#include "../headers/Lexer.h"
#include "../../tokens/headers/EndToken.h"
#include "../../tokens/headers/NameToken.h"
#include "../../tokens/headers/ValueToken.h"
#include "../../tokens/headers/OperatorToken.h"
#include "../../tokens/headers/PrintToken.h"
#include "../../tokens/headers/LeftParToken.h"
#include "../../tokens/headers/RightParToken.h"
#include "../../tokens/headers/AssignToken.h"
#include "../../values/headers/Double.h"
#include "../../values/headers/Bool.h"
#include <vector>

using namespace Sawoca;

Language::Tokens::TokenI* Lexer::get_token(){
	char ch;
	double number_value;
	std::string string_value;

	//consume whitespaces
	do {
		if(!input.get(ch))
			return new End_Token();
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case 0:
		return new End_Token();

	//printing
	case '\n': case ';':
		return new Print_Token();

	//operators
	case '+': case '-':	case '*': case '/':
		return new Operator_Token(ch);

	//Paranthesis
	case '(':
		return new LeftPar_Token();
	case ')':
		return new RightPar_Token();
	
	case '=':
		if(input.peek() == '='){
			input.get(ch); //consume '=='
			return new Operator_Token(EQ);
		}
		return new Assign_Token();

	case '!':
		if(input.peek() == '='){
			input.get(ch); //consume '!='
			return new Operator_Token(NEQ);
		}
		return new Operator_Token(L_NOT);

	case '<':
		if(input.peek() == '='){
			input.get(ch); //consume '<='
			return new Operator_Token(LESS_EQ);
		}
		return new Operator_Token(LESSER);

	case '>':
		if(input.peek() == '='){
			input.get(ch); //consume '>='
			return new Operator_Token(GREAT_EQ);
		}
		return new Operator_Token(GREATER);

	case '|':
		if(input.get() != '|')
			throw "invalid operator \'|\'";
		return new Operator_Token(L_OR);

	case '&':
		if(input.get() != '&')
			throw "invalid operator \'&\'";
		return new Operator_Token(L_AND);

	default:
		//value
		if(isdigit(ch) || ch == '.'){
			input.putback(ch);
			input >> number_value;
			return new Value_Token(new Double(number_value));
		}

		//name
		if(isalpha(ch)){
			string_value = ch;
			while(input.get(ch) && isalnum(ch))
				string_value.push_back(ch);
			input.putback(ch);

			//exit
			if(string_value == "exit")
				return new End_Token();

			//booleans
			if(string_value == "true")
				return new Value_Token(new Bool(true));			
			if(string_value == "false")
				return new Value_Token(new Bool(false));

			return new Name_Token(string_value, variables);
		}

		throw std::string("wrong keyword");
	}
}

Lexer::Lexer(
		std::map<std::string, const Value*>& variables,
		std::istream& input
) : variables(variables), input(input){}

std::vector<Language::Tokens::TokenI*> Lexer::lex(){
	std::vector<Language::Tokens::TokenI*> tokens;
		if(!input){
			Token* tok = new End_Token();
			if(!tok){
				for(Language::Tokens::TokenI* tok : tokens)
					delete tok;
				throw std::string("memory allocaiton failed");
			}				
			tokens.push_back(tok);
			return tokens;
		}
	while(true){
		Token* tok = dynamic_cast<Token*>(get_token());
		if(!tok){
			for(Language::Tokens::TokenI* tok : tokens)
				delete tok;
			throw std::string("memory allocation failed");
		}
		tokens.push_back(tok);
		if(tok->get_type() == END || tok->get_type() == PRINT)
			return tokens;
	}

	return tokens;
}
