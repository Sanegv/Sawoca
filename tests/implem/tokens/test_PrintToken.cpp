#define BOOST_TEST_MODULE PrintTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/PrintToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::Print_Token* tok = new Sawoca::Print_Token();
    BOOST_CHECK_NE(tok, nullptr);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::Print_Token tok;
    BOOST_CHECK_EQUAL(tok.get_string_type(), "PRINT");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::Print_Token tok;
    BOOST_CHECK_THROW(tok.get_value(), std::string);
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::Print_Token tok;
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::PRINT);
}