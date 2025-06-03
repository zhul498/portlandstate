CC = gcc
DEFINES = 
DEBUG = -g3 -O0
WERROR = -Werror
CFLAGS = $(DEFINES) $(DEBUG) -Wall -Wextra $(WERROR)
LDFLAGS = 

PROG1 = sum-array-rows
PROG2 = sum-array-cols

PROGS = $(PROG1) $(PROG2)

all: $(PROGS)

$(PROG1): $(PROG1).o
	$(CC) $(LDFLAGS) -o $@ $^

$(PROG1).o: $(PROG1).c
	$(CC) $(CFLAGS) -c $<

$(PROG2): $(PROG2).o
	$(CC) $(LDFLAGS) -o $@ $^

$(PROG2).o: $(PROG2).c
	$(CC) $(CFLAGS) -c $<

clean cls:
	rm -f $(PROGS) *.o *~ \#*

TAR_FILE = ${LOGNAME}-$(PROG1).tar.gz
tar: clean
	rm -f $(TAR_FILE)
	tar cvaf $(TAR_FILE) *.[ch] [Mm]akefile
	tar tvaf $(TAR_FILE)
