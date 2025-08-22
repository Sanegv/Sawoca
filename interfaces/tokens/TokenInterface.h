#ifndef DEFINE_TOKEN_I
#define DEFINE_TOKEN_I

#include "../values/ValueInterface.h"

/**
 *@file TokenInterface.h
 *@brief This file defines the TokenI interface and methods.
 *@author Sanegv
 */

namespace Language {
    namespace Tokens {
        /**
        * @brief The interface for lexer tokens, which should all have a value 
        * or throw an exception.
        */
        class TokenI {
        public:
            /**
            * Accessor of the value of a token if it has one.
            *
            * @return the value of the token, if it has one.
            */
            virtual const Values::ValueI* get_value() const = 0;

            /**
            * @brief A standard destructor used for polymorhism.
            */
            virtual ~TokenI() = default;
        };
    }
}

#endif