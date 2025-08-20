#ifndef DEFINE_SAWOCA_TOKEN_FACTORY
#define DEFINE_SAWOCA_TOKEN_FACTORY

#include "../../../interfaces/tokens/TokenFactoryInterface.h"
#include "../../../interfaces/parser/LexerInterface.h"
#include "Token.h"
#include "EndToken.h"

namespace Sawoca{
    class TokenFactory : Language::Tokens::TokenFactoryI {
    private:
        Language::Parser::LexerI* lexer;

        //tokens
        EndToken* create_end_token();

        //don't use
        TokenFactory() = delete;
        TokenFactory(const TokenFactory&) = delete;
        TokenFactory& operator=(const TokenFactory&) = delete;
    public:
        TokenFactory(Language::Parser::LexerI* lexer);
        virtual Language::Tokens::TokenI* create_token() override;
    };
}

#endif