#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
// #include "crazyflie.h"
#include "drivers/mpu9250.h"

class AttitudeEstimator
{
    public:
        AttitudeEstimator();
        void init();
        void estimate();
        float phi, theta, psi, phi_g;
        float p, q, r;
    
    private:
    MPU9250 imu;
};

#endif