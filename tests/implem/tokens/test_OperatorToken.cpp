#define BOOST_TEST_MODULE OperatorTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/OperatorToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::Operator_Token* tok = new Sawoca::Operator_Token('+');
    BOOST_CHECK_NE(tok, nullptr);
    delete tok;
    BOOST_CHECK_THROW(tok = new Sawoca::Operator_Token('a'), std::string);
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::Operator_Token tok_p('+');
    BOOST_CHECK_EQUAL(tok_p.get_string_type(), "PLUS");
    Sawoca::Operator_Token tok_mi('-');
    BOOST_CHECK_EQUAL(tok_mi.get_string_type(), "MINUS");
    Sawoca::Operator_Token tok_mu('*');
    BOOST_CHECK_EQUAL(tok_mu.get_string_type(), "MUL");
    Sawoca::Operator_Token tok_d('/');
    BOOST_CHECK_EQUAL(tok_d.get_string_type(), "DIV");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::Operator_Token tok('*');
    BOOST_CHECK_THROW(tok.get_value(), std::string);
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::Operator_Token tok_p('+');
    BOOST_CHECK_EQUAL(tok_p.get_type(), Sawoca::PLUS);
    Sawoca::Operator_Token tok_mi('-');
    BOOST_CHECK_EQUAL(tok_mi.get_type(), Sawoca::MINUS);
    Sawoca::Operator_Token tok_mu('*');
    BOOST_CHECK_EQUAL(tok_mu.get_type(), Sawoca::MUL);
    Sawoca::Operator_Token tok_d('/');
    BOOST_CHECK_EQUAL(tok_d.get_type(), Sawoca::DIV);
}