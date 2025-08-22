#ifndef DEFINE_PARSER_I
#define DEFINE_PARSER_I

#include <vector>
#include "../tokens/TokenInterface.h"

/**
 *@file ParserInterface.h
 *@brief This file defines the ParserI interface and methods.
 *@author Sanegv
 */

namespace Language {
    namespace Parser {
        /**
        * @brief The parser interface is responsible for reading a vector of 
        \ref TokenI and executing them in order.
        */
        class ParserI {
        public:
            /**
            * @brief Parses a vector of tokens and executes them in order.
            *
            * @param tokens The vector of Tokens to be parsed.
            */
            virtual void
                parse(std::vector<Tokens::TokenI*>) = 0;

            /**
            * @brief A standard destructor used for polymorhism.
            */
            virtual ~ParserI() = default;
        };
    }
}

#endif
