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

const Double& cast_to_double(const Value& v){
    try {
        const Double& dp = dynamic_cast<const Double&>(v);
        return dp;
    } catch (const std::bad_cast& e){
        throw std::string("not a " + double_type);
    }
}

Value* Double::operator+(const Value& v) const {    
    switch (v.get_type()) {
        case DOUBLE: {
            Double* d = new Double(val+cast_to_double(v).get_val());
            if(!d)
                throw std::string("memory allocation failed");
            return d; 
        }
        default:
            throw std::string("cannot add type " + double_type + 
            " and type " + v.get_string_type());
            return nullptr;
    }
}

Value* Double::operator-(const Value& v) const{
    switch (v.get_type()) {
        case DOUBLE: {
            Double* d = new Double(val-cast_to_double(v).get_val());
            if(!d)
                throw std::string("memory allocation failed");
            return d; 
        }
        default:
            throw std::string("cannot sub type " + double_type + " and type " + 
                v.get_string_type());
            return nullptr;
    }
}

Value* Double::operator*(const Value& v) const{
    switch (v.get_type()) {
        case DOUBLE: {
            Double* d = new Double(val*cast_to_double(v).get_val());
            if(!d)
                throw std::string("memory allocation failed");
            return d; 
        }
        default:
            throw std::string("cannot mul type " + double_type + " and type " + 
                v.get_string_type());
            return nullptr;
    }
}

Value* Double::operator/(const Value& v) const{
    switch (v.get_type()) {
        case DOUBLE:
            {
                double d = cast_to_double(v).get_val();
                if(d == 0) 
                    throw std::string("division by zero");
                
                Double* dp = new Double(val/d);
                if(!dp)
                    throw std::string("memory allocation failed");
                return dp; 
            }
        default:
            throw std::string("cannot add type " + double_type +
             " and type " + v.get_string_type());
            return nullptr;
    }
}

Value* Double::operator-() const{
    return new Double(-val);
}

Value& Double::operator+=(const Value& v){
    switch (v.get_type()) {
        case DOUBLE:
            val += cast_to_double(v).get_val();
            break;
        default:
            throw std::string("cannot add type " + double_type + " and type " +
                v.get_string_type());
            break;
    }

    return *this;
}

Value& Double::operator-=(const Value& v){
    switch (v.get_type()) {
        case DOUBLE:
            val -= cast_to_double(v).get_val();
            break;
        default:
            throw std::string("cannot sub type " + double_type + " and type " +
                v.get_string_type());
            break;
    }

    return *this;
}
Value& Double::operator*=(const Value& v){
    switch (v.get_type()) {
        case DOUBLE:
            val *= cast_to_double(v).get_val();
            break;
        default:
            throw std::string("cannot mul type " + double_type + " and type " +
                v.get_string_type());
            break;
    }

    return *this;
}
Value& Double::operator/=(const Value& v){
    switch (v.get_type()) {
        case DOUBLE:
            {
                double d = cast_to_double(v).get_val();
                if(d == 0) 
                    throw std::string("division by zero");
                val /= d; 
            }
            break;
        default:
            throw std::string("cannot div type " + double_type + " and type " +
                v.get_string_type());
            break;
    }

    return *this;
}

std::string Double::string() const{
    std::ostringstream stream;
    stream << val;
    return stream.str();
}

const Value* Double::operator==(const Value& other) const {
    if(other.get_type() != DOUBLE)
        throw std::string("cannot compare " + double_type + " and " 
            + other.get_string_type());
    return new Bool(val == cast_to_double(other).get_val());
}

const Value* Double::operator!=(const Value& other) const {
    if(other.get_type() != DOUBLE)
        throw std::string("cannot compare " + double_type + " and " 
            + other.get_string_type());
    return new Bool(val != cast_to_double(other).get_val());
}

const Value* Double::operator||(const Value& other) const{
    (void)other;
    throw std::string("cannot OR a " + double_type);
}

const Value* Double::operator&&(const Value& other) const{
    (void)other;
    throw std::string("cannot AND a " + double_type);
}

const Value* Double::operator!() const{
    throw std::string("cannot logically invert " + double_type);
}

const Value* Double::operator<(const Value& v) const {
    switch (v.get_type()) {
        case DOUBLE: {
            Bool* b = new Bool(val<cast_to_double(v).get_val());
            if(!b)
                throw std::string("memory allocation failed");
            return b; 
        }
        default:
            throw std::string("cannot compare type " + double_type + 
                " and type " + v.get_string_type());
            return nullptr;
    }    
}

const Value* Double::operator<=(const Value& v) const {
    switch (v.get_type()) {
        case DOUBLE: {
            Bool* b = new Bool(val<=cast_to_double(v).get_val());
            if(!b)
                throw std::string("memory allocation failed");
            return b; 
        }
        default:
            throw std::string("cannot compare type " + double_type + 
                " and type " + v.get_string_type());
            return nullptr;
    }    
}

const Value* Double::operator>(const Value& v) const {
    switch (v.get_type()) {
        case DOUBLE: {
            Bool* b = new Bool(val>cast_to_double(v).get_val());
            if(!b)
                throw std::string("memory allocation failed");
            return b; 
        }
        default:
            throw std::string("cannot compare type " + double_type + 
                " and type " + v.get_string_type());
            return nullptr;
    }    
}

const Value* Double::operator>=(const Value& v) const {
    switch (v.get_type()) {
        case DOUBLE: {
            Bool* b = new Bool(val>=cast_to_double(v).get_val());
            if(!b)
                throw std::string("memory allocation failed");
            return b; 
        }
        default:
            throw std::string("cannot compare type " + double_type + 
                " and type " + v.get_string_type());
            return nullptr;
    }    
}
