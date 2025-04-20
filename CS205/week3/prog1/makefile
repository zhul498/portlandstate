TAR_FILE = ${LOGNAME}_Activity01.tar.gz
CFLAGS = -g3 -O0 -Wall -Werror
LDFLAGS =


all: 1-3.o
	gcc $(CLFAGS) 1-3.o -o 1-3

1-3.o: 1-3.c
	gcc $(CFLAGS) -c 1-3.c
	

clean:
	rm -f *.o 1-3 *~ \#*

tar:
	rm -f $(TAR_FILE) 
	tar cvfa $(TAR_FILE) *.[ch] makefile
	tar tvfa $(TAR_FILE) 
