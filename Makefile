CC=gcc
CFLAGS=-W -Wall -pthread 
GPIOFLAGS = -lpigpio -lrt
SRC=src/
EXEC=main
BUILDDIR = build/
BINDIR = bin/
BLC = BLC/

all: $(EXEC)

battery.o: $(SRC)$(BLC)battery.cpp
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp $(GPIOFLAGS)

main: $(SRC)main.cpp battery
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $(SRC)$@.cpp $(BUILDDIR)$? $(GPIOFLAGS)

.PHONY : clean

clean:
	rm $(BUILDDIR)*.o