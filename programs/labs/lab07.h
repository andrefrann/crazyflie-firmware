#include "mbed.h"
#include "crazyflie.h"
#include "USBSerial.h"

USBSerial serial;


char command;

AttitudeEstimator att_est;

Ticker tic;

bool flag;

void callback()
{
    flag = true;
}

int main()
{
    att_est.init();
    tic.attach(&callback,delta_t);
    while(true)
    {
        if (flag)
        {
            flag = false;
            att_est.estimate();
        }
        // if (serial.readable())
        // {
        //     command = serial.getc();
        //     if (command == 'p')
        //     {
                serial.printf("%.10f,%f,%f\n", att_est.phi, att_est.theta, att_est.psi);
        //     }
        // }
    }
}