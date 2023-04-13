#ifndef _SERVO
#define _SERVO
#define SERVO_PIN 12

#define PWN_SERVO_FREQUENCY 330

#define MAX_SERVO_DUTYCYCLE 2500
#define MIN_SERVO_DUTYCYCLE 500

int initServo();
int setServoAngle(double angle);


#endif