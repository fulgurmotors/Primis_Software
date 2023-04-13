#include <iostream>
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

    #ifndef DEBUG
    //Initialize gpio library
    if (gpioInitialise() < 0) {
        std::cout << "Failed to initialise PIGPIO" << endl;
        return 1;
    }
    #endif
    std::cout << "PIGPIO Initialized" << endl;
    
    int handle = initServo();
    
    int i = 0;
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

    //while(true){

    //    //Check Sensors
    //   //std::cout << "Battery : " << batteryPercentage(deviceName) << "%" << std::endl;

    //    std::cout << "CPU Temp : " << raspberryPiCPUTemperature() << "°C" << std::endl;

    //    string input;
    //    
    //    cout << "Entrer valeur" << endl;
    //    cin >> input;
    //    
    //    int inputint = std::stoi(input);

    //    //Receive Controls

    //    //Controls

    //    setServoAngle(inputint);
    //    i++;
    //    if (i == 180) i = 0;
    //    sleep_for(milliseconds(20));
    //}
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
