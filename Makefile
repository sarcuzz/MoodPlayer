CC = gcc

CSAPP_INC = ../../../../include
CSAPP_SRC = ../../../../src

CFLAGS = -Wall -O2 -I $(CSAPP_INC) -I .
LDLIBS = -lpthread


all: $(CSAPP_SRC)/csapp.o $(PROGS) movie
$(PROGS): $(CSAPP_SRC)/csapp.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

#tiny/tiny: tiny/tiny.c
#(cd tiny; make)	

movie: movie.c $(CSAPP_SRC)/csapp.c
	$(CC) $(CFLAGS) -o movie movie.c $(CSAPP_SRC)/csapp.c 
echo: echoclient.c $(CSAPP_SRC)/csapp.c
	$(CC) $(CFLAGS) -o echoclient echoclient.c $(CSAPP_SRC)/csapp.c
# Programs that need more than one .o file


echoserveri: echoserveri.o echo.o

tinytarfile:
	(cd tiny; make clean)
	tar cvf - tiny >tiny.tar

clean:
	rm -f $(PROGS) *.o *~
	(cd tiny; make clean)
