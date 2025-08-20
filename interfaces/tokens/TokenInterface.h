#ifndef DEFINE_TOKEN_I
#define DEFINE_TOKEN_I

#include "../values/ValueInterface.h"

namespace Language {
    namespace Tokens {
        class TokenI {
        public:
            virtual const Values::ValueI* get_value() const = 0;
        };
    }
}

#endif