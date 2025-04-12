TAR_FILE = ${LOGNAME}_strings-control.tar.gz

make tar:
	rm -f $(TAR_FILE) 
	tar cvfa $(TAR_FILE) *.[ch] makefile
	tar tvfa $(TAR_FILE) 
