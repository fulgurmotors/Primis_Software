#include "battery.hpp"
#include <cstdlib>
extern "C" {
#include <pigpio.h>
}

using namespace std;

int batteryPercentage(char* deviceName){

    char request[] = "test";
    
    //Initialize gpio library
    if (gpioInitialise() < 0) return 1;

    //Connect to BLC
    int BLC_Serial = serOpen(deviceName, BAUDRATE, 0);

    if(BLC_Serial == PI_NO_HANDLE || BLC_Serial == PI_SER_OPEN_FAILED){
        return SER_OPEN_FAILED;
    }

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