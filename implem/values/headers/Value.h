#ifndef DEFINE_SAWOCA_VALUE
#define DEFINE_SAWOCA_VALUE

#include <string>

#include "../../../interfaces/values/ValueInterface.h"

/**
 *@file Value.h
 *@brief This file defines the abstract Value class, from which every value 
 * inherits, as well as the different value types.
 *@author Sanegv
 */

namespace Sawoca {
    /**
 	* @brief The different types of values that exist.
 	*/
    enum Value_Type {
        DOUBLE, ///< A double precision floating point number.
        BOOL, ///< A boolean for logical arithmetics.
    };

    /**
	 * @brief Represents a value, with a type and a few methods and operations.
     * It inherits from the \ref ValueI interface.
	 */
    class Value : public Language::Values::ValueI {
    private:
        Value_Type type;
        
        //do not use
        Value() = delete;
        
    public:
        /** 
         * @brief Creates a value with a type.
         * @param type the type of the value.
         */
        Value(Value_Type type) : type(type) {}

        /** 
         * @brief Accessor to the type field.
         * @return the type of the value.
         */
        Value_Type get_type() const {return type;}

		/**
		* @brief Accessor for the type field of a token, in human readable form.
		*
		* @return the name of the type of the token.
		*/
        virtual std::string get_string_type() const = 0;

        /**
         * @brief stringifies the value stored.
         * @return the string representation of the value inside. 
         */
        virtual std::string string() const = 0;

		/**
		 * @brief A standard destructor used for polymorhism.
		 */
        virtual ~Value() = default;

        //-------------------------const operators------------------------------

        /**
         *@brief Creates a new Value equal to the sum of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to add.
         * @return a pointer to a new value
         */
        virtual Value* operator+(const Value&) const = 0;

        /**
         *@brief Creates a new Value equal to the difference between this
         * and the other number. Throws an exception in case of an invalid type.
         * @param other the value to subtract.
         * @return a pointer to a new value
         */
        virtual Value* operator-(const Value&) const = 0;

        /**
         *@brief Creates a new Value equal to the product of this and the 
         * other number. Throws an exception in case of an invalid type.
         * @param other the value to multiply by.
         * @return a pointer to a new value
         */
        virtual Value* operator*(const Value&) const = 0;

        /**
         *@brief Creates a new Value equal to the division of this by the 
         * other number. Throws an exception in case of an invalid type or of a
         * division by zero.
         * @param other the denominator to divide by.
         * @return a pointer to a new value
         */
        virtual Value* operator/(const Value&) const = 0;

        //-----------------------reassign operators-----------------------------

        /**
         * @brief Returns a copy with the sign changed.
         * @return a pointer to the copy.
         */
        virtual Value* operator-() const = 0; //unary

        /**
         *@brief Changes the value to the sum of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to add.
         * @return a pointer to this
         */
        virtual Value& operator+=(const Value&) = 0;

        /**
         *@brief Changes the value to the difference of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to subtract.
         * @return a pointer to this
         */
        virtual Value& operator-=(const Value&) = 0;

        /**
         *@brief Changes the value to the product of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to multiply by.
         * @return a pointer to this
         */
        virtual Value& operator*=(const Value&) = 0;

        /**
         *@brief Changes the value to the division of this by the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to divide by.
         * @return a pointer to this
         */
        virtual Value& operator/=(const Value&) = 0;

        /**
         * @brief Checks whether the values are the same. Effectively calls
         * \ref equals. Throws an exception if the types are different.
         * @param other the value to compare
         * @return true if they are the same, false otherwise
         */
        virtual Value* operator==(const Value&) const = 0;

        /**
         * @brief Checks whether the values are different. Effectively calls
         * \ref not_equals(). Throws an exception if the types are different.
         * @param other the value to compare
         * @return false if they are the same, true otherwise
         */
        virtual Value* operator!=(const Value&) const = 0;

        /**
         * @brief Checks whether this is smaller than the right hand side value.
         * @param other the value to compare.
         * @return true if this is strictly smaller, false otherwise.
         */
        virtual Value* operator<(const Value&) const = 0;

        /**
         * @brief Checks whether this is smaller or equal to the right hand side
         * value.
         * @param other the value to compare.
         * @return false if this is strictly greater, true otherwise.
         */
        virtual Value* operator<=(const Value&) const = 0;

        /**
         * @brief Checks whether this is greater than the right hand side value.
         * @param other the value to compare.
         * @return true if this is strictly greater, false otherwise.
         */
        virtual Value* operator>(const Value&) const = 0;

        /**
         * @brief Checks whether this is smaller than the right hand side value.
         * @param other the value to compare.
         * @return false if this is strictly smaller, true otherwise.
         */
        virtual Value* operator>=(const Value&) const = 0;

        /**
         * @brief Checks whether at least one of the two values is true. Throws
         * an exception if one of the types is not a bool. 
         * @param other the value to logically compare.
         * @return false if none of the values is true, true otherwise.
         */
        virtual Value* operator||(const Value&) const = 0;


        /**
         * @brief Checks whether the two values is true. Throws
         * an exception if one of the types is not a bool.
         * @param other the value to logically compare.
         * @return true if both of the values are true, false otherwise.
         */
        virtual Value* operator&&(const Value&) const = 0;


        /**
         * @brief Logically inverts the value. Throws an exception if it's not a
         * bool.
         * @return true if false, false if true.
         */
        virtual Value* operator!() const = 0;
    };
}

#endif