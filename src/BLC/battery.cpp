#include "battery.hpp"
#include <cstdlib>
extern "C" {
#include <pigpio.h>
}

using namespace std;

int batteryPercentage(char* deviceName){

    char* request = (char*)malloc(4 * sizeof(char));
    request[0] = 't';
    request[1] = 'e';
    request[2] = 's';
    request[3] = 't';

    //Initialize gpio library
    if (gpioInitialise() < 0) return 1;

    //Connect to BLC
    int BLC_Serial = serOpen(deviceName, BAUDRATE, 0);

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