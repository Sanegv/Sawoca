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

        //const operations

        /**
         *@brief Creates a new Value equal to the sum of this and the 
         * other number. Throws an exception in case of an invalid type.
         * @param other the value to add.
         * @return a pointer to a new value
         */
        virtual ValueI* add(const ValueI* const) const = 0;

        /**
         *@brief Creates a new Value equal to the difference between this
         * and the other number. Throws an exception in case of an invalid type.
         * @param other the value to subtract.
         * @return a pointer to a new value
         */
        virtual ValueI* sub(const ValueI* const) const = 0;

        /**
         *@brief Creates a new Value equal to the product of this and the 
         * other number. Throws an exception in case of an invalid type.
         * @param other the value to multiply by.
         * @return a pointer to a new value
         */
        virtual ValueI* mul(const ValueI* const) const = 0;

        /**
         *@brief Creates a new Value equal to the division of this by the 
         * other number. Throws an exception in case of an invalid type or of a
         * division by zero.
         * @param other the denominator to divide by.
         * @return a pointer to a new value
         */
        virtual ValueI* div(const ValueI* const) const = 0;

        //const operators

        /**
         *@brief Creates a new Value equal to the sum of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * Effectively calls \ref add.
         * @param other the value to add.
         * @return a pointer to a new value
         */
        virtual ValueI* operator+(const ValueI* const) const = 0;

        /**
         *@brief Creates a new Value equal to the difference between this
         * and the other number. Throws an exception in case of an invalid type.
         * Effectively calls \ref sub.
         * @param other the value to subtract.
         * @return a pointer to a new value
         */
        virtual ValueI* operator-(const ValueI* const) const = 0;

        /**
         *@brief Creates a new Value equal to the product of this and the 
         * other number. Throws an exception in case of an invalid type.
         * Effectively calls \ref mul.
         * @param other the value to multiply by.
         * @return a pointer to a new value
         */
        virtual ValueI* operator*(const ValueI* const) const = 0;

        /**
         *@brief Creates a new Value equal to the division of this by the 
         * other number. Throws an exception in case of an invalid type or of a
         * division by zero.
         * Effectively calls \ref div.
         * @param other the denominator to divide by.
         * @return a pointer to a new value
         */
        virtual ValueI* operator/(const ValueI* const) const = 0;

        //reassign operators

        /**
         * @brief Changes the sign of the value stored inside.
         * @return a pointer to this.
         */
        virtual ValueI* operator-() = 0; //unary

        /**
         *@brief Changes the value to the sum of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to add.
         * @return a pointer to this
         */
        virtual ValueI& operator+=(const ValueI&) = 0;

        /**
         *@brief Changes the value to the difference of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to subtract.
         * @return a pointer to this
         */
        virtual ValueI& operator-=(const ValueI&) = 0;

        /**
         *@brief Changes the value to the product of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to multiply by.
         * @return a pointer to this
         */
        virtual ValueI& operator*=(const ValueI&) = 0;

        /**
         *@brief Changes the value to the division of this by the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to divide by.
         * @return a pointer to this
         */
        virtual ValueI& operator/=(const ValueI&) = 0;
    };
}

#endif