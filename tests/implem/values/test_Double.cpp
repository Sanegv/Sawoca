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

BOOST_AUTO_TEST_CASE(test_add){
    Sawoca::Double expected(4.18);
    Sawoca::Double a = 2.57;
    Sawoca::Double b = 1.61;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>((a.add(b)));
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_plus){
    Sawoca::Double expected(8.34);
    Sawoca::Double a = 5.17;
    Sawoca::Double b = 3.17;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a + b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_plus_equal){
    Sawoca::Double expected(7.13);
    Sawoca::Double a = 4.89;
    Sawoca::Double b = 2.24;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a += b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
}

BOOST_AUTO_TEST_CASE(test_sub){
    Sawoca::Double expected(1.61);
    Sawoca::Double a = 4.18;
    Sawoca::Double b = 2.57;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>((a.sub(b)));
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_minus){
    Sawoca::Double expected(3.17);
    Sawoca::Double a = 8.34;
    Sawoca::Double b = 5.17;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a - b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_minus_equal){
    Sawoca::Double expected(4.89);
    Sawoca::Double a = 7.13;
    Sawoca::Double b = 2.24;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a -= b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
}

BOOST_AUTO_TEST_CASE(test_mul){
    Sawoca::Double expected(8.36);
    Sawoca::Double a = 4.18;
    Sawoca::Double b = 2.0;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>((a.mul(b)));
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_times){
    Sawoca::Double expected(16.68);
    Sawoca::Double a = 8.34;
    Sawoca::Double b = 2.0;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a * b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_times_equal){
    Sawoca::Double expected(9.68);
    Sawoca::Double a = 4.84;
    Sawoca::Double b = 2.0;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a *= b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
}

BOOST_AUTO_TEST_CASE(test_div){
    Sawoca::Double expected(4.18);
    Sawoca::Double a = 8.36;
    Sawoca::Double b = 2.0;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>((a.div(b)));
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_THROW(a.div(Sawoca::Double(0)), std::string);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_slash){
    Sawoca::Double expected(8.34);
    Sawoca::Double a = 16.68;
    Sawoca::Double b = 2.0;
    Sawoca::Double* result = dynamic_cast<Sawoca::Double*>(a / b);
    BOOST_CHECK_NE(result, nullptr);
    BOOST_CHECK_CLOSE(result->get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_THROW(a / Sawoca::Double(0), std::string);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_operator_slash_equal){
    Sawoca::Double expected(4.84);
    Sawoca::Double a = 9.68;
    Sawoca::Double b = 2.0;
    Sawoca::Double& result = dynamic_cast<Sawoca::Double&>(a /= b);
    BOOST_CHECK_CLOSE(result.get_val(), expected.get_val(), 1e-9);
    BOOST_CHECK_EQUAL(&result, &a);
    BOOST_CHECK_THROW(a /= Sawoca::Double(0), std::string);
}

BOOST_AUTO_TEST_CASE(test_unary_operator_minus){
    double expected(5.87);
    Sawoca::Double positive(expected);
    Sawoca::Value* negative = -positive;
}

BOOST_AUTO_TEST_CASE(test_equal){
    Sawoca::Double a(3.14);
    Sawoca::Double b(3.14);
    Sawoca::Double c(3.15);

    const Sawoca::Value* result = a.equals(b);
    const Sawoca::Bool* bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a.equals(a);
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a.equals(c);
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), false);
    delete result;
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

BOOST_AUTO_TEST_CASE(test__not_equal){
    Sawoca::Double a(3.14);
    Sawoca::Double b(3.14);
    Sawoca::Double c(3.15);

    const Sawoca::Value* result = a.not_equals(b);
    const Sawoca::Bool* bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a.not_equals(a);
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a.not_equals(c);
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
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a != a;
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), true);
    delete result;

    result = a != c;
    bresult = dynamic_cast<const Sawoca::Bool*>(result);
    BOOST_CHECK_NE(bresult, nullptr);
    BOOST_CHECK_EQUAL(bresult->get_val(), false);
    delete result;
}

BOOST_AUTO_TEST_CASE(test_logical_or){
    Sawoca::Double a;
    BOOST_CHECK_THROW(a.logical_or(a), std::string);
}

BOOST_AUTO_TEST_CASE(test_logical_and){
    Sawoca::Double a;
    BOOST_CHECK_THROW(a.logical_and(a), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_or){
    Sawoca::Double a;
    BOOST_CHECK_THROW((a || a), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_and){
    Sawoca::Double a;
    BOOST_CHECK_THROW((a && a), std::string);
}

BOOST_AUTO_TEST_CASE(test_logical_not){
    Sawoca::Double a;
    BOOST_CHECK_THROW((a.logical_not()), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_not){
    Sawoca::Double a;
    BOOST_CHECK_THROW((!a), std::string);
}