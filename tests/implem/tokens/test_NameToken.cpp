#define BOOST_TEST_MODULE NameTokenTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/tokens/headers/NameToken.h"
#include "../../../implem/values/headers/Double.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    std::map<std::string, const Language::Values::ValueI*> table;
    std::string name = "pi";
    Sawoca::Double d(3.14);
    table[name] = &d;
    Sawoca::Name_Token* tok = new Sawoca::Name_Token(name, table);
    BOOST_CHECK_NE(tok, nullptr);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok->get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), d.get_val());
    delete tok;
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    std::map<std::string, const Language::Values::ValueI*> table;
    Sawoca::Name_Token tok("test", table);
    BOOST_CHECK_EQUAL(tok.get_string_type(), "NAME");
}

BOOST_AUTO_TEST_CASE(test_get_type){
    std::map<std::string, const Language::Values::ValueI*> table;
    Sawoca::Name_Token tok("test", table);
    BOOST_CHECK_EQUAL(tok.get_type(), Sawoca::NAME);
}

BOOST_AUTO_TEST_CASE(test_get_value){
    std::map<std::string, const Language::Values::ValueI*> table;
    std::string name = "pi";
    Sawoca::Double d(3.14);
    table[name] = &d;
    Sawoca::Name_Token tok(name, table);
    const Sawoca::Double* val = dynamic_cast<const Sawoca::Double*>(tok.get_value());
    BOOST_CHECK_NE(val, nullptr);
    BOOST_CHECK_EQUAL(val->get_val(), d.get_val());
    Sawoca::Name_Token fail("test", table);
    BOOST_CHECK_THROW(fail.get_value(), std::string);
}