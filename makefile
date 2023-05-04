CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: coursework

coursework: coursework.o
	$(CC) $(CFLAGS) coursework.o -o coursework $(SFML_LIBS)

coursework.o: coursework.cpp
	$(CC) $(CFLAGS) -c coursework/coursework.cpp -o coursework.o

clean:
	rm -rf coursework.o coursework
