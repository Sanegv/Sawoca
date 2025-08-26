#include "../headers/Double.h"
#include "../headers/Bool.h"
#include <sstream>
#include <typeinfo>

using namespace Sawoca;

const std::string double_type("double");

Double::Double() : Value(DOUBLE), val(0.0) {}

Double::Double(double d) : Value(DOUBLE), val(d) {};

double Double::get_val() const{
    return val;
}

std::string Double::get_string_type() const {
    return double_type;
}

const Value& cast_to_value(const Language::Values::ValueI& v){
    try {
        const Value& vp = dynamic_cast<const Value&>(v);
        return vp;
    } catch (const std::bad_cast& e) {
        throw std::string("values must inherit the Value abstract class");
    }
}

const Double& cast_to_double(const Value& v){
    try {
        const Double& dp = dynamic_cast<const Double&>(v);
        return dp;
    } catch (const std::bad_cast& e){
        throw "not a " + double_type;
    }
}

Language::Values::ValueI* Double::add(const ValueI& v) const {    
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE: {
            Double* d = new Double(val+cast_to_double(vp).get_val());
            if(!d)
                throw "memory allocation failed";
            return d; 
        }
        default:
            throw std::string("cannot add type " + double_type + 
            " and type " + vp.get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::sub(const ValueI& v) const{    
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE: {
            Double* d = new Double(val-cast_to_double(vp).get_val());
            if(!d)
                throw "memory allocation failed";
            return d; 
        }
        default:
            throw std::string("cannot sub type " + double_type + " and type " + 
                vp.get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::mul(const ValueI& v) const{    
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE: {
            Double* d = new Double(val*cast_to_double(vp).get_val());
            if(!d)
                throw "memory allocation failed";
            return d; 
        }
        default:
            throw std::string("cannot mul type " + double_type + " and type " + 
                vp.get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::div(const ValueI& v) const{    
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE:
            {
                double d = cast_to_double(vp).get_val();
                if(d == 0) 
                    throw std::string("division by zero");
                
                Double* dp = new Double(val/d);
                if(!dp)
                    throw "memory allocation failed";
                return dp; 
            }
        default:
            throw std::string("cannot add type " + double_type +
             " and type " + vp.get_string_type());
            return nullptr;
    }
}

Language::Values::ValueI* Double::operator-(){
    val = -val;
    return this;
}

Language::Values::ValueI* Double::operator+(const ValueI& v) const {
    return this->add(v);
}
Language::Values::ValueI* Double::operator-(const ValueI& v) const {
    return this->sub(v);
}
Language::Values::ValueI* Double::operator*(const ValueI& v) const {
    return this->mul(v);
}
Language::Values::ValueI* Double::operator/(const ValueI& v) const {
    return this->div(v);
}

Language::Values::ValueI& Double::operator+=(const Language::Values::ValueI& v){
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE:
            val += cast_to_double(vp).get_val();
            break;
        default:
            throw std::string("cannot add type " + double_type + " and type " +
                vp.get_string_type());
            break;
    }

    return *this;
}

Language::Values::ValueI& Double::operator-=(const Language::Values::ValueI& v){
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE:
            val -= cast_to_double(vp).get_val();
            break;
        default:
            throw std::string("cannot sub type " + double_type + " and type " +
                vp.get_string_type());
            break;
    }

    return *this;
}
Language::Values::ValueI& Double::operator*=(const Language::Values::ValueI& v){
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE:
            val *= cast_to_double(vp).get_val();
            break;
        default:
            throw std::string("cannot mul type " + double_type + " and type " +
                vp.get_string_type());
            break;
    }

    return *this;
}
Language::Values::ValueI& Double::operator/=(const Language::Values::ValueI& v){
    const Value& vp = cast_to_value(v);

    switch (vp.get_type()) {
        case DOUBLE:
            {
                double d = cast_to_double(vp).get_val();
                if(d == 0) 
                    throw std::string("division by zero");
                val /= d; 
            }
            break;
        default:
            throw std::string("cannot div type " + double_type + " and type " +
                vp.get_string_type());
            break;
    }

    return *this;
}

std::string Double::string() const{
    std::ostringstream stream;
    stream << val;
    return stream.str();
}

const Value* Double::equals(const ValueI& other) const {
    const Value& vother = cast_to_value(other);
    if(vother.get_type() != DOUBLE)
        throw "cannot compare " + double_type + " and " 
            + vother.get_string_type();
    return new Bool(val == cast_to_double(vother).get_val());
}

const Value* Double::not_equals(const ValueI& other) const {
    const Value& vother = cast_to_value(other);
    if(vother.get_type() != DOUBLE)
        throw "cannot compare " + double_type + " and " 
            + vother.get_string_type();
    return new Bool(val != cast_to_double(vother).get_val());
}

const Value* Double::operator==(const ValueI& other) const {
    const Value& vother = cast_to_value(other);
    if(vother.get_type() != DOUBLE)
        throw "cannot compare " + double_type + " and " 
            + vother.get_string_type();
    return new Bool(val == cast_to_double(vother).get_val());
}

const Value* Double::operator!=(const ValueI& other) const {
    const Value& vother = cast_to_value(other);
    if(vother.get_type() != DOUBLE)
        throw "cannot compare " + double_type + " and " 
            + vother.get_string_type();
    return new Bool(val != cast_to_double(vother).get_val());
}

const Value* Double::logical_or(const ValueI& other) const{
    throw "cannot OR a " + double_type;
}

const Value* Double::logical_and(const ValueI& other) const{
    throw "cannot AND a " + double_type;
}

const Value* Double::operator||(const ValueI& other) const{
    return logical_or(other);
}

const Value* Double::operator&&(const ValueI& other) const{
    return logical_and(other);
}

const Value* Double::logical_not() const{
    throw "cannot logically invert " + double_type;
}

const Value* Double::operator!() const{
    return logical_not();
}