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
        virtual std::string string()            const = 0;
        virtual ~Value() = default;

        virtual ValueI* add(const ValueI* const)       const = 0;
        virtual ValueI* sub(const ValueI* const)       const = 0;
        virtual ValueI* mul(const ValueI* const)       const = 0;
        virtual ValueI* div(const ValueI* const)       const = 0;

        virtual ValueI* operator+(const ValueI* const) const = 0;
        virtual ValueI* operator-(const ValueI* const) const = 0;
        virtual ValueI* operator*(const ValueI* const) const = 0;
        virtual ValueI* operator/(const ValueI* const) const = 0;
        virtual ValueI* operator-()                          = 0; //unary

        virtual ValueI& operator+=(const ValueI&)            = 0;
        virtual ValueI& operator-=(const ValueI&)            = 0;
        virtual ValueI& operator*=(const ValueI&)            = 0;
        virtual ValueI& operator/=(const ValueI&)            = 0;
    };
}

#endif