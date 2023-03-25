#include "servo.hpp"
#include <cstdlib>
extern "C" {
#include <pigpio.h>
}

using namespace std;


int initServo(){

    //Sets the PWN Frequency onthe servo pin to the defined frequency 
    it(gpioSetPWMfrequency(SERVO_PIN, PWN_SERVO_FREQUENCY) == PI_BAD_USER_GPIO) return -1;

    //Sets the servo position to center
    int pwm = gpioPWM(gpioGetPWMrange(SERVO_PIN)/2);

    if(pwm == PI_BAD_USER_GPIO || pwm == PI_BAD_DUTYCYCLE) return -1;
}

int setServoAngle(double angle){

    unsigned int pulse = (unsigned int) angle/180 * 255;

    gpioPWM(SERVO_PIN, pulse);

    return 0;
}