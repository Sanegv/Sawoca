#include "../headers/Double.h"
#include <sstream>

using namespace Sawoca;

Double::Double() : Value(DOUBLE), val(0.0) {}

Double::Double(double d) : Value(DOUBLE), val(d) {};

double Double::get_val() const{
    return val;
}

std::string Double::get_string_type() const {
    return std::string("double");
}

const Value* const cast_to_value(const Language::Values::ValueI* const v){
    if(!v)
        throw std::string("nullptr dereference");

    const Value* const vp = dynamic_cast<const Value* const>(v);
    if(!vp)
        throw std::string("values must inherit the Value abstract class");

    return vp;
}

const Double* const cast_to_double(const Value* const v){
    if(!v)
        throw std::string("nullptr dereference");

    const Double* const dp = dynamic_cast<const Double* const>(v);
    if(!dp)
        throw std::string("false double");

    return dp;
}

Language::Values::ValueI* Double::add(const ValueI* const v) const {    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            return new Double(val+cast_to_double(vp)->get_val()); 
        default:
            throw std::string("cannot add type " + get_string_type() + " and type " + 
                vp->get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::sub(const ValueI* const v) const{    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            return new Double(val-cast_to_double(vp)->get_val()); 
        default:
            throw std::string("cannot sub type " + get_string_type() + " and type " + 
                vp->get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::mul(const ValueI* const v) const{    
    const Value* const vp = cast_to_value(v);

    switch (vp->get_type()) {
        case DOUBLE:
            return new Double(val*cast_to_double(vp)->get_val()); 
        default:
            throw std::string("cannot mul type " + get_string_type() + " and type " + 
                vp->get_string_type());
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
                    throw std::string("division by zero");
                return new Double(val/d); 
            }
        default:
            throw std::string("cannot add type " + get_string_type() + " and type " + 
                vp->get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::operator-(){
    val = -val;
    return this;
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

Language::Values::ValueI& Double::operator+=(const Language::Values::ValueI& v){
    const Value* const vp = cast_to_value(&v);

    switch (vp->get_type()) {
        case DOUBLE:
            val += cast_to_double(vp)->get_val();
            break;
        default:
            throw std::string("cannot add type " + get_string_type() + " and type " +
                vp->get_string_type());
            break;
    }

    return *this;
}

Language::Values::ValueI& Double::operator-=(const Language::Values::ValueI& v){
    const Value* const vp = cast_to_value(&v);

    switch (vp->get_type()) {
        case DOUBLE:
            val -= cast_to_double(vp)->get_val();
            break;
        default:
            throw std::string("cannot sub type " + get_string_type() + " and type " +
                vp->get_string_type());
            break;
    }

    return *this;
}
Language::Values::ValueI& Double::operator*=(const Language::Values::ValueI& v){
    const Value* const vp = cast_to_value(&v);

    switch (vp->get_type()) {
        case DOUBLE:
            val *= cast_to_double(vp)->get_val();
            break;
        default:
            throw std::string("cannot mul type " + get_string_type() + " and type " +
                vp->get_string_type());
            break;
    }

    return *this;
}
Language::Values::ValueI& Double::operator/=(const Language::Values::ValueI& v){
    const Value* const vp = cast_to_value(&v);

    switch (vp->get_type()) {
        case DOUBLE:
            {
                double d = cast_to_double(vp)->get_val();
                if(d == 0) 
                    throw std::string("division by zero");
                val /= d; 
            }
            break;
        default:
            throw std::string("cannot div type " + get_string_type() + " and type " +
                vp->get_string_type());
            break;
    }

    return *this;
}

std::string Double::string() const{
    std::ostringstream stream;
    stream << val;
    return stream.str();
}

