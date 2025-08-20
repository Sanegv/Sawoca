#ifndef DEFINE_LEXER_I
#define DEFINE_LEXER_I

#include <vector>
#include "../tokens/TokenInterface.h"

namespace Language {
    namespace Lexer {
        class LexerI {
        public:
            virtual std::vector<Tokens::TokenI*> lex() = 0;
        };
    }
}

#endif
