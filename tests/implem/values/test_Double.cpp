#define BOOST_TEST_MODULE DoubleTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/values/headers/Double.h"

BOOST_AUTO_TEST_CASE(test_default_constructor){
    Sawoca::Double d;
    BOOST_CHECK_CLOSE(d.get_val(), 0.0, 1e-9);
}

BOOST_AUTO_TEST_CASE(test_double_constructor){
    double expected = 4.2145;
    Sawoca::Double d(expected);
    BOOST_CHECK_CLOSE(d.get_val(), expected, 1e-9);
}

BOOST_AUTO_TEST_CASE(test_get_val){
    double expected = 6.39157;
    Sawoca::Double d(expected);
    BOOST_CHECK_CLOSE(d.get_val(), expected, 1e-9);
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    std::string expected = "double";
    Sawoca::Double d1;
    Sawoca::Double d2(31.415);
    BOOST_CHECK_EQUAL(expected, d1.get_string_type());
    BOOST_CHECK_EQUAL(expected, d2.get_string_type());
}

BOOST_AUTO_TEST_CASE(test_string){
    std::string expected = "45.124";
    Sawoca::Double d(45.124);
    BOOST_CHECK_EQUAL(expected, d.string());
}