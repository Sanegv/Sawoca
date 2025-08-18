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

Calc::Token::Token(Calc::Token_Type type) : type(type) {}

Calc::Token_Type Calc::Token::get_type(){
	return type;
}

Calc::Number_Token::Number_Token() : Token(Calc::NUMBER), value(0.0) {}
Calc::Number_Token::Number_Token(double value) : 
	Token(Calc::NUMBER), value(value) {}

double Calc::Number_Token::get_value(){
	return value;
}

Calc::Name_Token::Name_Token(
		std::string name, std::map<std::string, double>& variables
		) : Token(Calc::NAME), name(name), variables(variables) {}

double Calc::Name_Token::get_value(){
	return variables[name];
}

Calc::Operator_Token::Operator_Token(
	char op, 
	std::unique_ptr<Operator_Token> LHS,
	std::unique_ptr<Operator_Token> RHS
) : Token(op), op(op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}

double Calc::Operator_Token::get_value() {
	switch(op){
	case '+':
		return LHS->get_value() + RHS->get_value();
	case '-':
		return LHS->get_value() - RHS->get_value();
	case '*':
		return LHS->get_value() * RHS->get_value();
	case '/':
		double right = RHS->get_value();
		if(!right)
			throw "dibision by zero";
		return LHS->get_value() / right;
