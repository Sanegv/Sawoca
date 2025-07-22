FLAGS= -Wall -Wextra -g
CC= g++
TARGET= calc

all: main.c
	$(CC) $(FLAGS) -o $(TARGET) main.c 

clean:
	$(RM) $(TARGET) *.o *.~	
