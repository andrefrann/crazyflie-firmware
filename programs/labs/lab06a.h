#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

int main()
{
    wait(2);
    mixer.actuate(0.5*m*g,0,0,0);
    wait(5);
    mixer.actuate(0, 0, 0, 0);

    while(true)
    {
    }
}