#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;

int main()
{
    mixer.actuate(0.7*m*g,0,0,0);
    wait(5);
    mixer.actuate(0, 0, 0, 0);

    while(true)
    {
    }
}