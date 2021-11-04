#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

class AttitudeEstimator
{
    public:
        AttitudeEstimator();
        void init();
        void estimate();
        float phi, theta, psi;
        float p, q, r;
    
    private:
        MPU9250 imu;
        float p_bias, q_bias, r_bias;
};

#endif