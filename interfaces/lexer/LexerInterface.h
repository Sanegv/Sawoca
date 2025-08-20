#ifndef DEFINE_LEXER_I
#define DEFINE_LEXER_I

#include "../tokens/TokenInterface.h"
#include "../tokens/TokenFactoryInterface.h"

namespace Language {
    namespace Lexer {
        class LexerI {
        private:
            //do not use
            LexerI()                            = delete;
            LexerI(const LexerI&)               = delete;
            LexerI& operator=(const LexerI&)    = delete;
        
        protected:
            Tokens::TokenFactoryI* factory;

        public:
            LexerI(Tokens::TokenFactoryI* factory) : factory(factory) {}
            virtual Tokens::TokenI* get_token() = 0;
        };
    }
}

#endif
