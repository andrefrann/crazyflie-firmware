#include "mbed.h"
#include "crazyflie.h"

PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);

float omega_1;
float omega_2;
float omega_3;
float omega_4;

float control_motor(float omega)
{
    float pwm_motor = a1*pow(omega,2) + a2*omega;
    return pwm_motor;
}

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    float omega_1_2 = f_t/(4*kl) - tau_phi/(4*kl*l) - tau_theta/(4*kl*l) - tau_psi/(4*kd);
    float omega_2_2 = f_t/(4*kl) - tau_phi/(4*kl*l) + tau_theta/(4*kl*l) + tau_psi/(4*kd);
    float omega_3_2 = f_t/(4*kl) + tau_phi/(4*kl*l) + tau_theta/(4*kl*l) - tau_psi/(4*kd);
    float omega_4_2 = f_t/(4*kl) + tau_phi/(4*kl*l) - tau_theta/(4*kl*l) + tau_psi/(4*kd);

    if (omega_1_2 > 0)
    {
        omega_1 = sqrt(omega_1_2);
    }
    else
    {
        omega_1 = 0;
    }

    if (omega_2_2 > 0)
    {
        omega_2 = sqrt(omega_2_2);
    }
    else
    {
        omega_2 = 0;
    }

    if (omega_3_2 > 0)
    {
        omega_3 = sqrt(omega_3_2);
    }
    else
    {
        omega_3 = 0;
    }

    if (omega_4_2 > 0)
    {
        omega_4 = sqrt(omega_4_2);
    }
    else
    {
        omega_4 = 0;
    }

}

void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
}

int main()
{
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);
    actuate(0,0.005,0,0);
    wait(5);
    actuate(0,0,0,0);
    while(true)
    {
    }
}