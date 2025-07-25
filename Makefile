FLAGS = -Wall -Wextra -g
CC = g++

SRC_DIR = sources
HDR_DIR = headers
BUILD_DIR = build

TARGET = $(BUILD_DIR)/swc

SRCS = $(addprefix $(SRC_DIR)/, main.cpp lexer.cpp parser.cpp)
HDRS = $(addprefix $(HDR_DIR)/, lexer.h parser.h)

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDRS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -I$(HDR_DIR) -c $< -o $@

doc: Doxyfile
	doxygen Doxyfile

run: all
	./$(TARGET)
clean:
	$(RM) $(TARGET) $(BUILD_DIR)/*.o *~
