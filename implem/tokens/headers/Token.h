#ifndef DEFINE_SAWOCA_TOKEN
#define DEFINE_SAWOCA_TOKEN

#include "../../../interfaces/values/ValueInterface.h"
#include "../../../interfaces/tokens/TokenInterface.h"
#include <string>

namespace Sawoca {
    /**
 	* @brief The different values a lexer token can have.
 	*/
	enum Token_Type{
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

    /**
	 * @brief Represents a parser token, with a type and a value. It's a 
	 * composite pattern that can either be a literal value, a variable or an 
	 * operation.
	 */
	class Token : public Language::Tokens::TokenI {
	private:
		Token_Type type;
		Token() = delete;
	public:
		/**
		 * @brief Creates a new token of the specified type. Can only be used 
		 * in subclasses that inherit Token.
		 *
		 * @param the type of the token.
		 */
		Token(Token_Type type) : type(type) {};
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
		 * Evaluates the value of a token, whether by simply returning it, or 
		 * by recursively evaluating the value of its branches in the AST.
		 *
		 * @return the evaluated value of the token and its branches in the AST.
		 */
		virtual const Language::Values::ValueI* get_value() const override = 0;
	};
}

#endif