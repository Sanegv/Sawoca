#ifndef DEFINE_SAWOCA_VALUE
#define DEFINE_SAWOCA_VALUE

#include <string>

#include "../../../interfaces/values/ValueInterface.h"

namespace Sawoca {
    enum Value_Type {
        DOUBLE,
    };

    class Value : public Language::Values::ValueI {
    private:
        Value_Type type;
        
        //do not use
        Value() = delete;
        
    public:
        Value(Value_Type type) : type(type) {}
        Value_Type get_type() const {return type;}
        virtual std::string get_string_type()   const = 0;
    };
}

#endif