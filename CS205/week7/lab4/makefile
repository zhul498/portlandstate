TAR_FILE = ${LOGNAME}_Lab4.tar.gz
CFLAGS = -Wall -Wshadow -Wunreachable-code -Wredundant-decls -Wmissing-declarations -Wold-style-definition -Wmissing-prototypes -Wdeclaration-after-statement -Wextra -Werror -Wpedantic -Wno-return-local-addr -Wunsafe-loop-optimizations -Wuninitialized
FILE = vhex



all: $(FILE)

$(FILE): $(FILE).o
	gcc $(CFLAGS) $(FILE).o -o $(FILE) -lm

$(FILE).o: $(FILE).c
	gcc $(CFLAGS) -c $(FILE).c

clean cls:
	rm -f *.log *.txt *.out *.o *.err ./my_cat1 ./Ch02_09_Readelf ./argv $(FILE) *~ \#*

tar: clean
	rm -f $(TAR_FILE)
	tar cvfa $(TAR_FILE) *.[ch] makefile
	tar tvfa $(TAR_FILE)

