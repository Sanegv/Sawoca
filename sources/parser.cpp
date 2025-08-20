#include "../headers/parser.h"
#include "../headers/lexer.h"

//\cond PRIVATE
void init_table(std::map<std::string, double>* table){
	if(table){
		(*table)["pi"] = 3.1415926535897932385;
		(*table)["e"]  = 2.7182818284590452354;
	}
}
//\endcond

Calc::Parser::Parser() : lexer(new Calc::Lexer()) {
	init_table(&table);
}

Calc::Parser::Parser(Calc::Lexer* l) : lexer(l) {
	init_table(&table);
}

Calc::Parser::~Parser() {
	delete lexer;
}


double Calc::Parser::prim(bool get){
	if(get)
		lexer->get_token(this, &Parser::error);

	switch(lexer->get_curr_tok()) {
	case Calc::NUMBER:
	{
		double v = lexer->get_num_val();
		lexer->get_token(this, &Parser::error);
		return v;
	}
	case Calc::NAME: 
	{
		double& v = table[lexer->get_string_val()];
		if(lexer->get_token(this, &Parser::error) == Calc::ASSIGN)
				v = expr(true);
		return v;
	}
	case Calc::MINUS:
		return -prim(true);
	case Calc::PLUS:
		return prim(true);
	case Calc::LP:
	{
		double e = expr(true);
		if(lexer->get_curr_tok() != Calc::RP)
			return error("expected ')'");

		lexer->get_token(this, &Parser::error); //consume ')'
		return e;
	}
	default:
		return error("expected primary");
	}
}

double Calc::Parser::term(bool get){
	double left = prim(get);

	while(true){
		switch(lexer->get_curr_tok()){
		case Calc::MUL:
			left *= prim(true);
			break;
		case Calc::DIV:
			if(double d = prim(true)) { //if != 0
				left /= d;
				break;
			}
			return error("division by 0");
		default:
			return left;
		}
	}

	return left;
}

double Calc::Parser::expr(bool get){
	double left = term(get);

	while(true){
		switch(lexer->get_curr_tok()){
		case Calc::PLUS:
			left += term(true);
			break;
		case Calc::MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
	}

	return left;
}

double Calc::Parser::error(std::string e){
	number_of_errors++;
	std::cerr << "Error: " << e << "\n";
	return 1;
}

int Calc::Parser::parse(){
	while(true){
		lexer->get_token(this, &Parser::error);
		if(lexer->get_curr_tok() == Calc::END)
			break;
		if(lexer->get_curr_tok() == Calc::PRINT)
			continue;
		std::cout << expr(false) << "\n";
	}

	return number_of_errors;
}