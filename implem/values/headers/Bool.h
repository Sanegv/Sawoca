#ifndef DEFINE_SAWOCA_BOOL
#define DEFINE_SAWOCA_BOOL

#include "Value.h"
namespace Sawoca {
    class Bool : public Value {
    private:
        bool val;
        virtual void pureVirtual() override {} 
        Bool() = delete;

    public:
        /**
         * @brief Creates a new Sawoca boolean.
         * @param val either true or false.
         */
        Bool(bool val);

        /**
         * @brief Accessor for the val field.
         * @return Either true or false.
         */
        bool get_val();
        
        /**
		* @brief Accessor for the type field of a token, in human readable form.
		*
		* @return the name of the type of the token.
		*/
        virtual std::string get_string_type() const override;

        /**
         * @brief stringifies the value stored.
         * @return the string representation of the value inside. 
         */
        virtual std::string string() const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* add(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* sub(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* mul(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* div(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* operator+(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* operator-(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* operator*(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI* operator/(const ValueI&) const override;

        /**
         *@brief throws an error.
         */
        virtual ValueI& operator+=(const ValueI&) override;

        /**
         *@brief throws an error.
         */
        virtual ValueI& operator-=(const ValueI&) override;

        /**
         *@brief throws an error.
         */
        virtual ValueI& operator*=(const ValueI&) override;

        /**
         *@brief throws an error.
         */
        virtual ValueI& operator/=(const ValueI&) override;

        /**
         * @brief Checks whether the values are the same. Throws an exception
         * if the types are different.
         * @param other the value to compare
         * @return true if they are the same, false otherwise
         */
        virtual const Value& equals(const ValueI&) const override;

        /**
         * @brief Checks whether the values are different. Throws an exception
         * if the types are different.
         * @param other the value to compare
         * @return false if they are the same, true otherwise
         */
        virtual const Value& not_equals(const ValueI&) const override;

        /**
         * @brief Checks whether the values are the same. Effectively calls
         * \ref equals. Throws an exception if the types are different.
         * @param other the value to compare
         * @return true if they are the same, false otherwise
         */
        virtual const Value& operator==(const ValueI&) const override;

        /**
         * @brief Checks whether the values are different. Effectively calls
         * \ref not_equals(). Throws an exception if the types are different.
         * @param other the value to compare
         * @return false if they are the same, true otherwise
         */
        virtual const Value& operator!=(const ValueI&) const override;

        /**
         * @brief Checks whether at least one of the two values is true. Throws
         * an exception if one of the types is not a bool.
         */
        virtual const Value& logical_or(const ValueI&) const override;

        /**
         * @brief Checks whether at least one of the two values is true. Throws
         * an exception if one of the types is not a bool. Effectively calls
         * \ref loical_or().
         */
        virtual const Value& operator||(const ValueI&) const override;

        /**
         * @brief Checks whether at least one of the two values is true. Throws
         * an exception if one of the types is not a bool.
         */
        virtual const Value& logical_and(const ValueI&) const override;


        /**
         * @brief Checks whether the two values is true. Throws
         * an exception if one of the types is not a bool.Effectively calls
         * \ref loical_and().
         */
        virtual const Value& operator&&(const ValueI&) const override;

        /**
         * @brief Logically inverts the value. Throws an exception if it's not a
         * bool.
         * @return true if false, false if true.
         */
        virtual const Value& logical_not() const override;


        /**
         * @brief Logically inverts the value. Throws an exception if it's not a
         * bool. Effectively calls \ref logical_not().
         * @return true if false, false if true.
         */
        virtual const Value& operator!() const override;
    };
}

#endif