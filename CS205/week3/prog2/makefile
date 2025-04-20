TAR_FILE = ${LOGNAME}_Activity02.tar.gz
CFLAGS = -g3 -O0 -Wall 
LDFLAGS =



all: 1-4 1-8 1-13 





1-4: 1-4.o 
	gcc $(CLFAGS) 1-4.o -o 1-4

1-8: 1-8.o 
	gcc $(CLFAGS) 1-8.o -o 1-8

1-13: 1-13.o
	gcc $(CLFAGS) 1-13.o -o 1-13 -lm
	


1-4.o: 1-4.c
	gcc $(CFLAGS) -c 1-4.c

1-8.o: 1-8.c
	gcc $(CFLAGS) -c 1-8.c

1-13.o: 1-13.c
	gcc $(CFLAGS) -c 1-13.c


clean:
	rm -f *.o 1-4 1-8 1-13 *~ \#*

tar:
	rm -f $(TAR_FILE) 
	tar cvfa $(TAR_FILE) *.[ch] makefile
	tar tvfa $(TAR_FILE) 
