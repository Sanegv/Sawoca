#ifndef DEFINE_PARSER_I
#define DEFINE_PARSER_I

#include "LexerInterface.h"
#include "../tokens/TokenInterface.h"

namespace Language {
    namespace Parser {
        class ParserI {
        private:
            LexerI* lexer;

            //do not use
            ParserI()                           = delete;
            ParserI(const ParserI&)             = delete;
            ParserI& operator=(const ParserI&)  = delete;
        public:
            ParserI(LexerI* lexer) : lexer(lexer) {}
            virtual Language::Tokens::TokenI* parse() = 0;
        };
    }
}

#endif