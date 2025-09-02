#ifndef DEFINE_SAWOCA_DOUBLE
#define DEFINE_SAWOCA_DOUBLE

#include "Value.h"

/**
 *@file Double.h
 *@brief This file defines the Double Value class.
 *@author Sanegv
 */

namespace Sawoca {    
    /**
    * @brief This class represents the value for a literal, double value. It is
    * used to perform double precision floating point operations. It inherits
    * from the \ref Value abstract class.
	*/
    class Double  : public Value {
    private:
        double val;
        virtual void pureVirtual() override {} 

    public:         
		/**
		 * @brief Creates a double with value 0.0.
		 */
        Double();

		/**
		 * @brief Creates a double with the specified value.
		 *
		 * @param d the value of the double.
		 */
        Double(double d);

		/**
		 * @brief Accessor for the litteral value of a double.
		 *
		 * @return a copy of the double value stored.
		 */
        double get_val() const;

        /**
         * @brief stringifies the type of the value.
         * @return a string saying "DOUBLE" 
         */
        virtual std::string get_string_type() const override;

        /**
         * @brief stringifies the value stored.
         * @return the string representation of the value inside. 
         */
        virtual std::string string() const override;

        //-------------------------const operators------------------------------

        /**
         *@brief Creates a new Double value equal to the sum of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * Effectively calls \ref add.
         * @param other the value to add.
         * @return a pointer to a new value
         */
        virtual Value* operator+(const Value&) const override;

        /**
         *@brief Creates a new Double value equal to the difference between this
         * and the other number. Throws an exception in case of an invalid type.
         * Effectively calls \ref sub.
         * @param other the value to subtract.
         * @return a pointer to a new value
         */
        virtual Value* operator-(const Value&) const override;

        /**
         *@brief Creates a new Double value equal to the product of this and the 
         * other number. Throws an exception in case of an invalid type.
         * Effectively calls \ref mul.
         * @param other the value to multiply by.
         * @return a pointer to a new value
         */
        virtual Value* operator*(const Value&) const override;

        /**
         *@brief Creates a new Double value equal to the division of this by the 
         * other number. Throws an exception in case of an invalid type or of a
         * division by zero.
         * Effectively calls \ref div.
         * @param other the denominator to divide by.
         * @return a pointer to a new value
         */
        virtual Value* operator/(const Value&) const override;

        //reassign operators

        /**
         * @brief Changes the sign of the value stored inside.
         * @return a pointer to this.
         */
        virtual Value* operator-() const override;

        /**
         *@brief Changes the value to the sum of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to add.
         * @return a pointer to this
         */
        virtual Value& operator+=(const Value&) override;

        /**
         *@brief Changes the value to the difference of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to subtract.
         * @return a pointer to this
         */
        virtual Value& operator-=(const Value&) override;

        /**
         *@brief Changes the value to the product of this and the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to multiply by.
         * @return a pointer to this
         */
        virtual Value& operator*=(const Value&) override;

        /**
         *@brief Changes the value to the division of this by the 
         * other number. Throws an exception in case of an invalid type. 
         * @param other the value to divide by.
         * @return a pointer to this
         */
        virtual Value& operator/=(const Value&) override;

        /**
         * @brief Checks whether the values are the same. Effectively calls
         * \ref equals.
         * @param other the value to compare
         * @return true if they are the same, false otherwise
         */
        virtual Value* operator==(const Value&) const override;

        /**
         * @brief Checks whether the values are different. Effectively calls
         * \ref not_equals()
         * @param other the value to compare
         * @return false if they are the same, true otherwise
         */
        virtual Value* operator!=(const Value&) const override;

        /**
         * @brief Checks whether this is smaller than the right hand side value.
         * @param other the value to compare.
         * @return true if this is strictly smaller, false otherwise.
         */
        virtual Value* operator<(const Value&) const override;

        /**
         * @brief Checks whether this is smaller or equal to the right hand side
         * value.
         * @param other the value to compare.
         * @return false if this is strictly greater, true otherwise.
         */
        virtual Value* operator<=(const Value&) const override;

        /**
         * @brief Checks whether this is greater than the right hand side value.
         * @param other the value to compare.
         * @return true if this is strictly greater, false otherwise.
         */
        virtual Value* operator>(const Value&) const override;

        /**
         * @brief Checks whether this is smaller than the right hand side value.
         * @param other the value to compare.
         * @return false if this is strictly smaller, true otherwise.
         */
        virtual Value* operator>=(const Value&) const override;

        /**
         * @brief Throws an exception.
         */
        virtual Value* operator||(const Value&) const override;


        /**
         * @brief Throws an exception.
         */
        virtual Value* operator&&(const Value&) const override;


        /**
         * @brief Throws an exception.
         */
        virtual Value* operator!() const override;
    };
}

#endif