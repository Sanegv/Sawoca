#define BOOST_TEST_MODULE NumberTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/NumberToken.h"

BOOST_AUTO_TEST_CASE(test_fail){
    BOOST_CHECK_EQUAL(0, 1);
}