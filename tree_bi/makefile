CC=gcc  -Wall -Werror -Wextra
LDFLAGS= -lcheck -lsubunit -lrt -lpthread -lm
SOURCES=main.c tree_d.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tree

all: clear $(EXECUTABLE) test
	
$(EXECUTABLE): main.o tree_d.o
	$(CC) main.o tree_d.o -o tree
test: tree_d.o 
	$(CC) test.c tree_d.c -o test $(LDFLAGS)

tree_d.o:
	$(CC) -c tree_d.c 

main.o:
	$(CC) -c main.c


clear:
	rm -rf *.o 
	rm -rf test tree