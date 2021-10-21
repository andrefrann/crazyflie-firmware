#include "attitude.estimator.h"
#include "crazyflie.h"

float p_bias;

AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL)
{
    float phi = 0;
    float phi_g = 0;
    float theta = 0;
    float psi = 0;
    float p = 0;
    float r = 0;
    float s = 0;
}

void AttitudeEstimator::init()
{
    imu.init();
    for(int i = 0; i<500; i++)
    {
        imu.read();
        float sum_bias =+ imu.gx;
        wait(delta_t);
        if (i == 499)
        {
            p_bias = sum_bias/500;
        }

    }
}

void AttitudeEstimator::estimate()
{
    imu.read();
    // float phi_a = atan2(-imu.ay,imu.az);
    // phi = (1-alpha)*phi + alpha*phi_a;
    // phi = phi_a;
    p = imu.gx - p_bias;
    phi_g = p*delta_t + phi_g; 
    phi = phi_g;


}
