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
		double value;
	public:
		/**
		 * @brief Creates a number_token with value 0.0.
		 */
		Number_Token();

		/**
		 * @brief Creates a number_token with the specified value.
		 */
		Number_Token(double value);
		~Number_Token() = default;

		/**
		 * @brief Accessor for the litteral value of a number_token;
		 *
		 * @return the value stored in the token.
		 */
		virtual Language::Values::ValueI get_value() const override;
		virtual std::string get_string_type() const override;
	};
}

#endif