#ifndef _LIGHT
#define _LIGHT

#define TURNSIGNAL 12
#define BRAKES 4
#define REVERSE 8
#define HEADLIGHT 16

void setTurnSignalLight(int handle, char state);
void setBrakeLight(int handle, char state);
void setReverseLight(int handle, char state);
void setHeadLight(int handle, char state);


#endif