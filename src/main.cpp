#include<iostream>
#include "main.hpp"
#include "BLC/battery.hpp"
extern "C" {
#include <pigpio.h>
}

using namespace std;

int main(int argc, char* argv[]){

    char deviceName[] = "dev/usb/hiddev0";

    int a = batteryPercentage(deviceName);

    return 0;
}
