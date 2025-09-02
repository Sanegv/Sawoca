#include "../headers/Bool.h"
#include <typeinfo>

using namespace Sawoca;

const std::string bool_type = "bool";

const Bool& cast_to_bool(const Value& v){
    if(v.get_type() != BOOL)
        throw std::string("not a bool");
    try{
        return dynamic_cast<const Bool&>(v);
    } catch (const std::bad_cast& e){
        throw std::string("unknown type");
    }
}

Bool::Bool(bool b) : Value(BOOL), val(b) {}

bool Bool::get_val() const{
    return val;
}

std::string Bool::get_string_type() const {
    return bool_type;
}

std::string Bool::string() const {
    if(val)
        return "true";
    return "false";
}

Value* Bool::operator+(const Value& other) const{
    (void)other;
    throw std::string("cannot add a bool");
}

Value* Bool::operator-(const Value& other) const{
    (void)other;
    throw std::string("cannot sub a bool");
}

Value* Bool::operator*(const Value& other) const{
    (void)other;
    throw std::string("cannot add a bool");
}

Value* Bool::operator/(const Value& other) const{
    (void)other;
    throw std::string("cannot div a bool");
}

Value* Bool::operator-() const {
    throw std::string("cannot invert a bool");
}

Value& Bool::operator+=(const Value& other) {
    (void)other;
    throw  std::string("cannot add a bool");
}

Value& Bool::operator-=(const Value& other) {
    (void)other;
    throw  std::string("cannot sub a bool");
}

Value& Bool::operator*=(const Value& other) {
    (void)other;
    throw  std::string("cannot mul a bool");
}

Value& Bool::operator/=(const Value& other) {
    (void)other;
    throw  std::string("cannot div a bool");
}

Value* Bool::operator==(const Value& other) const{
    if(other.get_type() != BOOL)
        throw std::string("cannot compare " + bool_type + " and " 
            + other.get_string_type());
    return new Bool(val == cast_to_bool(other).val);
}

Value* Bool::operator!=(const Value& other) const{
    if(other.get_type() != BOOL)
        throw std::string("cannot compare " + bool_type + " and " 
            + other.get_string_type());
    return new Bool(val != cast_to_bool(other).val);
}

Value* Bool::operator||(const Value& other) const{
    if(other.get_type() != BOOL)
        throw std::string("cannot compare " + bool_type + " and " 
            + other.get_string_type());
    return new Bool(val || cast_to_bool(other).val);
}

Value* Bool::operator&&(const Value& other) const{
    if(other.get_type() != BOOL)
        throw std::string("cannot compare " + bool_type + " and " 
            + other.get_string_type());
    return new Bool(val && cast_to_bool(other).val);
}

Value* Bool::operator!() const{
    return new Bool(!val);
}

Value* Bool::operator<(const Value& other) const {
    (void)other;
    throw "cannot arithmetically compare a " + bool_type;
}

Value* Bool::operator<=(const Value& other) const {
    (void)other;
    throw "cannot arithmetically compare a " + bool_type;
}

Value* Bool::operator>(const Value& other) const {
    (void)other;
    throw "cannot arithmetically compare a " + bool_type;
}

Value* Bool::operator>=(const Value& other) const {
    (void)other;
    throw "cannot arithmetically compare a " + bool_type;
}