#include <boost/test/tools/old/interface.hpp>
#define BOOST_TEST_MODULE NumberTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/NumberToken.h"
#include "../../../implem/values/headers/Double.h"

BOOST_AUTO_TEST_CASE(test_default_constructor){
    Sawoca::Number_Token* tok = new Sawoca::Number_Token();
    BOOST_CHECK_NE(tok, nullptr);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok->get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), 0.0);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_primitive_double_constructor){
    double expected = 3.14;
    Sawoca::Number_Token* tok = new Sawoca::Number_Token(expected);
    BOOST_CHECK_NE(tok, nullptr);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok->get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), expected);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_sawoca_double_constructor){
    Sawoca::Double* expected = new Sawoca::Double(3.14);
    Sawoca::Number_Token* tok = new Sawoca::Number_Token(expected);
    BOOST_CHECK_NE(tok, nullptr);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok->get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), expected->get_val());
    BOOST_CHECK_EQUAL(tok->get_value(), expected);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::Number_Token tok;
    BOOST_CHECK_EQUAL(tok.get_string_type(), "NUMBER");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::Number_Token tok(3.14);
    Sawoca::Double* d = new Sawoca::Double(3.14);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok.get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), d->get_val());
    delete d;
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::Number_Token tok;
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::NUMBER);
}