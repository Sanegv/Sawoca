#ifndef DEFINE_SAWOCA_ASSIGN_TOKEN
#define DEFINE_SAWOCA_ASSIGN_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

namespace Sawoca {
    class AssignToken : public Token {
    public:
        AssignToken();
        virtual std::string get_string_type() const override;
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif
