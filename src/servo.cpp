#include "servo.hpp"
#include "main.hpp"


#include <cstdlib>
extern "C" {
#include <pigpio.h>
}

using namespace std;

int initServo(){

    #ifdef DEBUG
        cout << "initiated Servo" << endl;
        return 0;
    #endif

    #ifndef DEBUG

    //Sets the PWN Frequency onthe servo pin to the defined frequency 
    if(gpioSetPWMfrequency(SERVO_PIN, PWN_SERVO_FREQUENCY) == PI_BAD_USER_GPIO) return -1;

    //Sets the servo position to center
    int pwm = gpioPWM(SERVO_PIN, gpioGetPWMrange(SERVO_PIN)/2);

    if(pwm == PI_BAD_USER_GPIO || pwm == PI_BAD_DUTYCYCLE) return -1;

    #endif
}

int setServoAngle(double angle){

    #ifdef DEBUG
        cout << "set Servo to " << angle << endl;
        return 0;
    #endif

    #ifndef DEBUG

    unsigned int pulse = (unsigned int) angle/180 * 255;

    gpioPWM(SERVO_PIN, pulse);

    return 0;

    #endif
}