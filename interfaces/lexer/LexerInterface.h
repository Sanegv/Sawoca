#ifndef DEFINE_LEXER_I
#define DEFINE_LEXER_I

#include "../tokens/TokenInterface.h"

namespace Language {
    namespace Lexer {
        class LexerI {
        private:
            //do not use
            LexerI(const LexerI&)               = delete;
            LexerI& operator=(const LexerI&)    = delete;

        public:
            virtual Tokens::TokenI* get_token() = 0;
        };
    }
}

#endif
