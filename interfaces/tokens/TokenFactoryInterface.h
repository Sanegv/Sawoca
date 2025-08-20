#ifndef DEFINE_TOKEN_FACTORY_I
#define DEFINE_TOKEN_FACTORY_I

#include "TokenInterface.h"

namespace Language {
    namespace Tokens {
        class TokenFactoryI {
            public:
                virtual TokenI* create_token() = 0;
        };
    }
}

#endif