CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BOOST_FLAGS = -lboost_unit_test_framework

ROOT_DIR = ../../..
BUILD_DIR = $(ROOT_DIR)/build
TEST_BUILD_DIR = $(BUILD_DIR)/tests/values
IMPLEM_VALUES_DIR = $(ROOT_DIR)/implem/values
HEADERS_DIR = $(IMPLEM_VALUES_DIR)/headers
INTERFACES_DIR = $(ROOT_DIR)/interfaces

TEST_SRC = test_Double.cpp
TEST_EXEC = $(TEST_BUILD_DIR)/test_values
OBJECTS = $(BUILD_DIR)/Double.o

INCLUDES = -I$(HEADERS_DIR) -I$(INTERFACES_DIR)

all: run_tests

build_objects:
	$(MAKE) -C $(IMPLEM_VALUES_DIR)

$(TEST_EXEC): build_objects $(TEST_SRC)
	mkdir -p $(TEST_BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_SRC) $(OBJECTS) $(BOOST_FLAGS) -o $(TEST_EXEC)

run_tests: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(TEST_BUILD_DIR)

clean_all: clean
	$(MAKE) -C $(IMPLEM_VALUES_DIR) clean

.PHONY: all build_objects run_tests clean clean_alls