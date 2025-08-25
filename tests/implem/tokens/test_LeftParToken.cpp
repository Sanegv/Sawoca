#define BOOST_TEST_MODULE LeftParTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/LeftParToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::LeftPar_Token* tok = new Sawoca::LeftPar_Token();
    BOOST_CHECK_NE(tok, nullptr);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::LeftPar_Token tok;
    BOOST_CHECK_EQUAL(tok.get_string_type(), "LP");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::LeftPar_Token tok;
    BOOST_CHECK_THROW(tok.get_value(), std::string);
}



BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::LeftPar_Token tok;
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::LP);
}