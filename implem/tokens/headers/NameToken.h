#ifndef DEFINE_SAWOCA_NAME_TOKEN
#define DEFINE_SAWOCA_NAME_TOKEN

#include <string>
#include <map>

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

namespace Sawoca {
/**
	 * Holds the value of a variable's name, as well as a reference to all the 
	 * variables to be able to look for its own value.
	 */
	class Name_Token : public Token {
	private:
		std::string name;
		std::map<std::string, double>& variables;
		Name_Token() = delete;
	public:
		/**
		 * @brief The only constructor for a variable token.
		 * 
		 * @param name the name of the variable.
		 * @param variables a reference to the table of all variables.
		 */
		Name_Token(std::string name, std::map<std::string, double>& variables);
		~Name_Token() = default;

		/**
		 * @brief Looks for its own value in the table of variables and returns
		 * it.
		 *
		 * @return the value of the variable of name `name` in the table.
		 */
		virtual Language::Values::ValueI get_value() const override;
		virtual std::string get_string_type() const override;
	};
}

#endif