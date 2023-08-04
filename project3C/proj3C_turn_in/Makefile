CC = gcc
CFLAGS = -W -Wall -c -g
OBJECTS = project3C.o project3C_hashtable.o
PROGRAMS = proj3C # run #tgz
# For run:
VALGRIND = valgrind --leak-check=full
EXECUABLE = ./project3C
# For tgz:
TAR = tar -zcvf
TARFILES = Makefile project3C.c project3C_hashtable.h project3C_hashtable.h wordlist1.txt wordlist2.txt
TGZNAME = proj3C.tgz

all: $(PROGRAMS)

proj3C: $(OBJECTS)
	$(CC) -W -Wall -o project3C $(OBJECTS)

project3C.o: project3C.c
	$(CC) $(CFLAGS) project3C.c

project3C_hashtable.o: project3C_hashtable.c
	$(CC) $(CFLAGS) project3C_hashtable.c

run: 
#	$(VALGRIND) 
	$(EXECUABLE)

#tgz: $(TARFILES)
#	$(TAR) $(TGZNAME) $(TARFILES)

clean:
	rm -f project3C $(OBJECTS) $(TGZNAME)
