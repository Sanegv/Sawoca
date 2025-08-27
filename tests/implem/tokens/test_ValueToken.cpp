#include <boost/test/tools/old/interface.hpp>
#define BOOST_TEST_MODULE ValueTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/ValueToken.h"
#include "../../../implem/values/headers/Double.h"
#include "../../../implem/values/headers/Bool.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::Value_Token* tok = new Sawoca::Value_Token(new Sawoca::Double());
    BOOST_CHECK_NE(tok, nullptr);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok->get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), 0.0);
    delete tok;

    tok = new Sawoca::Value_Token(new Sawoca::Bool(false));
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), false);
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::Value_Token tokd(new Sawoca::Double());
    BOOST_CHECK_EQUAL(tokd.get_string_type(), "double");
    Sawoca::Value_Token tokb(new Sawoca::Bool(true));
    BOOST_CHECK_EQUAL(tokb.get_string_type(), "bool");
}

BOOST_AUTO_TEST_CASE(test_get_value){
    Sawoca::Value_Token tokd(new Sawoca::Double(3.14));
    const Sawoca::Double* vald = dynamic_cast<const Sawoca::Double*>(tokd.get_value());
    BOOST_CHECK_NE(vald, nullptr);
    BOOST_CHECK_EQUAL(vald->get_val(), 3.14);

    Sawoca::Value_Token tokb(new Sawoca::Bool(true));
    const Sawoca::Bool* valb = dynamic_cast<const Sawoca::Bool*>(tokb.get_value());
    BOOST_CHECK_NE(valb, nullptr);
    BOOST_CHECK_EQUAL(valb->get_val(), true);
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::Value_Token tok(new Sawoca::Double());
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::VALUE);
}