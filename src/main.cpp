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

    //char deviceName[] = "dev/usb/hiddev0";

    //int a = batteryPercentage(deviceName);
    int angle = 0;
    int monte = 1;

    while(true){
        if(monte) angle++;
        else angle--;
        if(angle == 255) monte = 0;
        if(angle == 0) monte = 1;    
        gpioPWM(12,angle);
        sleep_for(milliseconds(50));
    }
    return 0;
}
