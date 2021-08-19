#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led_blue(LED_BLUE_L, false);
DigitalOut led_red1(LED_RED_L, true);
DigitalOut led_red2(LED_RED_R, true);
DigitalOut led_green1(LED_GREEN_L, true);
DigitalOut led_green2(LED_GREEN_R, true);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);

int i = 0;
int k = 0;

// Main program
int main()
{
        
    // Blink blue LED indicating inicialization (5 seconds)
    wait(3);
    while(i<=5)
    {
        led_blue = !led_blue;
        i++;
        wait(0.5);
    }
    // Turn on red LEDs indicating motors are armed
    wait(0.5);
    led_red1 = false;
    led_red2 = false;
    wait(1);

    // Test all motors with different frequencies (to make different noises)
    motor1.period(1.0/400);
    motor2.period(1.0/600);
    motor3.period(1.0/800);
    motor4.period(1.0/1000);

    motor1 = 0.07;
    wait(0.5);
    motor2 = 0.07;
    wait(0.5);
    motor3 = 0.07;
    wait(0.5);
    motor4 = 0.07;
    wait(1.5);
    motor1 = 0;
    wait(0.5);
    motor2 = 0;
    wait(0.5);
    motor3 = 0;
    wait(0.5);
    motor4 = 0;
    wait(2);

    motor4 = 0.1;
    wait(0.5);
    motor4 = 0;
    wait(0.05);
    motor3 = 0.07;
    wait(0.5);
    motor3 = 0;
    wait(0.05);
    motor2 = 0.07;
    wait(0.5);
    motor2 = 0;
    wait(0.05);
    motor1 = 0.07;
    wait(0.5);
    motor1 = 0;
    wait(5);

    // Turn off red LEDs indicating motors are disarmed
    led_red1 = true;
    led_red2 = true;
    wait(1.5);
    // Blink green LEDs indicating end of program
    while(k<=5)
    {
        led_green1 = !led_green1;
        led_green2 = !led_green2;
        wait(0.2);
        k++;
    }
}
