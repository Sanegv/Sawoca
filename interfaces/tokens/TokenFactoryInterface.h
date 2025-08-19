#ifndef DEFINE_TOKEN_FACTORY_I
#define DEFINE_TOKEN_FACTORY_I

#include "TokenInterface.h"

namespace Language {
    namespace Tokens {
        class TokenFactoryI {
            public:
                TokenI* create_token();
        };
    }
}

#endif