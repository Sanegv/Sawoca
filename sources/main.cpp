/**
 * @file main.cpp
 * @brief Instantiates a parser depending on the input, and calls it.
 *
 * @author Sanegv
 */

#include <exception>
#include <fstream>
#include "../implem/lexer/headers/Lexer.h"
#include "../implem/parser/headers/Parser.h"
#include "../implem/values/headers/Double.h"

static const int MEM_ALLOC_ERR	= -1;
static const int CPP_LEX_ERR 	= 1;
static const int SWC_LEX_ERR 	= 2;
static const int CPP_PAR_ERR 	= 3;
static const int SWC_PAR_ERR 	= 4;

void init_table(std::map<std::string, const Language::Values::ValueI*>* table){
	if(table){
		(*table)["pi"] = new Sawoca::Double(3.1415926535897932385);
		(*table)["e"]  = new Sawoca::Double(2.7182818284590452354);
	}
}

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
    -stream, --file <path/to/file>\n\
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
	std::map<std::string, const Language::Values::ValueI*> variables;
	init_table(&variables);
	std::istream* stream = nullptr;

	//choose the input mode
	switch(flags(argc, argv)){
		case 'i':
			stream = &std::cin;
			break;
		case 'e':
			stream = new std::istringstream(argv[2]);
			break;
		case 'f': {
				std::ifstream* f = new std::ifstream(argv[2]);
				if(!f || !f->is_open()){
					std::cerr << "Error: cannot open file. Using default \
interactive mode instead.\n";
					stream = &std::cin;
				} else
					stream = f;
			}
			break;
		case 'h':
			help();
			return 0;
		default:
			std::cerr << "Error: unknown flag \"" << argv[1] << ". Using \
default interactive mode instead.\n"; 
			stream = &std::cin;
			break;
	}

	if(!stream)
		return MEM_ALLOC_ERR;

	Sawoca::Lexer lexer(variables, *stream);
	std::vector<Language::Tokens::TokenI*> tokens;
	Sawoca::Parser parser(variables);

	do { 
		tokens.clear();

		try {
			tokens = lexer.lex();
		} catch (const std::exception& e) {
			std::cerr << "C++ error during lexing: " << e.what() << ".\n";

			tokens.clear();
			if(stream != &std::cin)
				delete stream;

			return CPP_LEX_ERR;
		} catch (const std::string& e) {
			std::cerr << "Sawoca error during lexing: " << e << ".\n";

			tokens.clear();
			if(stream != &std::cin)
				delete stream;

			return SWC_LEX_ERR;
		}

		try{
			parser.parse(tokens);
		} catch (const std::exception& e) {
			std::cerr << "C++ error during parsing: " << e.what() << ".\n";

			for(Language::Tokens::TokenI* token : tokens)
				delete token;
			variables.clear();
			return CPP_PAR_ERR;
		} catch (const std::string& e) {
			std::cout << "Sawoca error during parsing: " << e << ".\n";

			for(Language::Tokens::TokenI* token : tokens)
				delete token;
			variables.clear();
			return SWC_PAR_ERR;
		}
	} while (
		static_cast<Sawoca::Token*>(tokens.back())->get_type() != Sawoca::END
	);

	variables.clear();
	tokens.clear();
	if(stream != &std::cin)
		delete stream;

	return 0;
}
