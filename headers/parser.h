#ifndef DEFINE_PARSER
#define DEFINE_PARSER

/**
 *@file parser.h
 *@brief This file contains the parser class and mehtod.
 *@author Sanegv
 */

#include <map>
#include <memory>
#include <string>
#include "lexer.h"

namespace Calc {
	/**
	* @brief The parser class is responsible for reading the tokens of its lexer,
	* ordering them in a tree structure (AST) and executing them in order. 
	*/
	class Parser {
	private:
		std::map<std::string, double> table;
		int number_of_errors = 0;
		Lexer* lexer;

		//don't use
		Parser(const Parser&) = delete;
		Parser& operator=(const Parser&) = delete;
	
	public:
		/**
		* @brief Creates a new parser with a new lexer reading stdin. 
		*/
		Parser();

		/**
		* @brief Creates a new parser with the given lexer.
		*/
		Parser(Lexer* l);

		/**
		* @brief Standard destructor for the parser. Note that it will delete its
		* lexer, too. 
		*/
		~Parser();

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
		double prim(bool get);

		/**
		* @brief Multiplies or divides numbers and expressions, and calls @ref 
		* prim() for the rest. Raises an @ref error() in case of 
		* a division by zero.
		*
		* @param get A boolean that tells the function whether or not to get the next
		* token.
		* @return The result of the expression.
		*/
		double term(bool get);

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
		double error(std::string e);

		/**
		* @brief Parses the stream of its lexer until it is closed.
		*
		*@return the number of errors encountered.
		*/
		int parse();
	};
}

#endif
