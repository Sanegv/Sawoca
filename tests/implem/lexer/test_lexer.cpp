#define BOOST_TEST_MODULE LexerTest
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/lexer/headers/Lexer.h"

BOOST_AUTO_TEST_CASE(test_fail){
    BOOST_CHECK_EQUAL(0, 1);
}