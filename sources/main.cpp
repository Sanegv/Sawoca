/**
 * @file main.cpp
 * @brief Instantiates a parser depending on the input, and calls it.
 *
 * @author Bjarne Stroustrup
 * @author Sanegv
 */

#include <fstream>
#include "../headers/lexer.h"
#include "../headers/parser.h"
#include "../implem/tokens/headers/NameToken.h"

/**
 * @brief Prints the help menu.
 */
void help(){
	std::cout << "\n\
#############################################################################\n\
			Welcome to Sanegv's WonderCalc!\n\
#############################################################################\n\
\n\
This wonderful calculator can be used as follows: \n\n \
$ swc \n\
or\n \
$ swc [flags] (optionnal expressions)\n\n\
flags:\n\
    -e, --evaluate <expression>\n\
        Evaluates the specified expression.\n\n\
    -f, --file <path/to/file>\n\
        Tries to evaluate the content of the file at the specified path. You\n\
        can separate different expressions with a semicolon `;`.\n\n\
    -h, --help\n\
        Show the help (this) menu.\n\n\
    -i, --interactive\n\
        Opens the interactive CLI. This is the default mode.\n\n\
-----------------------------------------------------------------------------\n\
\n";
}

/**
 * @brief Parses the arguments of the program to choose a mode.
 *
 * @param argc the count of the program's passed arguments (including the 
 * program's name)
 * @param argv the value of the program's arguments.
 *
 * @return the mode with which the program should run.
 */
char flags(int argc, char* argv[]){
	if(argc == 0)
		return 0;

	if(argc == 1 || std::string(argv[1]) == "-i" || std::string(argv[1]) == "--interactive")
		return 'i';

	if(std::string(argv[1]) == "-e" || std::string(argv[1]) == "--evaluate")
		return 'e';

	if(std::string(argv[1]) == "-f" || std::string(argv[1]) == "--file")
		return 'f';

	if(std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")
		return 'h';

	return 0;
}

int main(int argc, char* argv[]){

	std::map<std::string, double> table;
	table["test"] = 4.2;
	Sawoca::Token* tok = new Sawoca::Name_Token("test", table);
	std::cout << tok->get_value() << " " << tok->get_string_type() << "\n";
	delete tok;

	return 0;

	//choose the input mode
	Calc::Lexer* lexer;
	switch(flags(argc, argv)){
		case 'i':
			lexer = new Calc::Lexer(&std::cin);
			break;
		case 'e':
			lexer = new Calc::Lexer(new std::istringstream(argv[2]));
			break;
		case 'f': {
				std::ifstream* f = new std::ifstream(argv[2]);
				if(!f->is_open()){
					std::cerr << "Error: cannot open file. Using default\
interactive mode instead.\n";
					lexer = new Calc::Lexer(&std::cin);
				} else
					lexer = new Calc::Lexer(f);
			}
			break;
		case 'h':
			help();
			return 0;
		default:
			std::cerr << "Error: unknown flag \"" << argv[1] << ". Using \
default interactive mode instead.\n"; 
			lexer = new Calc::Lexer(&std::cin);
			break;
	}
	if(!lexer)
		return 1;

	Calc::Parser parser = Calc::Parser(lexer);

	// main loop
	return parser.parse(); //lexer is deleted by parser
}
