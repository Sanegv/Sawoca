#ifndef DEFINE_SAWOCA_LEFT_PARANTHESIS_TOKEN
#define DEFINE_SAWOCA_LEFT_PARANTHESIS_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

/**
 *@file LeftParToken.h
 *@brief This file defines the left paranthesis Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for opening of a paranthesis. It is
    * used to begin the parsing of a new expression nested within the main one.
    * It inherits from the \ref Token abstract class.
    */
    class LeftPar_Token : public Token {
    public:
        /**
         * @brief A simple creator for an empty token.
         */
        LeftPar_Token();

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "LP" 
         */
        virtual std::string get_string_type() const override;

        /**
         * @brief throws an exception, as the LP token does not hold a value.
         */
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
