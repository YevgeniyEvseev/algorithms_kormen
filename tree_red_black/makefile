CC=gcc  -Wall -Werror -Wextra
LDFLAGS= -lcheck -lsubunit -lrt -lpthread -lm
SOURCES=main.c rb_tree.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tree

all: clear $(EXECUTABLE)
	
$(EXECUTABLE): main.o rb_tree.o
	$(CC) main.o rb_tree.o -o tree
test: tree_d.o 
	$(CC) test.c rb_tree.c -o test $(LDFLAGS)

tree_d.o:
	$(CC) -c rb_tree.c 

main.o:
	$(CC) -c main.c


clear:
	rm -rf *.o 
	rm -rf test tree