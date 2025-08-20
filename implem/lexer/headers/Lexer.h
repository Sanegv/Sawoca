#ifndef DEFINE_LEXER
#define DEFINE_LEXER

#include <string>
#include <map>
#include <sstream>
#include <iostream>

#include "../../../interfaces/lexer/LexerInterface.h"
#include "../../tokens/headers/Token.h"

/**
 *@file lexer.h
 *@brief This file contains the lexer class and mehtods,
 * as well as the tokens it can return.
 *@author Sanegv
 */

namespace Sawoca {
	class Parser;

	/**
	* @brief The lexer class is responsible for reading an input stream and 
	* returning tokens.
	*/
	class Lexer : public Language::Lexer::LexerI {
	private:		
		std::map<std::string, Language::Values::ValueI*>& variables;
		std::istream* input;

		//don't use (yet)
		Lexer(const Lexer&) = delete;
		Lexer& operator=(const Lexer&) = delete;
		Lexer() = delete;

	public:
		/**
		* @brief Creates a new Lexer that will read stdin and use the given
		* variables map.
		*
		* @param variables The map of the variables that will be passed to 
		* Variables Tokens.
		*/
		Lexer(std::map<std::string, Language::Values::ValueI*>& variables);

		/**
		* @brief Creates a new Lexer that will read the given input stream and
		* use the given variables map.
		*
		* @param variables The map of the variables that will be passed to 
		* Variables Tokens.
		* @param input A pointer to an input stream.
		*/
		Lexer(
			std::map<std::string, Language::Values::ValueI*>& variables, 
			std::istream* input
		);

		/**
		* @brief The destructor will free the input stream if it's not stdin.
		*/
		~Lexer();


		/**
		 *itodo
		 */
		virtual std::vector<Language::Tokens::TokenI*> lex() override;

		/**
		* @brief Parses the next token in the input stream, updates the tokens
		* type global variable, and the token value in case of a number or 
		* name.
		*
		* @param parser The parser that will call error.
		* @param error A function with prototype `double error(std::string)`
		* that will handle errors.
		*
		* @return The token type.
		*/
		Language::Tokens::TokenI* get_token();
	};
}

#endif
