#ifndef DEFINE_SAWOCA_NAME_TOKEN
#define DEFINE_SAWOCA_NAME_TOKEN

#include <string>
#include <map>

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

/**
 *@file NameToken.h
 *@brief This file defines the name Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for the name of a variable. It is
    * used to access the actual value of the variable in the map. It inherits
	* from the \ref Token abstract class.
	*/
	class Name_Token : public Token {
	private:
		std::string name;
		std::map<std::string, const Language::Values::ValueI*>& variables;

		//do not use
		Name_Token() = delete;
	public:
		/**
		 * @brief Creates a Name Token that holds a reference to all variables, 
		 * as well as the name of the variable it represents.
		 * 
		 * @param name the name of the variable.
		 * @param variables a reference to the table of all variables.
		 */
		Name_Token(
			std::string name,
			std::map<std::string, const Language::Values::ValueI*>& variables
		);
		~Name_Token() = default;

		/**
		 * @brief Looks for its own value in the table of variables and returns
		 * it.
		 *
		 * @return the value of the variable of name `name` in the table.
		 */
		virtual const Language::Values::ValueI* get_value() const override;

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "NUMBER" 
         */
		virtual std::string get_string_type() const override;

		/**
		 * @brief the accessor for the name field.
		 *
		 *@return the name of the variable represented.
		 */
		std::string get_name();
	};
}

#endif