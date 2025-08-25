#ifndef DEFINE_SAWOCA_END_TOKEN
#define DEFINE_SAWOCA_END_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

/**
 *@file EndToken.h
 *@brief This file defines the end of stream Token class.
 *@author Sanegv
 */

namespace Sawoca {
    /**
    * @brief This class represents the Token for the end of the stream being 
    * lexed. It is used to close and exit the swc program properly. It 
    * inherits from the \ref Token abstract class.
     */
    class End_Token : public Token {
    public:
        /**
         * @brief A simple creator for an empty token.
         */
        End_Token();

        /**
         * @brief stringifies the type of the token.
         * @return a string saying "END" 
         */
        virtual std::string get_string_type() const override;

        /**
         * @brief throws an exception, as the END token does not hold a value.
         */
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
