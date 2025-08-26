#include <boost/test/tools/old/interface.hpp>
#define BOOST_TEST_MODULE DoubleTests
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/values/headers/Bool.h"
#include "../../../implem/values/headers/Double.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    Sawoca::Bool* b = new Sawoca::Bool(false);
    BOOST_CHECK_NE(b, nullptr);
    BOOST_CHECK_EQUAL(b->get_val(), false);
    BOOST_CHECK_NE(b->get_val(), true);
    delete b;

    b = new Sawoca::Bool(true);
    BOOST_CHECK_NE(b, nullptr);
    BOOST_CHECK_EQUAL(b->get_val(), true);
    BOOST_CHECK_NE(b->get_val(), false);
    delete b;
}

BOOST_AUTO_TEST_CASE(test_get_type){
    Sawoca::Bool b(true);
    BOOST_CHECK_EQUAL(b.get_type(), Sawoca::BOOL);
}

BOOST_AUTO_TEST_CASE(test_get_string_type){
    Sawoca::Bool b(true);
    BOOST_CHECK_EQUAL(b.get_string_type(), "bool");
}

BOOST_AUTO_TEST_CASE(test_string){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    BOOST_CHECK_EQUAL(bt.string(), "true");
    BOOST_CHECK_EQUAL(bf.string(), "false");
}

BOOST_AUTO_TEST_CASE(test_maths){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    BOOST_CHECK_THROW(bt.add(bf), std::string);
    BOOST_CHECK_THROW(bt.sub(bf), std::string);
    BOOST_CHECK_THROW(bt.mul(bf), std::string);
    BOOST_CHECK_THROW(bt.div(bf), std::string);

    BOOST_CHECK_THROW(bt + bf, std::string);
    BOOST_CHECK_THROW(bt - bf, std::string);
    BOOST_CHECK_THROW(bt * bf, std::string);
    BOOST_CHECK_THROW(bt / bf, std::string);
    BOOST_CHECK_THROW(-bf, std::string);

    BOOST_CHECK_THROW(bt += bf, std::string);
    BOOST_CHECK_THROW(bt -= bf, std::string);
    BOOST_CHECK_THROW(bt *= bf, std::string);
    BOOST_CHECK_THROW(bt /= bf, std::string);
}

BOOST_AUTO_TEST_CASE(test_equal){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf.equals(bt);
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;
    Sawoca::Double d;
    BOOST_CHECK_THROW(bf.equals(d), std::string);
}

BOOST_AUTO_TEST_CASE(test_not_equal){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf.not_equals(bt);
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;
    Sawoca::Double d;
    BOOST_CHECK_THROW(bf.not_equals(d), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_equal){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf == bt;
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;
    Sawoca::Double d;
    BOOST_CHECK_THROW((bf == d), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_not_equal){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf != bt;
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;
    Sawoca::Double d;
    BOOST_CHECK_THROW((bf != d), std::string);
}

BOOST_AUTO_TEST_CASE(test_logical_or){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf.logical_or(bt);
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bt.logical_or(bf);
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bt.logical_or(bt);
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bf.logical_or(bf);
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    Sawoca::Double d;
    BOOST_CHECK_THROW(bt.logical_or(d), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_logical_or){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf || bt;
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bt || bf;
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bt || bt;
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bf || bf;
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    Sawoca::Double d;
    BOOST_CHECK_THROW(bt || d, std::string);
}

BOOST_AUTO_TEST_CASE(test_logical_and){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf.logical_and(bt);
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    compare = bt.logical_and(bf);
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    compare = bt.logical_and(bt);
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bf.logical_and(bf);
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    Sawoca::Double d;
    BOOST_CHECK_THROW(bt.logical_and(d), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_logical_and){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* compare = bf || bt;
    const Sawoca::Bool* bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    compare = bt || bf;
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    compare = bt || bt;
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), true);
    delete compare;

    compare = bf || bf;
    bcomp = dynamic_cast<const Sawoca::Bool*>(compare);
    BOOST_CHECK_EQUAL(bcomp->get_val(), false);
    delete compare;

    Sawoca::Double d;
    BOOST_CHECK_THROW(bt || d, std::string);
}

BOOST_AUTO_TEST_CASE(test_logical_not){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* lnot = bf.logical_not();
    const Sawoca::Bool* blnot = dynamic_cast<const Sawoca::Bool*>(lnot);
    BOOST_CHECK_EQUAL(blnot->get_val(), true);
    delete lnot;

    lnot = bt.logical_not();
    blnot = dynamic_cast<const Sawoca::Bool*>(lnot);
    BOOST_CHECK_EQUAL(blnot->get_val(), false);
    delete lnot;

    Sawoca::Double d;
    BOOST_CHECK_THROW(bt.logical_or(d), std::string);
}

BOOST_AUTO_TEST_CASE(test_operator_logical_not){
    Sawoca::Bool bt(true);
    Sawoca::Bool bf(false);

    const Sawoca::Value* lnot = !bf;
    const Sawoca::Bool* blnot = dynamic_cast<const Sawoca::Bool*>(lnot);
    BOOST_CHECK_EQUAL(blnot->get_val(), true);
    delete lnot;

    lnot = !bt;
    blnot = dynamic_cast<const Sawoca::Bool*>(lnot);
    BOOST_CHECK_EQUAL(blnot->get_val(), false);
    delete lnot;

    Sawoca::Double d;
    BOOST_CHECK_THROW(bt.logical_or(d), std::string);
}