CC=gcc
CFLAGS=-W -Wall -pthread -lpigpio -lrt
SRC=src/
EXEC=main
BUILDDIR = build/
BINDIR = bin/
BLC = BLC/

all: $(EXEC)

main: $(SRC)main.cpp battery
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $(SRC)$@.cpp
 
battery: $(SRC)$(BLC)battery.cpp
	$(CC) $(CFLAGS) -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp

.PHONY : clean

clean:
	rm $(BUILDDIR)*.o