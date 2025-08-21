#ifndef DEFINE_SAWOCA_PRINT_TOKEN
#define DEFINE_SAWOCA_PRINT_TOKEN

#include "../../../interfaces/tokens/TokenInterface.h"
#include "Token.h"

namespace Sawoca {
    class PrintToken : public Token {
    public:
        PrintToken();
        virtual std::string get_string_type() const override;
        virtual const Language::Values::ValueI* get_value() const override;    
    };
}

#endif