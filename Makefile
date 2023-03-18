CC=g++
CFLAGS=-W -Wall -pthread 
GPIOFLAGS = -lpigpio -lrt
SRC=src/
EXEC=main
BUILDDIR = build/
BINDIR = bin/
BLC = BLC/

all: $(EXEC)

main: $(SRC)main.cpp battery servo
	$(CC) $(CFLAGS) -o $(BINDIR)$@ $(SRC)$@.cpp $(BUILDDIR)battery.o $(BUILDDIR)servo.o $(GPIOFLAGS)
 
battery: $(SRC)$(BLC)battery.cpp
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC)$(BLC)$@.cpp $(GPIOFLAGS)

servo: $(SRC)servo.cpp
	$(CC) $(CFLAGS) -c -o $(BUILDDIR)$@.o $(SRC).cpp $(GPIOFLAGS)

.PHONY : clean

clean:
	rm $(BUILDDIR)*.o