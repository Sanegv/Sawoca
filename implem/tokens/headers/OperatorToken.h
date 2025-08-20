#ifndef DEFINE_SAWOCA_OPERATOR_TOKEN
#define DEFINE_SAWOCA_OPERATOR_TOKEN

#include <string>
#include <map>
#include <memory>

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

namespace Sawoca {
    /**
	 * @brief Holds a binary operator, as well as its left and right sons.
	 */
	class Operator_Token : public Token {
	private:
		char op;
		std::unique_ptr<Token> LHS, RHS;

		//do not use
		Operator_Token() = delete;
		Operator_Token(const Operator_Token&) = delete;
		Operator_Token& operator=(const Operator_Token&) = delete;
	public:
		Operator_Token(
			char op, 
			std::unique_ptr<Operator_Token> LHS,
			std::unique_ptr<Operator_Token> RHS
		);
		virtual const Language::Values::ValueI* get_value() const override;
		virtual std::string get_string_type() const override;
	};
}

#endif