#include "battery.hpp"

#include <cstdlib>
#include <iostream>

extern "C" {
#include <pigpio.h>
}

using namespace std;

int batteryPercentage(int handle){

    char * request = (char*)malloc(REQUEST_SIZE * sizeof(char));
    //Send request
    serWrite(handle, request, sizeof(request));

    //Read answer
    while(serDataAvailable(handle) < ANSWER_SIZE);
    char* answer = (char*)malloc(ANSWER_SIZE * sizeof(char));

    serRead(handle, answer, ANSWER_SIZE);

    //Handle answer

    //TODO

    free(answer);
    gpioTerminate();
    return 0;
    
}