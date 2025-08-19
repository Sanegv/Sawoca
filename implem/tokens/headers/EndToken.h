#ifndef DEFINE_SAWOCA_END_TOKEN
#define DEFINE_SAWOCA_END_TOKEN

#include "Token.h"
#include "../../../interfaces/tokens/TokenInterface.h"

namespace Sawoca {
    class EndToken : Token {
    public:
        EndToken();
        std::string get_string_type() const override;
        Language::Values::ValueI get_value() const override;    
    };
}

#endif
