#ifndef DEFINE_SAWOCA_VALUE
#define DEFINE_SAWOCA_VALUE

#include "string"

#include "../../../interfaces/values/ValueInterface.h"

namespace Sawoca {
    enum Value_Type {
        DOUBLE,
    };

    class Value : public Language::Values::ValueI {
    private:
        //do not use
        Value() = delete;

    protected:
        Value_Type type;
        
    public:
        Value(Value_Type type) : type(type) {}
        virtual Value_Type get_type()           const = 0;
        virtual std::string get_string_type()   const = 0;
    };
}

#endif