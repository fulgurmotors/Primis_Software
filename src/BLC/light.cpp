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

void lightDemo(int handle){
    setHeadLight(handle, 1); 
    setTurnSignalLight(handle,1);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(handle,2);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(handle,3);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(handle,0);
    setHeadLight(handle, 0);
    setReverseLight(handle, 1);
    sleep_for(milliseconds(1000));
    setReverseLight(handle, 0);
}