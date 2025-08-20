#ifndef DEFINE_VALUE_INTERFACE
#define DEFINE_VALUE_INTERFACE

namespace Language {
    namespace Values {
        class ValueI {
        public:
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

            virtual ~ValueI() = default;
        };
    }
}

#endif