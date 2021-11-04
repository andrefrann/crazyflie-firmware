#include "mbed.h"
#include "crazyflie.h"

Mixer mixer;
AttitudeEstimator att_est;
AttitudeController att_cont;

Ticker tic;

bool flag;

void callback()
{
    flag = true;
}

int main()
{
    float f_t = m*g;
    float phi_r = 0.0;
    float theta_r = 0.0;
    float psi_r = 0.0;

    att_est.init();

    tic.attach(&callback, delta_t);
    mixer.arm();

    while(abs(att_est.phi) <= pi/4.0 && abs(att_est.theta) <=pi/4.0 && abs(att_est.p) <= 4.0*pi
        && abs(att_est.q) <= 4.0*pi && abs(att_est.r) <= 4.0*pi)
    {
        if (flag)
        {
            flag = false;
            att_est.estimate();
            att_cont.control(phi_r, theta_r, psi_r, att_est.phi, att_est.theta, att_est.psi,
                att_est.p, att_est.q, att_est.r);
            mixer.actuate(0.80*f_t, att_cont.tau_phi, att_cont.tau_theta, att_cont.tau_psi);

        }
    }

    mixer.disarm();
    while(true);
}