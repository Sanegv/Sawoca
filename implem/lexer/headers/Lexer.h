#ifndef DEFINE_LEXER
#define DEFINE_LEXER

#include <string>
#include <map>
#include <sstream>
#include <iostream>

#include "../../../interfaces/lexer/LexerInterface.h"
#include "../../tokens/headers/Token.h"

/**
 *@file Lexer.h
 *@brief This file defines the Lexer class and methods.
 *@author Sanegv
 */

namespace Sawoca {
	/**
	* @brief The lexer class is responsible for reading an input stream and 
	* returning tokens. It implements the \ref LexerI interface
	*/
	class Lexer : public Language::Lexer::LexerI {
	private:		
		std::map<std::string, const Language::Values::ValueI*>& variables;
		std::istream& input;

		//don't use
		Lexer(const Lexer&) = delete;
		Lexer& operator=(const Lexer&) = delete;
		Lexer() = delete;

	public:
		/**
		* @brief Creates a new Lexer that will read the given input stream and
		* use the given variables map.
		*
		* @param variables The map of the variables that will be passed to 
		* Variables Tokens.
		* @param input A pointer to an input stream.
		*/
		Lexer(
			std::map<std::string, const Language::Values::ValueI*>& variables, 
			std::istream& input
		);

		/**
		 * @brief Reads the whole stream attribute, and tokenises its content.
		 *
		 * @return a vector of Tokens.
		 */
		virtual std::vector<Language::Tokens::TokenI*> lex() override;

		/**
		* @brief Parses the next token in the input stream, updates the tokens
		* type global variable, and the token value in case of a number or 
		* name.
		*
		* @return a pointer to the polymophic token.
		*/
		Language::Tokens::TokenI* get_token();
	};
}

#endif
