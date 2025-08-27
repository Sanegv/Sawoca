CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BOOST_FLAGS = -lboost_unit_test_framework

ROOT_DIR = ../../..
BUILD_DIR = $(ROOT_DIR)/build
TEST_BUILD_DIR = $(BUILD_DIR)/tests/lexer
IMPLEM_LEXER_DIR = $(ROOT_DIR)/implem/lexer
IMPLEM_TOKENS_DIR = $(ROOT_DIR)/implem/tokens
IMPLEM_VALUES_DIR = $(ROOT_DIR)/implem/values
LEXER_HEADERS_DIR = $(IMPLEM_LEXER_DIR)/headers
TOKENS_HEADERS_DIR = $(IMPLEM_TOKENS_DIR)/headers
VALUES_HEADERS_DIR = $(IMPLEM_VALUES_DIR)/headers
INTERFACES_DIR = $(ROOT_DIR)/interfaces

TEST_SRC = test_lexer.cpp
TEST_EXEC = $(TEST_BUILD_DIR)/test_lexer

LEXER_OBJECTS = $(BUILD_DIR)/Lexer.o
TOKEN_OBJECTS = $(BUILD_DIR)/AssignToken.o $(BUILD_DIR)/EndToken.o $(BUILD_DIR)/LeftParToken.o $(BUILD_DIR)/NameToken.o $(BUILD_DIR)/NumberToken.o $(BUILD_DIR)/OperatorToken.o $(BUILD_DIR)/PrintToken.o $(BUILD_DIR)/RightParToken.o
VALUE_OBJECTS = $(BUILD_DIR)/Double.o $(BUILD_DIR)/Bool.o

INCLUDES = -I$(LEXER_HEADERS_DIR) -I$(TOKENS_HEADERS_DIR) -I$(VALUES_HEADERS_DIR) -I$(INTERFACES_DIR)

all: run_tests

build_objects:
	$(MAKE) -C $(IMPLEM_LEXER_DIR)
	$(MAKE) -C $(IMPLEM_TOKENS_DIR)
	$(MAKE) -C $(IMPLEM_VALUES_DIR)

$(TEST_EXEC): build_objects $(TEST_SRC)
	mkdir -p $(TEST_BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_SRC) $(LEXER_OBJECTS) $(TOKEN_OBJECTS) $(VALUE_OBJECTS) $(BOOST_FLAGS) -o $(TEST_EXEC)

run_tests: $(TEST_EXEC)
	$(TEST_EXEC)

clean:
	rm -rf $(TEST_BUILD_DIR)

clean_all: clean
	$(MAKE) -C $(IMPLEM_LEXER_DIR) clean
	$(MAKE) -C $(IMPLEM_TOKENS_DIR) clean
	$(MAKE) -C $(IMPLEM_VALUES_DIR) clean

.PHONY: all build_objects run_tests clean clean_all