#ifndef DEFINE_SAWOCA_LEFT_PARANTHESIS_TOKEN
#define DEFINE_SAWOCA_LEFT_PARANTHESIS_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

namespace Sawoca {
    class LeftParToken : public Token {
    public:
        LeftParToken();
        virtual std::string get_string_type() const override;
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
