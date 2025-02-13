CC=gcc  -Wall -Werror -Wextra
LDFLAGS=
SOURCES=main.c tree_d.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=tree

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -c $@