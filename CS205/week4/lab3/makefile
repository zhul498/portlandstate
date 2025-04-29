TAR_FILE = ${LOGNAME}_Lab2.tar.gz
CFLAGS = -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wextra -Werror -Wpedantic

all: float-2-hex hex-2-float

hex-2-float: hex-2-float.o
	gcc $(CFLAGS) hex-2-float.o -o hex-2-float -lm


float-2-hex: float-2-hex.o
	gcc $(CFLAGS) float-2-hex.o -o float-2-hex




hex-2-float.o: hex-2-float.c
	gcc $(CFLAGS) -c hex-2-float.c


float-2-hex.o: float-2-hex.c
	gcc $(CFLAGS) -c float-2-hex.c


clean:
	rm -f *.log *.txt *.out *.o *.err hex-2-float float-2-hex *~ \#*

tar: clean
	rm -f $(TAR_FILE)
	tar cvfa $(TAR_FILE) *.[ch] makefile
	tar tvfa $(TAR_FILE)

