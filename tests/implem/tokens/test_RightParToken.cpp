#define BOOST_TEST_MODULE RightParTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/RightParToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::RightPar_Token* tok = new Sawoca::RightPar_Token();
    BOOST_CHECK_NE(tok, nullptr);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::RightPar_Token tok;
    BOOST_CHECK_EQUAL(tok.get_string_type(), "RP");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::RightPar_Token tok;
    BOOST_CHECK_THROW(tok.get_value(), std::string);
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::RightPar_Token tok;
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::RP);
}