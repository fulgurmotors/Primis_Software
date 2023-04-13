#include "light.hpp"
extern "C" {
#include <pigpio.h>
}

void setTurnSignalLight(char state){ // 0 = off, 1 = gauche, 2 = droite, 3 = warning
    serWriteByte(BLC_Handle, state + TURNSIGNAL);
}

void setBrakeLight(char state){ // 0 = off, 1 = on
    serWriteByte(BLC_Handle, state + BRAKES);
}

void setReverseLight(char state){ // 0 = off, 1 = on
    serWriteByte(BLC_Handle, state + REVERSE);
}

void setHeadLight(char state){ // 0 = off, 1 = on
    serWriteByte(BLC_Handle, state + HEADLIGHT);
}