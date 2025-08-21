#include "../headers/Lexer.h"
#include "../../tokens/headers/EndToken.h"
#include "../../tokens/headers/NameToken.h"
#include "../../tokens/headers/NumberToken.h"
#include "../../tokens/headers/OperatorToken.h"
#include "../../tokens/headers/PrintToken.h"
#include <vector>

using namespace Sawoca;

Language::Tokens::TokenI* Lexer::get_token(){
	char ch;
	double number_value;
	std::string string_value;

	//consume whitespaces
	do {
		if(!input->get(ch))
			return new EndToken();
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case 0:
		return new EndToken();

	//printing
	case '\n': case ';':
		return new PrintToken();

	//operators
	case '+': case '-':	case '*': case '/':	case '(': case ')':	case '=':
		return new Operator_Token(ch);

	default:
		//number
		if(isdigit(ch) || ch == '.'){
			input->putback(ch);
			*input >> number_value;
			return new Number_Token(number_value);
		}

		//name
		if(isalpha(ch)){
			string_value = ch;
			while(input->get(ch) && isalnum(ch))
				string_value.push_back(ch);

			//exit
			if(string_value == "exit")
				return new EndToken();

			input->putback(ch);
			return new Name_Token(string_value, variables);
		}

		throw std::string("wrong keyword");
		return new PrintToken();
	}
}


Lexer::Lexer(std::map<std::string, Language::Values::ValueI*>& variables)
	: variables(variables), input(&std::cin){}

Lexer::Lexer(
		std::map<std::string, Language::Values::ValueI*>& variables,
		std::istream* input
) : variables(variables), input(input){}

Lexer::~Lexer(){
	try{
		delete input;
	} catch (void*){}
}

std::vector<Language::Tokens::TokenI*> Lexer::lex(){
	std::vector<Language::Tokens::TokenI*> tokens;
		if(!input){
			tokens.emplace_back(new EndToken);
			return tokens;
		}
	while(true){
		Token* tok =  static_cast<Token*>(get_token());
		tokens.push_back(tok);
		if(tok->get_type() == END)
			return tokens;
	}

	std::cout << "lexing complete.\n";
	return tokens;
}