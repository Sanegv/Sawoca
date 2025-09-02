#include <boost/test/tools/old/interface.hpp>
#define BOOST_TEST_MODULE DoubleTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/values/headers/Double.h"
#include "../../../implem/values/headers/Bool.h"

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

BOOST_AUTO_TEST_CASE(test_operator_plus){
    Sawoca::Double expected(8.34);
    Sawoca::Double a = 5.17;
    Sawoca::Double b = 3.17;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a + b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_THROW(a + Sawoca::Bool(false), std::string);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_plus_equal){
    Sawoca::Double expected(7.13);
    Sawoca::Double a = 4.89;
    Sawoca::Double b = 2.24;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a += b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
    BOOST_CHECK_THROW(a += Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_minus){
    Sawoca::Double expected(3.17);
    Sawoca::Double a = 8.34;
    Sawoca::Double b = 5.17;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a - b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
    BOOST_CHECK_THROW(a - Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_minus_equal){
    Sawoca::Double expected(4.89);
    Sawoca::Double a = 7.13;
    Sawoca::Double b = 2.24;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a -= b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
    BOOST_CHECK_THROW(a -= Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_times){
    Sawoca::Double expected(16.68);
    Sawoca::Double a = 8.34;
    Sawoca::Double b = 2.0;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a * b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
    BOOST_CHECK_THROW(a * Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_times_equal){
    Sawoca::Double expected(9.68);
    Sawoca::Double a = 4.84;
    Sawoca::Double b = 2.0;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a *= b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
    BOOST_CHECK_THROW(a *= Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_slash){
    Sawoca::Double expected(8.34);
    Sawoca::Double a = 16.68;
    Sawoca::Double b = 2.0;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a / b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_THROW(a / Sawoca::Double(0), std::string);
    BOOST_CHECK_THROW(a / Sawoca::Bool(false), std::string);
    delete result;
    BOOST_CHECK_THROW(a / Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_slash_equal){
    Sawoca::Double expected(4.84);
    Sawoca::Double a = 9.68;
    Sawoca::Double b = 2.0;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a /= b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
    BOOST_CHECK_THROW(a /= Sawoca::Double(0), std::string);
    BOOST_CHECK_THROW(a /= Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_unary_operator_minus){
    double expected(5.87);
    Sawoca::Double positive(expected);
    Sawoca::Value* negative = -positive;
    const Sawoca::Double* dneg = dynamic_cast<const Sawoca::Double*>(negative);
    BOOST_CHECK_NE(dneg, nullptr);
    BOOST_CHECK_EQUAL(dneg->get_val(), -expected);
    delete negative;
}

BOOST_AUTO_TEST_CASE(test_operator_equal_equal){
    Sawoca::Double a(3.14);
    Sawoca::Double b(3.14);
    Sawoca::Double c(3.15);

    const Sawoca::Value* result = a == b;
    const Sawoca::Bool* bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a == a;
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a == c;
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), false);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_not_equal){
    Sawoca::Double a(3.14);
    Sawoca::Double b(3.14);
    Sawoca::Double c(3.15);
    const Sawoca::Value* result = a != b;
    const Sawoca::Bool* bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), false);
    delete result;

    result = a != a;
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), false);
    delete result;

    result = a != c;
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_or){
    Sawoca::Double a;
    BOOST_CHECK_THROW((a || a), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_and){
    Sawoca::Double a;
    BOOST_CHECK_THROW((a && a), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_not){
    Sawoca::Double a;
    BOOST_CHECK_THROW((!a), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_lesser){
    Sawoca::Double a = 4.34;
    Sawoca::Double b = 5.17;

    const Sawoca::Bool* result = dynamic_cast<const Sawoca::Bool*>(a < b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), true);
    delete result;

    result = dynamic_cast<const Sawoca::Bool*>(b < a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), false);
    delete result;
    
    result = dynamic_cast<const Sawoca::Bool*>(a < a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), false);
    delete result;

    BOOST_CHECK_THROW(a < Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_lesser_eq){
    Sawoca::Double a = 4.34;
    Sawoca::Double b = 5.17;

    const Sawoca::Bool* result = dynamic_cast<const Sawoca::Bool*>(a <= b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), true);
    delete result;

    result = dynamic_cast<const Sawoca::Bool*>(b <= a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), false);
    delete result;
    
    result = dynamic_cast<const Sawoca::Bool*>(a <= a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), true);
    delete result;

    BOOST_CHECK_THROW(a <= Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_greater){
    Sawoca::Double a = 4.34;
    Sawoca::Double b = 5.17;

    const Sawoca::Bool* result = dynamic_cast<const Sawoca::Bool*>(a > b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), false);
    delete result;

    result = dynamic_cast<const Sawoca::Bool*>(b > a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), true);
    delete result;
    
    result = dynamic_cast<const Sawoca::Bool*>(a > a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), false);
    delete result;

    BOOST_CHECK_THROW(a > Sawoca::Bool(false), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_greater_eq){
    Sawoca::Double a = 4.34;
    Sawoca::Double b = 5.17;

    const Sawoca::Bool* result = dynamic_cast<const Sawoca::Bool*>(a >= b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), false);
    delete result;

    result = dynamic_cast<const Sawoca::Bool*>(b >= a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), true);
    delete result;
    
    result = dynamic_cast<const Sawoca::Bool*>(a >= a);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_EQUAL(result->get_val(), true);
    delete result;

    BOOST_CHECK_THROW(a >= Sawoca::Bool(false), std::string);
}