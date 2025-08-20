#ifndef DEFINE_SAWOCA_OPERATOR_TOKEN
#define DEFINE_SAWOCA_OPERATOR_TOKEN

#include <string>
#include <map>

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

namespace Sawoca {
    /**
	 * @brief Holds a binary operator, as well as its left and right sons.
	 */
	class Operator_Token : public Token {
	private:
		char op;

		//do not use
		Operator_Token() = delete;
		Operator_Token(const Operator_Token&) = delete;
		Operator_Token& operator=(const Operator_Token&) = delete;
	public:
		Operator_Token(char op);
		virtual const Language::Values::ValueI* get_value() const override;
		virtual std::string get_string_type() const override;
	};
}

#endif
