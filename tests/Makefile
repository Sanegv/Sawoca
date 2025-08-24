CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TESTS_IMPLEM_DIR = implem
VALUES_TEST_DIR = $(TESTS_IMPLEM_DIR)/values
TOKENS_TEST_DIR = $(TESTS_IMPLEM_DIR)/tokens
PARSER_TEST_DIR = $(TESTS_IMPLEM_DIR)/parser
LEXER_TEST_DIR = $(TESTS_IMPLEM_DIR)/lexer

BUILD_DIR = ../build
TEST_BUILD_DIR = $(BUILD_DIR)/tests

all: run_all_tests

run_all_tests: test_values test_tokens test_parser test_lexer

test_values:
	$(MAKE) -C $(VALUES_TEST_DIR)

test_tokens:
	$(MAKE) -C $(TOKENS_TEST_DIR)

test_parser:
	$(MAKE) -C $(PARSER_TEST_DIR)

test_lexer:
	$(MAKE) -C $(LEXER_TEST_DIR)

build_all: build_values build_tokens build_parser build_lexer

build_values:
	$(MAKE) -C $(VALUES_TEST_DIR) build_tests

build_tokens:
	$(MAKE) -C $(TOKENS_TEST_DIR) build_tests

build_parser:
	$(MAKE) -C $(PARSER_TEST_DIR) $(TEST_BUILD_DIR)/parser/test_parser

build_lexer:
	$(MAKE) -C $(LEXER_TEST_DIR) $(TEST_BUILD_DIR)/lexer/test_lexer

clean:
	$(MAKE) -C $(VALUES_TEST_DIR) clean
	$(MAKE) -C $(TOKENS_TEST_DIR) clean
	$(MAKE) -C $(PARSER_TEST_DIR) clean
	$(MAKE) -C $(LEXER_TEST_DIR) clean

clean_all:
	$(MAKE) -C $(VALUES_TEST_DIR) clean_all
	$(MAKE) -C $(TOKENS_TEST_DIR) clean_all
	$(MAKE) -C $(PARSER_TEST_DIR) clean_all
	$(MAKE) -C $(LEXER_TEST_DIR) clean_all

values:
	$(MAKE) test_values

tokens:
	$(MAKE) test_tokens

parser:
	$(MAKE) test_parser

lexer:
	$(MAKE) test_lexer

.PHONY: all run_all_tests test_values test_tokens test_parser test_lexer build_all build_values build_tokens build_parser build_lexer clean clean_all values tokens parser lexer