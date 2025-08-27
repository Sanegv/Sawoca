CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
BOOST_FLAGS = -lboost_unit_test_framework

ROOT_DIR = ../../..
BUILD_DIR = $(ROOT_DIR)/build
TEST_BUILD_DIR = $(BUILD_DIR)/tests/values
IMPLEM_VALUES_DIR = $(ROOT_DIR)/implem/values
HEADERS_DIR = $(IMPLEM_VALUES_DIR)/headers
INTERFACES_DIR = $(ROOT_DIR)/interfaces

TEST_SOURCES = test_Bool.cpp test_Double.cpp
TEST_EXECUTABLES = $(patsubst %.cpp,$(TEST_BUILD_DIR)/%,$(TEST_SOURCES))

VALUE_OBJECTS = $(BUILD_DIR)/Double.o $(BUILD_DIR)/Bool.o

INCLUDES = -I$(HEADERS_DIR) -I$(INTERFACES_DIR)

all: run_tests

build_objects:
	$(MAKE) -C $(IMPLEM_VALUES_DIR)

# --- Compilation des tests ---
$(TEST_BUILD_DIR)/test_%: test_%.cpp build_objects
	mkdir -p $(TEST_BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< $(VALUE_OBJECTS) $(BOOST_FLAGS) -o $@

build_tests: $(TEST_EXECUTABLES)

run_tests: build_tests
	@for test in $(TEST_EXECUTABLES); do \
		$$test; \
	done

clean:
	rm -rf $(TEST_BUILD_DIR)

clean_all: clean
	$(MAKE) -C $(IMPLEM_VALUES_DIR) clean

.PHONY: all build_objects build_tests run_tests clean clean_all
