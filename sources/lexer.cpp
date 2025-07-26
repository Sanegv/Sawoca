#include "../headers/lexer.h"

Calc::Token_Type Calc::Lexer::get_token(Calc::Parser* parser, double(Calc::Parser::*error)(std::string)){
	char ch;

	//consume whitespaces
	do {
		if(!input->get(ch))
			return curr_tok = END;
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case 0:
		return curr_tok = END;

	//printing
	case '\n': case ';':
		return curr_tok = Calc::PRINT;

	//operators
	case '+': case '-':	case '*': case '/':	case '(': case ')':	case '=':
		return curr_tok = Calc::Token_Type(ch);

	default:
		//number
		if(isdigit(ch) || ch == '.'){
			input->putback(ch);
			*input >> number_value;
			return curr_tok = Calc::NUMBER;
		}

		//name
		if(isalpha(ch)){
			string_value = ch;
			while(input->get(ch) && isalnum(ch))
				string_value.push_back(ch);

			//exit
			if(string_value == "exit")
				return curr_tok = END;

			input->putback(ch);
			return curr_tok = Calc::NAME;
		}
		if(parser && error)
			(parser->*error)("wrong keyword");
		return curr_tok = Calc::PRINT;
	}
}


Calc::Lexer::Lexer() : input(&std::cin){}

Calc::Lexer::Lexer(std::istream* input) : input(input) {}

Calc::Lexer::~Lexer(){
	if(input != &std::cin)
		delete input;
}

Calc::Token_Type Calc::Lexer::get_curr_tok() const {
	return curr_tok;
}

std::string Calc::Lexer::get_string_val() const{
	return string_value;
}

double Calc::Lexer::get_num_val() const {
	return number_value;
}
