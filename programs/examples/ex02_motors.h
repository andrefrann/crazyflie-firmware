#include "mbed.h"
#include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

int i = 0;
// Main program
int main()
{
    // Turn motor on (20% power) and off every second
    while(i<=10) 
    {
        int f1 = 450;
        int f2 = 600;
        int f3 = 750;
        int f4 = 950;
        motor.period(1.0/f4);
        motor2.period(1.0/f3);
        motor3.period(1.0/f2);
        motor4.period(1.0/f1);

        motor3 = 0.05;
        wait(0.1);
        motor3 = 0.0;
        wait(0.05);
        motor2 = 0.05;
        wait(0.1);
        motor2 = 0;
        wait(0);
        motor = 0.05;
        wait(0.1);
        motor = 0;
        wait(1);
        motor3 = 0.05;
        wait(0.1);
        motor3 = 0;
        wait(0);
        motor2 = 0.05;
        wait(0.08);
        motor2 = 0;
        wait(0.1);
        motor = 0.05;
        wait(0.1);
        motor = 0;
        wait(0.3);
        motor4 = 0.05;
        wait(0.1);
        motor4 = 0;

        wait(4);
        i++;
    }
}
