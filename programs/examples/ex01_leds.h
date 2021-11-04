#include "mbed.h"
#include "crazyflie.h"

// Define red LED (right) as digital output object
DigitalOut led(LED_RED_L,false);
DigitalOut led2(LED_RED_R,false);
DigitalOut led3(LED_BLUE_L,false);
// DigitalOut led_green_l(LED_GREEN_L,false);
// DigitalOut led_green_r(LED_GREEN_R,false);


int i = 0;
// Main program
int main()
{
    // Blink LED every second

    while(i<10)
    {
        led = false;
        led2 = false;
        // led3 = true;

        // wait(1);
        // led = false;
        // led2 = true;
        // wait(1);
        // i++;
    }
    wait(3);
    // led3 = true;
}
