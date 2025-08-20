#include "../headers/TokenFactory.h"

using namespace Sawoca;

EndToken* TokenFactory::create_end_token(){
    return new EndToken();
}

Language::Tokens::TokenI* TokenFactory::create_token(){
    return create_end_token();
}