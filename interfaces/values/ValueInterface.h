#ifndef DEFINE_VALUE_INTERFACE
#define DEFINE_VALUE_INTERFACE

namespace Language {
    namespace Values {
        class ValueI {
        private:
            virtual void pureVirtual() = 0;
        public:
            virtual ~ValueI() = default;
        };
    }
}

#endif