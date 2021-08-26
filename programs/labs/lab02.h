#include "mbed.h"
#include "crazyflie.h"

PwmOut motor(MOTOR1);
float control_motor(float omega_r)
{
    float pwm_motor = a1*pow(omega_r,2) + a2*omega_r;
    return pwm_motor;
}

int main()
{
    while(true)
    {
        motor = control_motor(2600.0);
        wait(5);
        motor = 0;
        break;
    }
}