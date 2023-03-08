#include "battery.hpp"

#include <string>
#include <pigpio.h>

using namespace std;

int main(void){

    char deviceName[] = "dev/tty/...";

    int a = batteryPercentage(deviceName);
}

int batteryPercentage(char[] deviceName){

    char request[] = "test";

    //Initialize gpio library
    if (gpioInitialise() < 0) return 1;

    //Connect to BLC
    int BLC_Serial = serOpen(deviceName, BAUDRATE);

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