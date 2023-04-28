#include <iostream>
#include <string>

#include "BLC/battery.hpp"
#include "BLC/light.hpp"
#include "servo.hpp"
#include "tools.hpp"
#include "network.hpp"


extern "C" {
#include <pigpio.h>
}

using namespace std;

float raspberryPiCPUTemperature();
void lightDemo(int BLC_Handle);

int main(){

    //Initialize gpio library
    if (gpioInitialise() < 0) {
        std::cout << "Failed to initialise PIGPIO" << endl;
        return 1;
    }
    std::cout << "PIGPIO Initialized" << endl;
    
    //Initialize servo
    //int servoHandle = initServo();

    //Initialize serial connection to BLC
    char deviceName[] = "/dev/ttyS0";
    int BLC_Handle = serOpen(deviceName, 9600, 0);
    if(BLC_Handle == PI_NO_HANDLE || BLC_Handle == PI_SER_OPEN_FAILED){
        return SER_OPEN_FAILED;
    }
    std::cout << "Serial connection to BLC initialized" << endl;


    connect();

    lightDemo(BLC_Handle);

    serClose(BLC_Handle);

    return 0;
}
