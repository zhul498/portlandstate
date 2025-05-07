CC = gcc
AS = nasm

DEBUG = -g3 -O0
ARCH = -m32
PIE = -no-pie -fno-pie
STACK = -z noexecstack
CFLAGS = $(ARCH) $(PIE) $(DEBUG) -Wall
LDFLAGS = $(ARCH) $(PIE) $(STACK)
ASFLAGS = -g -f elf32 -F dwarf

PROG0 = template
PROG1 = expression
PROGS = $(PROG0) $(PROG1)

# These are some special make variables
# $@ is the target filename
# $^ is the name of all of the prerequisites
# $< is the name of the first dependancy
# there are others, but these are the ones we will be using


all: $(PROGS)

$(PROG0): $(PROG0).o
	$(CC) $(LDFLAGS) -o $@ $^

$(PROG0).o: $(PROG0).asm
	$(AS) $(ASFLAGS) -l $(PROG0).lst $<

$(PROG1): $(PROG1).o
	$(CC) $(LDFLAGS) -o $@ $^

$(PROG1).o: $(PROG1).asm
	$(AS) $(ASFLAGS) -l $(PROG1).lst $<

.PHONY: clean ci git get tar

clean:
	rm -f $(PROGS) *.s *.o *.lst *~ \#*

TAR_FILE = ${LOGNAME}_$(PROG1).tar.gz
tar: clean
	rm -f $(TAR_FILE)
	tar cvfa $(TAR_FILE) *.asm makefile
	tar tvfa $(TAR_FILE)

