#ifndef DEFINE_LEXER_I
#define DEFINE_LEXER_I

#include <vector>
#include "../tokens/TokenInterface.h"

/**
 *@file LexerInterface.h
 *@brief This file defines the LexerI interface and methods.
 *@author Sanegv
 */

namespace Language {
    namespace Lexer {
        /**
        * @brief The lexer interface is responsible for reading a raw text and 
        * returning tokens.
        */
        class LexerI {
        public:
            /**
            * @brief Reads the whole stream attribute, and tokenises its content.
            *
            * @return a vector of Tokens.
            */
            virtual std::vector<Tokens::TokenI*> lex() = 0;

            /**
            * @brief A standard destructor used for polymorhism.
            */
            virtual ~LexerI() = default;
        };
    }
}

#endif
