#ifndef DEFINE_SAWOCA_OPERATOR_TOKEN
#define DEFINE_SAWOCA_OPERATOR_TOKEN

#include <string>
#include <map>

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

/**
 *@file OperatorToken.h
 *@brief This file defines the number Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for a binary operation. It is used
	* to know which operation to apply to the values on its sides. It inherits
	* from the \ref Token abstract class.
	*/
	class Operator_Token : public Token {
	private:
		char op;

		//do not use
		Operator_Token() = delete;
		Operator_Token(const Operator_Token&) = delete;
		Operator_Token& operator=(const Operator_Token&) = delete;
	public:

		/**
		 * @brief Creates an operator token for the specified operation.
		 *
		 * @param op the character representiong a binary operation.
		 */
		Operator_Token(char op);

        /**
         * @brief throws an exception, as the LP token does not hold a value.
         */
		virtual const Language::Values::ValueI* get_value() const override;

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "OPERATOR" 
         */
		virtual std::string get_string_type() const override;
	};
}

#endif
