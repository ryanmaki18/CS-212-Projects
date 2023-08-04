CC = gcc
CFLAGS = -W -Wall -c -g
OBJECTS = project3B.o project3B_deque.o
PROGRAMS = proj3B run tgz
# For run:
EXECUABLE = ./project3B
INPUT = project3B_input.scr
OUTPUT = project3B_output.txt
# For tgz:
TAR = tar -zcvf
TARFILES = project3B.c project3B_deque.h project3B_deque.c project3B_input.scr project3B_output.txt Makefile

all: $(PROGRAMS)

proj3B: $(OBJECTS)
	$(CC) -W -Wall -o project3B $(OBJECTS)

project3B.o: project3B.c project3B_deque.h
	$(CC) $(CFLAGS) project3B.c

project3B_deque.o: project3B_deque.c project3B_deque.h
	$(CC) $(CFLAGS) project3B_deque.c

run: 
	$(EXECUABLE) < $(INPUT) > $(OUTPUT)

tgz: $(TARFILES)
	$(TAR) proj3B.tgz $(TARFILES)

clean:
	rm -f project3B $(OBJECTS)
