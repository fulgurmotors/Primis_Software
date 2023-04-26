#include "servo.hpp"

#include <iostream>
#include <cstdlib>

extern "C" {
#include <pigpio.h>
}

using namespace std;

int initServo(){

    //Sets the PWN Frequency onthe servo pin to the defined frequency 
    if(gpioSetPWMfrequency(SERVO_PIN, PWN_SERVO_FREQUENCY) == PI_BAD_USER_GPIO) return -1;
    gpioSetPWMrange(SERVO_PIN, (int) 1000000.0/PWN_SERVO_FREQUENCY);
    //Sets the servo position to center
    int pwm = gpioPWM(SERVO_PIN, gpioGetPWMrange(SERVO_PIN)/2);

    if(pwm == PI_BAD_USER_GPIO || pwm == PI_BAD_DUTYCYCLE) return -1;

    return pwm;
}

int setServoAngle(double angle){

    unsigned int pulse = (unsigned int) MIN_SERVO_DUTYCYCLE + (angle/ 180.0) * (MAX_SERVO_DUTYCYCLE - MIN_SERVO_DUTYCYCLE);
    cout << pulse << endl;
    gpioPWM(SERVO_PIN, (int)pulse);

    return 0;
}