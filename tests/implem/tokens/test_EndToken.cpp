#define BOOST_TEST_MODULE EndTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/EndToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::End_Token* tok = new Sawoca::End_Token();
    BOOST_CHECK_NE(tok, nullptr);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::End_Token tok;
    BOOST_CHECK_EQUAL(tok.get_string_type(), "END");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::End_Token tok;
    BOOST_CHECK_THROW(tok.get_value(), std::string);
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::End_Token tok;
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::END);
}