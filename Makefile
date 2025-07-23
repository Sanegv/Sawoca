FLAGS= -Wall -Wextra -g
CC= g++
TARGET= calc
SRCS= main.cpp

all: $(SRCS)
	$(CC) $(FLAGS) -o $(TARGET) $(SRCS)
 
doc: Doxyfile
	doxygen Doxyfile

clean:
	$(RM) $(TARGET) *.o *.~	
