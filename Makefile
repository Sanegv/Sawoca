CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinterfaces -Iinterfaces/lexer -Iinterfaces/parser -Iinterfaces/tokens -Iinterfaces/values

OBJ_DIR := build
MODULES := implem/values implem/tokens implem/lexer implem/parser
MODULE_OBJS := $(OBJ_DIR)/values.o $(OBJ_DIR)/tokens.o $(OBJ_DIR)/lexer.o $(OBJ_DIR)/parser.o
MAIN_OBJ := $(OBJ_DIR)/main.o
TARGET := $(OBJ_DIR)/sawoca

all: $(TARGET)

$(TARGET): $(MODULE_OBJS) $(MAIN_OBJ)
	$(CXX) -o $@ $^

$(MAIN_OBJ): sources/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Appel récursif des Makefiles de modules
$(OBJ_DIR)/values.o:
	$(MAKE) -C implem/values

$(OBJ_DIR)/tokens.o:
	$(MAKE) -C implem/tokens

$(OBJ_DIR)/lexer.o:
	$(MAKE) -C implem/lexer

$(OBJ_DIR)/parser.o:
	$(MAKE) -C implem/parser

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	for d in $(MODULES); do $(MAKE) -C $$d clean; done
