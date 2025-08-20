#ifndef DEFINE_LEXER
#define DEFINE_LEXER

#include <string>
#include <sstream>
#include <iostream>

#include "../../../interfaces/parser/LexerInterface.h"
#include "../../tokens/headers/Token.h"
#include "../../../interfaces/tokens/TokenFactoryInterface.h"

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
	class Lexer : public Language::Parser::LexerI {
	private:		
		Language::Tokens::TokenI* curr_tok;
		double number_value; 
		std::string string_value;
		std::istream* input;

		//don't use (yet)
		Lexer(const Lexer&) = delete;
		Lexer& operator=(const Lexer&) = delete;

	public:
		/**
		* @brief Creates a new Lexer that will read stdin with the default
		* Sawoca Token Factory.
		*/
		Lexer();

		/**
		* @brief Creates a new Lexer that will read the given input stream with 
		* the default Sawoca Token Factory.
		*
		* @param input A pointer to an input stream.
		*/
		Lexer(std::istream* input);

		/**
		 * @brief Creates a new lexer that will read stdin and use the given
		 * Token Factory.
		 *
		 * @param factory A pointer to the factory to use.
		 */
		Lexer(Language::Tokens::TokenFactoryI* factory);

		/**
		 * @brief Creates a new lexer that will read the given input stream and
		 * use the given Token Factory
		 *
		 * @param input A pointer to an input stream.
		 * @param factory A pointer to the factory to use.
		 *
		 */
		Lexer(std::istream* input, Language::Tokens::TokenFactoryI* factory);

		/**
		* @brief The destructor will free the input stream if it's not stdin.
		*/
		~Lexer();

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
		Language::Tokens::TokenI* get_token() override;

		/**
		* @brief Accessor of the current token field.
		*
		* @return a copy ofthe last token that was lexed.
		*/
		Token_Type get_curr_tok() const;

		/**
		* @brief Accessor of the current string value for @ref NAME tokens.
		*
		* @return a copy of the value of the last @ref NAME token that was 
		* lexed.
		 */
		std::string get_string_val() const;

		/**
		* @brief Accessor of the current double value for @ref NUMBER tokens.
		*
		* @return a copy of the value of the last @ref NUMBER token that was lexed.
		 */
		double get_num_val() const;
	};
}

#endif
