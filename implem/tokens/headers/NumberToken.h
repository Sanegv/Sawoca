#ifndef DEFINE_SAWOCA_NUMBER_TOKEN
#define DEFINE_SAWOCA_NUMBER_TOKEN

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

namespace Sawoca {
    /**
	 * @brief Token class of literal numeric values.
	 */
	class Number_Token : public Token {
	private:
		Language::Values::ValueI* value;
	public:
		/**
		 * @brief Creates a number_token with value 0.0.
		 */
		Number_Token();

		/**
		 * @brief Creates a number_token with the specified value.
		 *
		 * @param value a double used to create a new Value.
		 */
		Number_Token(double value);

		/**
		 * @brief Creates a number_token with the specified value.
		 *
		 * @param value a pointer to a Value. \note the value will be freed at
		 * the end of the token's life.
		 */
		Number_Token(Language::Values::ValueI* value);

		/** 
		* @brief Deletes the token and clear its value.
		*/
		~Number_Token();

		/**
		 * @brief Accessor for the litteral value of a number_token;
		 *
		 * @return the value stored in the token.
		 */
		virtual const Language::Values::ValueI* get_value() const override;
		virtual std::string get_string_type() const override;
	};
}

#endif