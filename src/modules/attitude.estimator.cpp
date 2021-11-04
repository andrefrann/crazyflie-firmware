#include "attitude.estimator.h"

AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL)
{
    float phi = 0;
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

        p_bias += imu.gx/500.0;
        q_bias += imu.gy/500.0;
        r_bias += imu.gz/500.0;
        wait(delta_t);
    }

    wait(2);


}

void AttitudeEstimator::estimate()
{
    imu.read();
    float phi_a = atan2(-imu.ay,-imu.az);
    float theta_a = atan2(imu.ax, -((imu.az>0)-(imu.az<0))*sqrt(pow(imu.ay,2) + pow(imu.az,2)));


    // phi = (1-alpha)*phi + alpha*phi_a;    //passa-baixas
    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;
    float phi_g = phi + (p + sin(phi)*tan(theta)*q + cos(phi)*tan(theta)*r)*delta_t;
    float theta_g = theta + (cos(phi)*q - sin(phi)*r)*delta_t;
    float psi_g = psi + (sin(phi)*pow(cos(theta),-1)*q + cos(phi)*pow(cos(theta),-1)*r)*delta_t;


    // phi = (1-alpha)*phi_g;                      //passa-altas
    phi = (1-alpha)*phi_g + alpha*phi_a;
    theta = (1-alpha)*theta_g + alpha*theta_a;
    psi = psi_g;

}
