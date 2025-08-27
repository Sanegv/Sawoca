#define BOOST_TEST_MODULE LexerTest
#include <boost/test/included/unit_test.hpp>

#include <algorithm>
#include <boost/test/tools/old/interface.hpp>
#include <iterator>
#include <sstream>
#include <vector>

#include "../../../implem/lexer/headers/Lexer.h"
#include "../../../implem/tokens/headers/Token.h"

BOOST_AUTO_TEST_CASE(test_constructor){
    std::map<std::string, const Sawoca::Value*> table;
    std::string str = "test";
    std::istringstream input(str);
    Sawoca::Lexer* lexer = new Sawoca::Lexer(table, input);
    BOOST_CHECK_NE(lexer, nullptr);
    delete lexer;
}

BOOST_AUTO_TEST_CASE(test_get_token){
    std::map<std::string, const Sawoca::Value*> table;
    std::vector<Sawoca::Token_Type> expected;
    std::string text = "test true false = + - * / 1.2 () || && ! == !=";
    std::istringstream input(text);

    expected.emplace_back(Sawoca::NAME);
    expected.emplace_back(Sawoca::VALUE);
    expected.emplace_back(Sawoca::VALUE);
    expected.emplace_back(Sawoca::ASSIGN);
    expected.emplace_back(Sawoca::PLUS);
    expected.emplace_back(Sawoca::MINUS);
    expected.emplace_back(Sawoca::MUL);
    expected.emplace_back(Sawoca::DIV);
    expected.emplace_back(Sawoca::VALUE);
    expected.emplace_back(Sawoca::LP);
    expected.emplace_back(Sawoca::RP);
    expected.emplace_back(Sawoca::L_OR);
    expected.emplace_back(Sawoca::L_AND);
    expected.emplace_back(Sawoca::L_NOT);
    expected.emplace_back(Sawoca::EQ);
    expected.emplace_back(Sawoca::NEQ);
    expected.emplace_back(Sawoca::END);

    Sawoca::Lexer lexer = Sawoca::Lexer(table, input);

    for(Sawoca::Token_Type type : expected){
        Language::Tokens::TokenI* tok = lexer.get_token();
        Sawoca::Token* stok = dynamic_cast<Sawoca::Token*>(tok);
        BOOST_CHECK_NE(stok, nullptr);

        BOOST_CHECK_EQUAL(stok->get_type(), type);

        delete tok;
    }
}

BOOST_AUTO_TEST_CASE(test_lex){
    std::map<std::string, const Sawoca::Value*> table;
    std::vector<Sawoca::Token_Type> expected;
    std::string text = "test true false = + - * / 1.2 () || && ! == !=";
    std::istringstream input(text);

    expected.emplace_back(Sawoca::NAME);
    expected.emplace_back(Sawoca::VALUE);
    expected.emplace_back(Sawoca::VALUE);
    expected.emplace_back(Sawoca::ASSIGN);
    expected.emplace_back(Sawoca::PLUS);
    expected.emplace_back(Sawoca::MINUS);
    expected.emplace_back(Sawoca::MUL);
    expected.emplace_back(Sawoca::DIV);
    expected.emplace_back(Sawoca::VALUE);
    expected.emplace_back(Sawoca::LP);
    expected.emplace_back(Sawoca::RP);
    expected.emplace_back(Sawoca::L_OR);
    expected.emplace_back(Sawoca::L_AND);
    expected.emplace_back(Sawoca::L_NOT);
    expected.emplace_back(Sawoca::EQ);
    expected.emplace_back(Sawoca::NEQ);
    expected.emplace_back(Sawoca::END);

    Sawoca::Lexer lexer = Sawoca::Lexer(table, input);
    std::vector<Language::Tokens::TokenI*> result = lexer.lex();
    std::vector<Sawoca::Token_Type> result_types;
    std::transform(result.begin(), result.end(), std::back_inserter(result_types),
        [](const Language::Tokens::TokenI* tok){
            const Sawoca::Token* stok = dynamic_cast<const Sawoca::Token*>(tok);
            BOOST_CHECK_NE(stok, nullptr);
            return stok->get_type();
        }
    );

    BOOST_CHECK_EQUAL_COLLECTIONS(
        result_types.begin(), result_types.end(),
        expected.begin(), expected.end()
    );

    for(Language::Tokens::TokenI* tok : result)
        delete tok;
}