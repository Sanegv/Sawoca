/**
 * @file main.cpp
 * @brief Instantiates a parser depending on the input, and calls it.
 *
 * @author Bjarne Stroustrup
 * @author Sanegv
 */

#include "../headers/lexer.h"
#include "../headers/parser.h"


int main(int argc, char* argv[]){
	//choose the input mode
	Calc::Lexer* lexer;
	switch(argc){
		case 1:
			lexer = new Calc::Lexer(&std::cin);
			break;
		default:
			lexer = new Calc::Lexer(new std::istringstream(argv[1]));
			break;
	}
	if(!lexer)
		return 1;

	Calc::Parser parser = Calc::Parser(lexer);

	// main loop
	return parser.parse(); //lexer is deleted by parser
}
