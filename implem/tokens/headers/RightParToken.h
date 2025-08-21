#ifndef DEFINE_SAWOCA_RIGHT_PARANTHESIS_TOKEN
#define DEFINE_SAWOCA_RIGHT_PARANTHESIS_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

namespace Sawoca {
    class RightParToken : public Token {
    public:
        RightParToken();
        virtual std::string get_string_type() const override;
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
