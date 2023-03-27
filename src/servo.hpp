#ifndef _SERVO
#define _SERVO
#define SERVO_PIN 12

#define PWN_SERVO_FREQUENCY 50

int initServo();
int setServoAngle(double angle);

#endif