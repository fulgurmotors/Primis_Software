CC=gcc
CFLAGS=-W -Wall -pthread 
GPIOFLAGS = -lpigpio -lrt
SRC=src/
EXEC=main
BUILDDIR = build/
BINDIR = bin/
BLC = BLC/

all: $(EXEC)

main: $(SRC)main.cpp battery
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $(SRC)$@.cpp $(BUILDDIR)*.o $(GPIOFLAGS)
 
battery: $(SRC)$(BLC)battery.cpp
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp $(GPIOFLAGS)

.PHONY : clean

clean:
	rm $(BUILDDIR)*.o