#include <string>
#include <map>
#include <iostream>
#include <sstream>

enum Token_Value{
	NAME, NUMBER, END,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};

double number_value;
std::string string_value;
std::map<std::string, double> table;
int number_of_errors = 0;
std::istream* input;

Token_Value curr_tok = PRINT;

double expr(bool);

double error(std::string e){
	number_of_errors++;
	std::cerr << "Error: " << e << "\n";
	return 1;
}

Token_Value get_token(){
	char ch;

	do {
		if(!input->get(ch))
			return curr_tok = END;
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case 0:
		return curr_tok = END;
	case '\n':
	case ';':
		return curr_tok = PRINT;
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '=':
		return curr_tok = Token_Value(ch);
	default:
		if(isdigit(ch) || ch == '.'){
			input->putback(ch);
			*input >> number_value;
			return curr_tok = NUMBER;
		}
		if(isalpha(ch)){
			string_value = ch;
			while(input->get(ch) && isalnum(ch))
				string_value.push_back(ch);
			if(string_value == "exit")
				return curr_tok = END;
			input->putback(ch);
			return curr_tok = NAME;
		}
		error("wrong keyword");
		return curr_tok = PRINT;
	}
}

double prim(bool get) {
	if(get)
		get_token();

	switch(curr_tok) {
	case NUMBER:
	{
		double v = number_value;
		get_token();
		return v;
	}
	case NAME: 
	{
		double& v = table[string_value];
		if(get_token() == ASSIGN)
				v = expr(true);
		return v;
	}
	case MINUS:
		return -prim(true);

	case LP:
	{
		double e = expr(true);
		if(curr_tok != RP)
			return error("expected ')'");
		get_token(); //consume ')'
		return e;
	}
	default:
		return error("expected primary");
	}
}

double term(bool get){
	double left = prim(get);

	while(true){
		switch(curr_tok){
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if(double d = prim(true)) { //if != 0
				left /= d;
				break;
			}
			return error("division by 0");
		default:
			return left;
		}
	}
}

double expr(bool get){
	double left = term(get);

	while(true){
		switch(curr_tok){
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}

int main(int argc, char* argv[]){
	switch(argc){
		case 1:
			input = &std::cin;
			break;
		default:
			input = new std::istringstream(argv[1]);
			break;
	}
	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;

	while(*input){
		get_token();
		if(curr_tok == END)
			break;
		if(curr_tok == PRINT)
			continue;
		std::cout << expr(false) << "\n";
	}

	if(input != &std::cin)
		delete input;
	return number_of_errors;
}
