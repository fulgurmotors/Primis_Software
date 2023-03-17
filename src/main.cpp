#include<iostream>
#include "main.hpp"
#include "BLC/battery.hpp"


int main(int argc, char* argv[]){
    char* deviceName = "dev/tty/...";

    int a = batteryPercentage(deviceName);
}
