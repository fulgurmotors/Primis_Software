CC=g++
CFLAGS=-W -Wall -pthread 
GPIOFLAGS = -lpigpio -lrt
SRC=src/
EXEC=main
BUILDDIR = build/
BINDIR = bin/
BLC = BLC/

all: $(EXEC)

main: battery servo light
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $(SRC)$@.cpp $(BUILDDIR)battery.o $(BUILDDIR)servo.o $(GPIOFLAGS)
 
battery:
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp $(GPIOFLAGS)

servo:
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC)$@.cpp $(GPIOFLAGS)

light:
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp $(GPIOFLAGS)

.PHONY : clean

clean:
	rm $(BUILDDIR)*.o
