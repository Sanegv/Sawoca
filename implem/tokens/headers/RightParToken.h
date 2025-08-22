#ifndef DEFINE_SAWOCA_RIGHT_PARANTHESIS_TOKEN
#define DEFINE_SAWOCA_RIGHT_PARANTHESIS_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

/**
 *@file LeftParToken.h
 *@brief This file defines the right paranthesis Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for closing of a paranthesis. It is
    * used to end the parsing of a new expression nested within the main one, 
    * and evaluate its content. It inherits from the \ref Token abstract class.
    */
    class RightParToken : public Token {
    public:
        /**
         * @brief A simple creator for an empty token.
         */
        RightParToken();

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "RP" 
         */
        virtual std::string get_string_type() const override;

        /**
         * @brief throws an exception, as the RP token does not hold a value.
         */
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
