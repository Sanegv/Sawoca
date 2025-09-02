#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include <vector>
#define BOOST_TEST_MODULE ParserTest
#include <boost/test/included/unit_test.hpp>

#include "../../../implem/parser/headers/Parser.h"

#include "../../../implem/tokens/headers/EndToken.h"
#include "../../../implem/tokens/headers/NameToken.h"
#include "../../../implem/tokens/headers/ValueToken.h"
#include "../../../implem/tokens/headers/OperatorToken.h"
#include "../../../implem/tokens/headers/PrintToken.h"
#include "../../../implem/tokens/headers/LeftParToken.h"
#include "../../../implem/tokens/headers/RightParToken.h"
#include "../../../implem/tokens/headers/AssignToken.h"

#include "../../../implem/values/headers/Double.h"
#include "../../../implem/values/headers/Bool.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    std::cout << "constructor\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser* parser = new Sawoca::Parser(table);
    BOOST_CHECK_NE(parser, nullptr);
    delete parser;
}

BOOST_AUTO_TEST_CASE(test_parse_value){
    std::cout << "value\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Value_Token(new Sawoca::Double(3.14)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(tokens);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "3.14\n");

    for(auto tok : tokens)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_parse_addition){
    std::cout << "addition\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Value_Token(new Sawoca::Double(3.14)),
        new Sawoca::Operator_Token('+'),
        new Sawoca::Value_Token(new Sawoca::Double(2.46)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(tokens);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "5.6\n");

    for(auto tok : tokens)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_parse_precedence){
    std::cout << "precedence\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Value_Token(new Sawoca::Double(1)),
        new Sawoca::Operator_Token('+'),
        new Sawoca::Value_Token(new Sawoca::Double(2)),
        new Sawoca::Operator_Token('*'),
        new Sawoca::Value_Token(new Sawoca::Double(3)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(tokens);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "7\n");

    for(auto tok : tokens)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_parse_paranthesis){
    std::cout << "paranthesis\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::LeftPar_Token(),
        new Sawoca::Value_Token(new Sawoca::Double(1)),
        new Sawoca::Operator_Token('+'),
        new Sawoca::Value_Token(new Sawoca::Double(2)),
        new Sawoca::RightPar_Token(),
        new Sawoca::Operator_Token('*'),
        new Sawoca::Value_Token(new Sawoca::Double(3)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(tokens);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "9\n");

    for(auto tok : tokens)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_parse_variables){
    std::cout << "variables\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Name_Token("test", table),
        new Sawoca::Assign_Token(),
        new Sawoca::Value_Token(new Sawoca::Double(4.5)),
        new Sawoca::Print_Token(),
        new Sawoca::Name_Token("test", table),
        new Sawoca::Operator_Token('*'),
        new Sawoca::Value_Token(new Sawoca::Double(2)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(tokens);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "4.5\n9\n");

    for(auto tok : tokens)
        delete tok;
    for(auto [_, val] : table)
        delete val;
}

BOOST_AUTO_TEST_CASE(test_parse_boolean_value){
    std::cout << "bool value\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> boolean_value {
        new Sawoca::Value_Token(new Sawoca::Bool(true)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(boolean_value);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "true\n");

    for(auto tok : boolean_value)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_left_to_right_comparison){
    std::cout << "comparison\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> left_to_right_comparison {
        new Sawoca::Value_Token(new Sawoca::Double(7.86)),
        new Sawoca::Operator_Token(Sawoca::EQ),
        new Sawoca::Value_Token(new Sawoca::Double(0.28)),
        new Sawoca::Operator_Token(Sawoca::NEQ),
        new Sawoca::Operator_Token(Sawoca::L_NOT),
        new Sawoca::Value_Token(new Sawoca::Bool(false)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(left_to_right_comparison);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "true\n");

    for(auto tok : left_to_right_comparison)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_logical_precedence){
    std::cout << "logical precedence\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> logical_precedence {
        new Sawoca::Value_Token(new Sawoca::Double(1.2)),
        new Sawoca::Operator_Token(Sawoca::LESS_EQ),
        new Sawoca::Value_Token(new Sawoca::Double(3.8)),
        new Sawoca::Operator_Token(Sawoca::EQ),
        new Sawoca::Value_Token(new Sawoca::Double(6.6)),
        new Sawoca::Operator_Token(Sawoca::GREATER),
        new Sawoca::Value_Token(new Sawoca::Double(6.6)),
        new Sawoca::Operator_Token(Sawoca::L_AND),
        new Sawoca::Value_Token(new Sawoca::Double(7.4)),
        new Sawoca::Operator_Token(Sawoca::GREAT_EQ),
        new Sawoca::Value_Token(new Sawoca::Double(2)),
        new Sawoca::Operator_Token(Sawoca::NEQ),
        new Sawoca::Value_Token(new Sawoca::Double(8)),
        new Sawoca::Operator_Token(Sawoca::LESS_EQ),
        new Sawoca::Value_Token(new Sawoca::Double(8)),
        new Sawoca::End_Token
    };

    std::streambuf* orig = std::cout.rdbuf();
    std::ostringstream captured;
    std::cout.rdbuf(captured.rdbuf());

    parser.parse(logical_precedence);

    std::cout.rdbuf(orig);
    BOOST_CHECK_EQUAL(captured.str(), "false\n");

    for(auto tok : logical_precedence)
        delete tok;
}

BOOST_AUTO_TEST_CASE(test_parser_error){
    std::cout << "errors\n";
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> undeclared_var {
        new Sawoca::Name_Token("test", table),
        new Sawoca::End_Token
    };
    BOOST_CHECK_THROW(parser.parse(undeclared_var), std::string);
    for(auto tok : undeclared_var)
        delete tok;

    std::vector<Language::Tokens::TokenI*> div_by_zero{
        new Sawoca::Value_Token(new Sawoca::Double(1)),
        new Sawoca::Operator_Token('/'),
        new Sawoca::Value_Token(new Sawoca::Double()),
        new Sawoca::End_Token()
    };
    BOOST_CHECK_THROW(parser.parse(div_by_zero), std::string);
    for(auto tok : div_by_zero)
        delete tok;

    std::vector<Language::Tokens::TokenI*> wrong_comparison{
        new Sawoca::Value_Token(new Sawoca::Double(1)),
        new Sawoca::Operator_Token(Sawoca::EQ),
        new Sawoca::Value_Token(new Sawoca::Double()),
        new Sawoca::Operator_Token(Sawoca::EQ),
        new Sawoca::Value_Token(new Sawoca::Double(3.8)),
        new Sawoca::End_Token()
    };
    BOOST_CHECK_THROW(parser.parse(wrong_comparison), std::string);
    for(auto tok : wrong_comparison)
        delete tok;
}