#define BOOST_TEST_MODULE PrintTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/PrintToken.h"

BOOST_AUTO_TEST_CASE(test_fail){
    BOOST_CHECK_EQUAL(0, 1);
}