#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <cmath>
#include <fstream> 
#include <string>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "BLC/battery.hpp"
#include "BLC/light.hpp"
#include "servo.hpp"


extern "C" {
#include <pigpio.h>
}

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

float raspberryPiCPUTemperature();

int main(int argc, char* argv[]){

    //Initialize gpio library
    if (gpioInitialise() < 0) {
        std::cout << "Failed to initialise PIGPIO" << endl;
        return 1;
    }
    std::cout << "PIGPIO Initialized" << endl;
    
    //Initialize servo
    int servoHandle = initServo();
    
    //Initialize serial connection to BLC
    char deviceName[] = "/dev/ttyS0";
    int BLC_Handle = serOpen(deviceName, 9600, 0);
    if(BLC_Handle == PI_NO_HANDLE || BLC_Handle == PI_SER_OPEN_FAILED){
        return SER_OPEN_FAILED;
    }

<<<<<<< HEAD
    //Initialize connection socket
    int port = 1242;
    sockaddr_in servAddr;
    bzero((char*)&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(port);
 
    int serverSd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSd < 0)
    {
        cerr << "Error establishing the server socket" << endl;
        exit(0);
    }
    //bind the socket to its local address
    int bindStatus = bind(serverSd, (struct sockaddr*) &servAddr, 
        sizeof(servAddr));
    if(bindStatus < 0)
    {
        cerr << "Error binding socket to local address" << endl;
        exit(0);
    }
    cout << "Waiting for a client to connect..." << endl;
    //listen for up to 5 requests at a time
    listen(serverSd, 5);
    //receive a request from client using accept
    //we need a new address to connect with the client
    sockaddr_in newSockAddr;
    socklen_t newSockAddrSize = sizeof(newSockAddr);
    //accept, create a new socket descriptor to 
    //handle the new connection with client
    int newSd = accept(serverSd, (sockaddr *)&newSockAddr, &newSockAddrSize);
    if(newSd < 0)
    {
        cerr << "Error accepting request from client!" << endl;
        exit(1);
    }
    cout << "Connected with client!" << endl;

    lightDemo(BLC_Handle);

=======
    /*
    setHeadLight(BLC_Handle, 1); 
    setTurnSignalLight(BLC_Handle,1);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(BLC_Handle,2);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(BLC_Handle,3);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(BLC_Handle,0);
    setHeadLight(BLC_Handle, 0);
    setReverseLight(BLC_Handle, 1);
    sleep_for(milliseconds(1000));
    setReverseLight(BLC_Handle, 0);*/
    setTurnSignalLight(BLC_Handle,1);
>>>>>>> master
    serClose(BLC_Handle);

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

void lightDemo(int BLC_Handle){
    setHeadLight(BLC_Handle, 1); 
    setTurnSignalLight(BLC_Handle,1);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(BLC_Handle,2);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(BLC_Handle,3);
    sleep_for(milliseconds(1000));
    setTurnSignalLight(BLC_Handle,0);
    setHeadLight(BLC_Handle, 0);
    setReverseLight(BLC_Handle, 1);
    sleep_for(milliseconds(1000));
    setReverseLight(BLC_Handle, 0);
}
