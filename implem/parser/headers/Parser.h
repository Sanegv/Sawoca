#ifndef DEFINE_PARSER
#define DEFINE_PARSER

/**
 *@file Parser.h
 *@brief This file defines the parser class and methods.
 *@author Sanegv
 */

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../../../interfaces/parser/ParserInterface.h"

namespace Sawoca {
	/**
	* @brief The parser class is responsible for reading a vector of tokens and
	* executing them in order. It inherits from the \ref ParserI interface.
	*/
	class Parser : Language::Parser::ParserI {
	private:
		std::map<std::string, const Language::Values::ValueI*>& table;
		int number_of_errors = 0;

		//don't use
		Parser(const Parser&) = delete;
		Parser& operator=(const Parser&) = delete;
		Parser();
	
	public:
		/**
		 * @brief Creates a new parser that will use the given variables.
		 *
		 * @param variables a reference to the map that will store the 
		 * variables.
		 */
		Parser(
			std::map<std::string,
			const Language::Values::ValueI*>& variables
		);

		/**
		* @brief Parses a primary expression and returns its value.
		* Calls @ref expr() to parse Par expressions, and returns an 
		* @ref error() in case of a wrong parameter or an unclosed Par.
		*
		* @param get A boolean that tells the function whether or not to get the
		*  next token.
		* @param it A reference to an iterator over a vector of Tokens to be
		* parsed.
		*
		* @return The value of the primary expression.
		*/
		Language::Values::ValueI* prim(
			bool get,
			std::vector<Language::Tokens::TokenI*>::iterator& it
		);

		/**
		* @brief Multiplies or divides numbers and expressions, and calls @ref 
		* prim() for the rest. Raises an @ref error() in case of 
		* a division by zero.
		*
		* @param get A boolean that tells the function whether or not to get the
		* next token.
		* @param it An iterator over a vector of Tokens to be parsed.
		* @return The result of the expression.
		*/
		Language::Values::ValueI* term(
			bool get,
			std::vector<Language::Tokens::TokenI*>::iterator& it
		);

		/**
		* @brief Adds or subtracts numbers and expressions, and calls @ref 
		* term() for the rest.
		*
		* @param get A boolean that tells the function whether or not to get the
		* next token.
		* @param it An iterator over a vector of Tokens to be parsed.
		* @return The result of the expression.
		*/
		Language::Values::ValueI* expr(
			bool get, 
			std::vector<Language::Tokens::TokenI*>::iterator& it
		);

		/**
		* @brief Parses the vector of tokens until it is closed or ends.
		*
		* @param tokens The vector of Tokens to be parsed.
		*/
		virtual void 
			parse(std::vector<Language::Tokens::TokenI*> tokens) override;
	};
}

#endif
