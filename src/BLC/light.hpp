#ifndef _LIGHT
#define _LIGHT

#define TURNSIGNAL 12
#define BRAKES 4
#define REVERSE 8
#define HEADLIGHT 16

void setTurnSignalLight(char state);
void setBrakeLight(char state);
void setReverseLight(char state);
void setHeadLight(char state);


#endif