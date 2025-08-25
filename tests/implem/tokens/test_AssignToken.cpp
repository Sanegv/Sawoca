#define BOOST_TEST_MODULE AssignTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/AssignToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::Assign_Token* tok = new Sawoca::Assign_Token();
    BOOST_CHECK_NE(tok, nullptr);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::Assign_Token tok;
    BOOST_CHECK_EQUAL(tok.get_string_type(), "ASSIGN");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::Assign_Token tok;
    BOOST_CHECK_THROW(tok.get_value(), std::string);
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::Assign_Token tok;
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::ASSIGN);
}