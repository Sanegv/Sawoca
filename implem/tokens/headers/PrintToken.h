#ifndef DEFINE_SAWOCA_PRINT_TOKEN
#define DEFINE_SAWOCA_PRINT_TOKEN

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

/**
 *@file PrintToken.h
 *@brief This file defines the print Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token that ends an expression. It is
    * used to print the evaluation of the last expression, and clear the tokens
    * to begin the evaluation of the next one. It inherits from the \ref Token
    * abstract class.
    */
    class Print_Token : public Token {
    public:
        /**
         * @brief A simple creator for an empty token.
         */
        Print_Token();

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "PRINT" 
         */
        virtual std::string get_string_type() const override;

        /**
         * @brief throws an exception, as the PRINT token does not hold a value.
         */
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif