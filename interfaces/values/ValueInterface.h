#ifndef DEFINE_VALUE_INTERFACE
#define DEFINE_VALUE_INTERFACE

/**
 *@file ValueInterface.h
 *@brief This file defines the ValueI interface.
 *@author Sanegv
 */

namespace Language {
    namespace Values {
        /**
        * @brief Represents a value, used by tokens and the parser to store
        * data.
        */
        class ValueI {
        private:
            virtual void pureVirtual() = 0;
        public:
            /**
            * @brief A standard destructor used for polymorhism.
            */
            virtual ~ValueI() = default;
        };
    }
}

#endif