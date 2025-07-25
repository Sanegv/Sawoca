FLAGS= -Wall -Wextra -g
CC= g++
TARGET= calc
SRCS= main.cpp lexer.cpp parser.cpp
HDRS= lexer.h parser.h

OBJS= $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS) $(HDRS)
	$(CC) $(FLAGS) -o $(TARGET) $(OBJS)

$(OBJS): $(HDRS) $(SRCS)
 
doc: Doxyfile
	doxygen Doxyfile

clean:
	$(RM) $(TARGET) *.o *.~	
