#ifndef DEFINE_SAWOCA_ASSIGN_TOKEN
#define DEFINE_SAWOCA_ASSIGN_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

/**
 *@file AssignToken.h
 *@brief This file defines the assignment Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for an assignment. It is used to
    * define new variables, or change the values of existing variables. It 
    * inherits from the \ref Token abstract class.
    */
    class Assign_Token : public Token {
    public:
        /**
         * @brief A simple creator for an empty token.
         */
        Assign_Token();

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "ASSIGN" 
         */
        virtual std::string get_string_type() const override;

        /**
         * @brief throws an exception, as the assignment token does not yet hold
         * a value.
         */
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
