# Module: tokens
CXX := g++
CXXFLAGS := -std=c++17 -g -Wall -Wextra -I../../interfaces/tokens -I../../interfaces/values -I../../interfaces

SRC_DIR := sources
HDR_DIR := headers
OBJ_DIR := ../../build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

TARGET := $(OBJ_DIR)/tokens.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -r -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_DIR)/%.h
	$(CXX) $(CXXFLAGS) -I$(HDR_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
