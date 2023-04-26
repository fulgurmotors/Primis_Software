#include "battery.hpp"

#include <cstdlib>
#include <iostream>

extern "C" {
#include <pigpio.h>
}

using namespace std;

int batteryPercentage(int handle){

    //Send request
    serWrite(BLC_Serial, request, sizeof(request));

    //Read answer
    while(serDataAvailable(BLC_Serial) < ANSWER_SIZE);
    char* answer = (char*)malloc(ANSWER_SIZE * sizeof(char));

    serRead(BLC_Serial, answer, ANSWER_SIZE);

    //Handle answer

    //TODO

    free(answer);
    serClose(BLC_Serial);
    gpioTerminate();
    return 0;
    
}