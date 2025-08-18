#ifndef DEF_PARSER
#define DEF_PARSER

/**
 *@file parser.h
 *@brief This file contains the parser class and mehtod.
 *@author Sanegv
 */

#include <map>
#include <memory>
#include <string>
#include "lexer.h"

namespace Calc {

	/**
	 * @brief Represents a parser token, with a type and a value. It's a 
	 * composite pattern that can either be a literal value, a variable or an 
	 * operation.
	 */
	class Token {
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
		Token(Token_Type type);
		virtual ~Token() = default;

		/**
		 * @brief Accessor for the type field of a token.
		 *
		 * @return the type of the token.
		 */
		Token_Type get_type();

		/**
		 * Evaluates the value of a token, whether by simply returning it, or 
		 * by recursively evaluating the value of its branches in the AST.
		 *
		 * @return the evaluated value of the token and its branches in the AST.
		 */
		virtual double get_value() = 0;
	};

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
		virtual double get_value() override;
	};

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
		virtual double get_value() override;
	};

	/**
	 * @brief Holds a binary operator, as well as its left and right sons.
	 */
	class Operator_Token : public Token {
	private:
		char op;
		std::unique_ptr<Token> LHS, RHS;
		Operator_Token() = delete;
		Operator_Token(const Operator_Token&) = delete;
		Operator_Token& operator=(const Operator_Token&) = delete;
	public:
		Operator_Token(
			char op, 
			std::unique_ptr<Operator_Token> LHS,
			std::unique_ptr<Operator_Token> RHS
		);
		virtual double get_value() override;
	};

	/**
	* @brief The parser class is responsible for reading the tokens of its lexer,
	* ordering them in a tree structure (AST) and executing them in order. 
	*/
	class Parser {
	private:
		std::map<std::string, double> table;
		int number_of_errors = 0;
		Lexer* lexer;

		//don't use
		Parser(const Parser&) = delete;
		Parser& operator=(const Parser&) = delete;
	
	public:
		/**
		* @brief Creates a new parser with a new lexer reading stdin. 
		*/
		Parser();

		/**
		* @brief Creates a new parser with the given lexer.
		*/
		Parser(Lexer* l);

		/**
		* @brief Standard destructor for the parser. Note that it will delete its
		* lexer, too. 
		*/
		~Parser();

		/**
		* @brief Parses a primary expression and returns its value.
		* Calls @ref expr() to parse paranthesis expressions, and returns an 
		* @ref error() in case of a wrong parameter or an unclosed paranthesis.
		*
		* @param get A boolean that tells the function whether or not to get the next
		* token
		*
		* @return The value of the primary expression
		*/
		double prim(bool get);

		/**
		* @brief Multiplies or divides numbers and expressions, and calls @ref 
		* prim() for the rest. Raises an @ref error() in case of 
		* a division by zero.
		*
		* @param get A boolean that tells the function whether or not to get the next
		* token.
		* @return The result of the expression.
		*/
		double term(bool get);

		/**
		* @brief Adds or subtracts numbers and expressions, and calls @ref 
		* term() for the rest.
		*
		* @param get A boolean that tells the function whether or not to get the next
		* token.
		* @return The result of the expression.
		*/
		double expr(bool get);

		/**
		* @brief Prints the error to stderr and increments the global error counter.
		*
		* @param e A string that will be printed to stderr.
		*
		* @return 1.0, as to prevent further errors from happening.
		*/
		double error(std::string e);

		/**
		* @brief Parses the stream of its lexer until it is closed.
		*
		*@return the number of errors encountered.
		*/
		int parse();
	};
}

#endif
