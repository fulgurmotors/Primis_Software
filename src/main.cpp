#include<iostream>
#include <chrono>
#include <thread>

#include "main.hpp"
#include "BLC/battery.hpp"
extern "C" {
#include <pigpio.h>
}

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

int main(int argc, char* argv[]){


    if (gpioInitialise() < 0) return 1;

    char deviceName[] = "dev/ttyS0";


    int BLC_Handle = serOpen(deviceName, 9600, 0);


    char c = 1+4;
    serWriteByte(BLC_Handle, c);
    sleep_for(milliseconds(1000));

    c = 4;
    serWriteByte(BLC_Handle, c);
    sleep_for(milliseconds(1000));


    serClose(BLC_Handle);



    //int a = batteryPercentage(deviceName);

    while(true){
        gpioPWM(12,0);
        sleep_for(milliseconds(10000));
        
        gpioPWM(12,255);
        sleep_for(milliseconds(10000));
    }
    return 0;
}
