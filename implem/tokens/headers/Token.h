#ifndef DEFINE_SAWOCA_TOKEN
#define DEFINE_SAWOCA_TOKEN

#include "../../../interfaces/values/ValueInterface.h"
#include "../../../interfaces/tokens/TokenInterface.h"
#include <string>

/**
 *@file Token.h
 *@brief This file defines the abstract Token class, from which every token 
 * inherits, as well as the different token types.
 *@author Sanegv
 */

namespace Sawoca {
    /**
 	* @brief The different types of lexer tokens that exist.
 	*/
	enum Token_Type{
		NAME, ///< The name of a variable
		VALUE, ///< A litteral double
		L_OR, ///< A logical "or"
		L_AND, ///< A logical "and"
		L_NOT, ///< A logical "not"
		END, ///< The end of the stream to parse
		PLUS = '+', ///< An addition
		MINUS = '-', ///< A subtraction
		MUL = '*', ///< A multiplication
		DIV = '/', ///< A division
		PRINT = ';', ///< The end of an expression
		ASSIGN = '=', ///< An assignment
		LP = '(', ///< Beginning of a Par
		RP = ')' ///< End of a Par
	};

    /**
	 * @brief Represents a lexer token, with a type and a few methods. It 
	 * inherits from the \ref TokenI interface.
	 */
	class Token : public Language::Tokens::TokenI {
	private:
		Token_Type type;
		Token() = delete;

	protected:
		/**
		 * @brief Creates a new token of the specified type. Can only be used 
		 * in subclasses that inherit Token.
		 *
		 * @param type the type of the token.
		 */
		Token(Token_Type type) : type(type) {};

	public:
		/**
		 * @brief A standard destructor used for polymorhism.
		 */
		virtual ~Token() = default;

		/**
		 * @brief Accessor for the type field of a token.
		 *
		 * @return the type of the token.
		 */
		Token_Type get_type() const {return type;}

		/**
		* @brief Accessor for the type field of a token, in human readable form.
		*
		* @return the name of the type of the token.
		*/
		virtual std::string get_string_type() const = 0;

		/**
		 * Accessor of the value of a token if it has one, or returns an
		  exception if reading a value would make no sense.
		 *
		 * @return the value of the token, if it has one.
		 */
		virtual const Language::Values::ValueI* get_value() const override = 0;
	};
}

#endif