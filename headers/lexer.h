#ifndef DEFINE_LEXER
#define DEFINE_LEXER

#include <string>
#include <sstream>
#include <iostream>

/**
 *@file lexer.h
 *@brief This file contains the lexer class and mehtods,
 * as well as the tokens it can return.
 *@author Sanegv
 */

namespace Calc {
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

	class Parser;

	/**
	* @brief The lexer class is responsible for reading an input stream and return tokens.
	*/
	class Lexer {
	private:		
		Token_Value curr_tok = PRINT;
		double number_value; 
		std::string string_value;
		std::istream* input;

		//don't use (yet)
		Lexer(const Lexer&) = delete;
		Lexer& operator=(const Lexer&) = delete;

	public:
		/**
		* @brief Creates a new Lexer that will read stdin.
		*/
		Lexer();

		/**
		* @brief Creates a new Lexer that will read the given input stream.
		*
		* @param input A pointer to an input stream.
		*/
		Lexer(std::istream* input);

		/**
		* @brief The destructor will free the input stream if it's not stdin.
		*/
		~Lexer();

		/**
		* @brief Parses the next token in the input stream, updates the token type 
		* global variable, and the token value in case of a number or name.
		*
		* @param parser The parser that will call error.
		* @param error A function with prototype `double error(std::string)` that will handle errors.
		*
		* @return The token type.
		*/
		Token_Value get_token(Parser* parser, double(Parser::*error)(std::string));

		/**
		* @brief Accessor of the current token field.
		*
		* @return a copy ofthe last token that was lexed.
		*/
		Token_Value get_curr_tok() const;

		/**
		* @brief Accessor of the current string value for @ref NAME tokens.
		*
		* @return a copy of the value of the last @ref NAME token that was lexed.
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
