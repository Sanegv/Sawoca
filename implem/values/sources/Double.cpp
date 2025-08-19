#include "../headers/Double.h"

using namespace Sawoca;


Double::Double() : Value(DOUBLE), val(0.0) {}

Double::Double(double d) : Value(DOUBLE), val(d) {};

double Double::get_val() const{
    return val;
}

Value_Type Double::get_type() const {
    return type;
}

std::string Double::get_string_type() const {
    return std::string("double");
}

const Value* const cast_to_value(const Language::Values::ValueI* const v){
    if(!v)
        throw "nullptr dereference";

    const Value* const vp = dynamic_cast<const Value* const>(v);
    if(!vp)
        throw "values must inherit the Value abstract class";

    return vp;
}

const Double* const cast_to_double(const Value* const v){
    if(!v)
        throw "nullptr dereference";

    const Double* const dp = dynamic_cast<const Double* const>(v);
    if(!dp)
        throw "false double";

    return dp;
}

Language::Values::ValueI* Double::add(const ValueI* const v) const {    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            return new Double(val+cast_to_double(vp)->get_val()); 
        default:
            throw "cannot add type " + get_string_type() + " and type " + vp->get_string_type();
            return nullptr;
    }
}

Language::Values::ValueI* Double::sub(const ValueI* const v) const{    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            return new Double(val-cast_to_double(vp)->get_val()); 
        default:
            throw "cannot sub type " + get_string_type() + " and type " + vp->get_string_type();
            return nullptr;
    }
}

Language::Values::ValueI* Double::mul(const ValueI* const v) const{    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            return new Double(val*cast_to_double(vp)->get_val()); 
        default:
            throw "cannot mul type " + get_string_type() + " and type " + vp->get_string_type();
            return nullptr;
    }
}

Language::Values::ValueI* Double::div(const ValueI* const v) const{    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            {
                double d = cast_to_double(vp)->get_val();
                if(d == 0) 
                    throw "division by zero";
                return new Double(val/d); 
            }
        default:
            throw "cannot add type " + get_string_type() + " and type " + vp->get_string_type();
            return nullptr;
    }
}

Language::Values::ValueI* Double::operator+(const ValueI* const v) const {
    return this->add(v);
}
Language::Values::ValueI* Double::operator-(const ValueI* const v) const {
    return this->sub(v);
}
Language::Values::ValueI* Double::operator*(const ValueI* const v) const {
    return this->mul(v);
}
Language::Values::ValueI* Double::operator/(const ValueI* const v) const {
    return this->div(v);
}