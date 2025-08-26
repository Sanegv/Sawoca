#include <boost/test/tools/old/interface.hpp>
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
#include "../../../implem/tokens/headers/NumberToken.h"
#include "../../../implem/tokens/headers/OperatorToken.h"
#include "../../../implem/tokens/headers/PrintToken.h"
#include "../../../implem/tokens/headers/LeftParToken.h"
#include "../../../implem/tokens/headers/RightParToken.h"
#include "../../../implem/tokens/headers/AssignToken.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser* parser = new Sawoca::Parser(table);
    BOOST_CHECK_NE(parser, nullptr);
    delete parser;
}

BOOST_AUTO_TEST_CASE(test_parse_number){
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Number_Token(3.14),
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
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Number_Token(3.14),
        new Sawoca::Operator_Token('+'),
        new Sawoca::Number_Token(2.46),
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
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Number_Token(1),
        new Sawoca::Operator_Token('+'),
        new Sawoca::Number_Token(2),
        new Sawoca::Operator_Token('*'),
        new Sawoca::Number_Token(3),
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
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::LeftPar_Token(),
        new Sawoca::Number_Token(1),
        new Sawoca::Operator_Token('+'),
        new Sawoca::Number_Token(2),
        new Sawoca::RightPar_Token(),
        new Sawoca::Operator_Token('*'),
        new Sawoca::Number_Token(3),
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
    std::map<std::string, const Sawoca::Value*> table;
    Sawoca::Parser parser(table);

    std::vector<Language::Tokens::TokenI*> tokens {
        new Sawoca::Name_Token("test", table),
        new Sawoca::Assign_Token(),
        new Sawoca::Number_Token(4.5),
        new Sawoca::Print_Token(),
        new Sawoca::Name_Token("test", table),
        new Sawoca::Operator_Token('*'),
        new Sawoca::Number_Token(2),
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

BOOST_AUTO_TEST_CASE(test_parser_error){
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
        new Sawoca::Number_Token(1),
        new Sawoca::Operator_Token('/'),
        new Sawoca::Number_Token(),
        new Sawoca::End_Token()
    };
    BOOST_CHECK_THROW(parser.parse(div_by_zero), std::string);
    for(auto tok : div_by_zero)
        delete tok;
}