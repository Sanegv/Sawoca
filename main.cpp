/**
 * @file main.cpp
 * @brief Interactive calculator with variables.
 *
 * @author Bjarne Stroustrup
 * @author Sanegv
 */
#include <string>
#include <map>
#include <iostream>
#include <sstream>

/**
 * @brief The different values a lexer token can have.
 */
enum Token_Value{
	NAME, ///< The name of a variable
	NUMBER, ///< A litteral double
	END, ///< The end of the stream to parse
	PLUS = '+', ///< An addition
	MINUS = '-', ///< A subtraction
	MUL = '*', ///< A multiplication
	DIV = '/', ///< A division
	PRINT = ';', ///< Printing 
	ASSIGN = '=', ///< An assignment
	LP = '(', ///< Beginning of a paranthesis
	RP = ')' ///< End of a paranthesis
};

//current token value \cond PRIVATE
double number_value; 
std::string string_value;
Token_Value curr_tok = PRINT;

//store execution variables
std::map<std::string, double> table;

// program variables
int number_of_errors = 0;
std::istream* input;
//\endcond

/**
 * @brief Adds or subtracts numbers and expressions, and calls @ref 
 * term() for the rest.
 *
 * @param get A boolean that tells the function whether or not to get the next
 * token.
 * @return The result of the expression.
 */
double expr(bool get);

/**
 * @brief Prints the error to stderr and increments the global error counter.
 *
 * @param e A string that will be printed to stderr.
 *
 * @return 1.0, as to prevent further errors from happening.
 */
double error(std::string e){
	number_of_errors++;
	std::cerr << "Error: " << e << "\n";
	return 1;
}

/**
 * @brief Parses the next token in the input stream, updates the token type 
 * global variable, and the token value in case of a number or name.
 *
 * @return The token type.
 */
Token_Value get_token(){
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
		return curr_tok = PRINT;

	//operators
	case '+': case '-':	case '*': case '/':	case '(': case ')':	case '=':
		return curr_tok = Token_Value(ch);

	default:
		//number
		if(isdigit(ch) || ch == '.'){
			input->putback(ch);
			*input >> number_value;
			return curr_tok = NUMBER;
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
			return curr_tok = NAME;
		}
		error("wrong keyword");
		return curr_tok = PRINT;
	}
}

/**
 * @brief Parses a primary expression and returns its value.
 * Calls @ref expr() to parse paranthesis expressions, and returns an 
 * @ref error() in case of a wrong parameter or an unclosed paranthesis.
 *
 * @param get A boolean that tells the function whether or not to get the next
 * token
 *
 * @return The value of the primary expression
 */
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
	case PLUS:
		return prim(true);
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

/**
 * @brief Multiplies or divides numbers and expressions, and calls @ref 
 * prim() for the rest. Raises an @ref error() in case of 
 * a division by zero.
 *
 * @param get A boolean that tells the function whether or not to get the next
 * token.
 * @return The result of the expression.
 */

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

	return left;
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

	return left;
}

int main(int argc, char* argv[]){

	//choose the input mode
	switch(argc){
		case 1:
			input = &std::cin;
			break;
		default:
			input = new std::istringstream(argv[1]);
			break;
	}

	//define default variables
	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;

	// main loop
	while(*input){
		get_token(); //
		if(curr_tok == END)
			break;
		if(curr_tok == PRINT)
			continue;
		std::cout << expr(false) << "\n";
	}

	//clean exit
	if(input != &std::cin)
		delete input;
	return number_of_errors;
}
