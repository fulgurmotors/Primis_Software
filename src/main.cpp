#include<iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <cmath>
#include <fstream> 

#include "main.hpp"
#include "BLC/battery.hpp"
#include "servo.hpp"
extern "C" {
#include <pigpio.h>
}

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

float raspberryPiCPUTemperature();

int main(int argc, char* argv[]){

    if (initServo() <0) {
        cout << "Failed to initialise servo" << endl;
        return 1;
    }

    if (gpioInitialise() < 0) {
        cout << "Failed to initialise PIGPIO" << endl;
        return 1;
    }

    char deviceName[] = "dev/usb/hiddev0";

    //Initialize gpio library

    //int a = batteryPercentage(deviceName);

    cout << raspberryPiCPUTemperature << endl;

    /*
    while(true){
        gpioPWM(12,0);
        sleep_for(milliseconds(10000));
        
        gpioPWM(12,255);
        sleep_for(milliseconds(10000));
    }
    */
    return 0;
}



float raspberryPiCPUTemperature(){
    string fileName = "/sys/class/thermal/thermal_zone0/temp";
    std::ifstream piCpuTempFile;
    float piCpuTemp = 0.0;
    std::stringstream buffer;
    piCpuTempFile.open(fileName);
    buffer << piCpuTempFile.rdbuf();
    piCpuTempFile.close();

    piCpuTemp = stof(buffer.str()); // convert string to float
    piCpuTemp = piCpuTemp / 1000; // convert float value to degree
    piCpuTemp = roundf(piCpuTemp * 100) / 100; // round decimal to nearest

    return piCpuTemp;
}

void fanControle(){

}
