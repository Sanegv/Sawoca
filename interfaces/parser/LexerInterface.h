#ifndef DEFINE_LEXER_I
#define DEFINE_LEXER_I

#include "../tokens/TokenInterface.h"
#include "../tokens/TokenFactoryInterface.h"

namespace Language {
    namespace Parser {
        class LexerI {
        private:
            Tokens::TokenFactoryI* fatory;

            //do not use
            LexerI()                            = delete;
            LexerI(const LexerI&)               = delete;
            LexerI& operator=(const LexerI&)    = delete;
        public:
            LexerI(Tokens::TokenFactoryI* fatory) : fatory(fatory) {}
            Tokens::TokenI* get_token();
        };
    }
}

#endif