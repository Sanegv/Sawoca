#ifndef DEFINE_SAWOCA_VALUE_TOKEN
#define DEFINE_SAWOCA_VALUE_TOKEN

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"
#include "../../values/headers/Value.h"

/**
 *@file NumberToken.h
 *@brief This file defines the number Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for a literal, double value. It
	 inherits from the \ref Token abstract class.
	*/
	class Value_Token : public Token {
	private:
		Value* value;

	public:
		/**
		 * @brief Creates a number token with the specified value.
		 *
		 * @param value a pointer to a Value. \note the value will be freed at
		 * the end of the token's life.
		 */
		Value_Token(Value* value);

		/** 
		* @brief Deletes the token and clears its value.
		*/
		~Value_Token();

		/**
		 * @brief Accessor for the litteral value of a value_token.
		 *
		 * @return the value stored in the token.
		 */
		virtual const Value* get_value() const override;

		/**
		 * @brief Accessor for the type of the value stored.
		 * @return the type of the actual value in the token.
		 */
		Value_Type get_value_type() const;

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "NUMBER" 
         */
		virtual std::string get_string_type() const override;
	};
}

#endif