#include "light.hpp"
extern "C" {
#include <pigpio.h>
}

void setTurnSignalLight(int handle, char state){ // 0 = off, 1 = gauche, 2 = droite, 3 = warning
    serWriteByte(handle, state + TURNSIGNAL);
}

void setBrakeLight(int handle, char state){ // 0 = off, 1 = on
    serWriteByte(handle, state + BRAKES);
}

void setReverseLight(int handle, char state){ // 0 = off, 1 = on
    serWriteByte(handle, state + REVERSE);
}

void setHeadLight(int handle, char state){ // 0 = off, 1 = on
    serWriteByte(handle, state + HEADLIGHT);
}