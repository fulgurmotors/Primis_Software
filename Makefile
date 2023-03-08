CC=gcc
CFLAGS=-W -Wall
SRC=src/
EXEC=main
BUILDDIR = build/
BINDIR = bin/
BLC = BLC/

all: $(EXEC)

main: $(SRC)main.cpp battery
	$(CC) -o $(BINDIR)$@ $(SRC)$@.cpp
 
battery: $(SRC)$(BLC)battery.cpp
	$(CC) -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp

.PHONY : clean

clean:
	rm $(BUILDDIR)*.o