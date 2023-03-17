#ifndef _BATTERY
#define _BATTERY

#define BAUDRATE 9600
#define ANSWER_SIZE 8

#define SER_OPEN_FAILED -1

int batteryPercentage(char* deviceName);

#endif