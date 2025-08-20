#ifndef DEFINE_SAWOCA_DOUBLE
#define DEFINE_SAWOCA_DOUBLE

#include "Value.h"

namespace Sawoca {
    class Double  : public Value {
    private:
        double val;
    public: 
        Double();
        Double(double d);
        double get_val() const;

        virtual std::string get_string_type()              const override;
        virtual std::string string()                       const override;

            virtual ValueI* add(const ValueI* const)       const override;
            virtual ValueI* sub(const ValueI* const)       const override;
            virtual ValueI* mul(const ValueI* const)       const override;
            virtual ValueI* div(const ValueI* const)       const override;

            virtual ValueI* operator+(const ValueI* const) const override;
            virtual ValueI* operator-(const ValueI* const) const override;
            virtual ValueI* operator*(const ValueI* const) const override;
            virtual ValueI* operator/(const ValueI* const) const override;
            virtual ValueI* operator-()                          override;

            virtual ValueI& operator+=(const ValueI&)            override;
            virtual ValueI& operator-=(const ValueI&)            override;
            virtual ValueI& operator*=(const ValueI&)            override;
            virtual ValueI& operator/=(const ValueI&)            override;
    };
}

#endif