CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BOOST_FLAGS = -lboost_unit_test_framework

ROOT_DIR = ../../..
BUILD_DIR = $(ROOT_DIR)/build
TEST_BUILD_DIR = $(BUILD_DIR)/tests/tokens
IMPLEM_TOKENS_DIR = $(ROOT_DIR)/implem/tokens
IMPLEM_VALUES_DIR = $(ROOT_DIR)/implem/values
HEADERS_DIR = $(IMPLEM_TOKENS_DIR)/headers
VALUES_HEADERS_DIR = $(IMPLEM_VALUES_DIR)/headers
INTERFACES_DIR = $(ROOT_DIR)/interfaces

TEST_SOURCES = test_AssignToken.cpp test_EndToken.cpp test_LeftParToken.cpp test_NameToken.cpp test_NumberToken.cpp test_OperatorToken.cpp test_PrintToken.cpp test_RightParToken.cpp
TEST_OBJECTS = $(patsubst %.cpp,$(TEST_BUILD_DIR)/%.o,$(TEST_SOURCES))
TEST_EXECUTABLES = $(patsubst %.cpp,$(TEST_BUILD_DIR)/%,$(TEST_SOURCES))

TOKEN_OBJECTS = $(BUILD_DIR)/AssignToken.o $(BUILD_DIR)/EndToken.o $(BUILD_DIR)/LeftParToken.o $(BUILD_DIR)/NameToken.o $(BUILD_DIR)/NumberToken.o $(BUILD_DIR)/OperatorToken.o $(BUILD_DIR)/PrintToken.o $(BUILD_DIR)/RightParToken.o
VALUE_OBJECTS = $(BUILD_DIR)/Double.o $(BUILD_DIR)/Bool.o

INCLUDES = -I$(HEADERS_DIR) -I$(VALUES_HEADERS_DIR) -I$(INTERFACES_DIR)

all: run_tests

build_objects:
	$(MAKE) -C $(IMPLEM_TOKENS_DIR)
	$(MAKE) -C $(IMPLEM_VALUES_DIR)

$(TEST_BUILD_DIR)/test_%: test_%.cpp build_objects
	mkdir -p $(TEST_BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< $(BUILD_DIR)/$*.o $(VALUE_OBJECTS) $(BOOST_FLAGS) -o $@

build_tests: $(TEST_EXECUTABLES)

run_tests: build_tests
	@for test in $(TEST_EXECUTABLES); do \
		$$test; \
	done

clean:
	rm -rf $(TEST_BUILD_DIR)

clean_all: clean
	$(MAKE) -C $(IMPLEM_TOKENS_DIR) clean
	$(MAKE) -C $(IMPLEM_VALUES_DIR) clean

.PHONY: all build_objects build_tests run_tests clean clean_all