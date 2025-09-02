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
    Sawoca::Operator_Token tok_o(Sawoca::L_OR);
    BOOST_CHECK_EQUAL(tok_o.get_string_type(), "OR");
    Sawoca::Operator_Token tok_a(Sawoca::L_AND);
    BOOST_CHECK_EQUAL(tok_a.get_string_type(), "AND");
    Sawoca::Operator_Token tok_n(Sawoca::L_NOT);
    BOOST_CHECK_EQUAL(tok_n.get_string_type(), "NOT");
    Sawoca::Operator_Token tok_e(Sawoca::EQ);
    BOOST_CHECK_EQUAL(tok_e.get_string_type(), "EQUALS");
    Sawoca::Operator_Token tok_ne(Sawoca::NEQ);
    BOOST_CHECK_EQUAL(tok_ne.get_string_type(), "NOT EQUALS");
    Sawoca::Operator_Token tok_l('<');
    BOOST_CHECK_EQUAL(tok_l.get_string_type(), "LESS");
    Sawoca::Operator_Token tok_le(Sawoca::LESS_EQ);
    BOOST_CHECK_EQUAL(tok_le.get_string_type(), "LESS EQ");
    Sawoca::Operator_Token tok_g('>');
    BOOST_CHECK_EQUAL(tok_g.get_string_type(), "GREAT");
    Sawoca::Operator_Token tok_ge(Sawoca::GREAT_EQ);
    BOOST_CHECK_EQUAL(tok_ge.get_string_type(), "GREAT EQ");
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
    Sawoca::Operator_Token tok_o(Sawoca::L_OR);
    BOOST_CHECK_EQUAL(tok_o.get_type(), Sawoca::L_OR);
    Sawoca::Operator_Token tok_a(Sawoca::L_AND);
    BOOST_CHECK_EQUAL(tok_a.get_type(), Sawoca::L_AND);
    Sawoca::Operator_Token tok_n(Sawoca::L_NOT);
    BOOST_CHECK_EQUAL(tok_n.get_type(), Sawoca::L_NOT);
    Sawoca::Operator_Token tok_e(Sawoca::EQ);
    BOOST_CHECK_EQUAL(tok_e.get_type(), Sawoca::EQ);
    Sawoca::Operator_Token tok_ne(Sawoca::NEQ);
    BOOST_CHECK_EQUAL(tok_ne.get_type(), Sawoca::NEQ);
    Sawoca::Operator_Token tok_l('<');
    BOOST_CHECK_EQUAL(tok_l.get_type(), Sawoca::LESSER);
    Sawoca::Operator_Token tok_le(Sawoca::LESS_EQ);
    BOOST_CHECK_EQUAL(tok_le.get_type(), Sawoca::LESS_EQ);
    Sawoca::Operator_Token tok_g('>');
    BOOST_CHECK_EQUAL(tok_g.get_type(), Sawoca::GREATER);
    Sawoca::Operator_Token tok_ge(Sawoca::GREAT_EQ);
    BOOST_CHECK_EQUAL(tok_ge.get_type(), Sawoca::GREAT_EQ);
}