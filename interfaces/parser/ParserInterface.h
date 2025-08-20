#ifndef DEFINE_PARSER_I
#define DEFINE_PARSER_I

#include <vector>
#include "../tokens/TokenInterface.h"

namespace Language {
    namespace Parser {
        class ParserI {
        public:
            virtual int
                parse(std::vector<Tokens::TokenI*>) = 0;
        };
    }
}

#endif
