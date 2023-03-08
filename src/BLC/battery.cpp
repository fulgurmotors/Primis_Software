#include "battery.hpp"

#include <string>
#include <pigpio.h>

using namespace std;

int main(void){

    std::string deviceName = "dev/tty/...";

    batteryPercentage(deviceName);
   
}

int batteryPercentage(string deviceName){

    string request = "test";

    //Initialize gpio library
    if (gpioInitialise() < 0) return 1;

    //Connect to BLC
    int BLC_Serial = serOpen(deviceName.c_str(), BAUDRATE);

    //Send request
    serWrite(BLC_Serial, request.c_str(), sizeof(request));

    //Read answer
    while(serDataAvailable < ANSWER_SIZE);
    char* answer = (char*)malloc(ANSWER_SIZE * sizeof(char));

    serRead(BLC_Serial, answer, ANSWER_SIZE);

    //Handle answer

    //TODO

    free(answer);
    serClose(BLC_Serial);
    gpioTerminate();
    return 0;

}