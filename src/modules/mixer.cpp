#include "mixer.h"
#include "crazyflie.h"

DigitalOut led_red_l(LED_RED_L,true);
DigitalOut led_red_r(LED_RED_R,true);
DigitalOut led_blue_l(LED_BLUE_L,false);
DigitalOut led_green_l(LED_GREEN_L,true);
DigitalOut led_green_r(LED_GREEN_R,true);

bool armed = false;
// bool armed;

Mixer::Mixer(): motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4)
{
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);
}

void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    if (armed == true)
    {
        mixer(f_t, tau_phi, tau_theta, tau_psi);
        motor_1 = control_motor(omega_1);
        motor_2 = control_motor(omega_2);
        motor_3 = control_motor(omega_3);
        motor_4 = control_motor(omega_4);
    }
}

void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
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

float Mixer::control_motor(float omega)
{
    float pwm_motor = a1*pow(omega,2) + a2*omega;
    return pwm_motor;
}


int i = 0;
void Mixer::arm()
{
    while(i < 5)
    {
        led_red_l = true;
        led_red_r = true;
        led_green_l = true;
        led_green_r = true;
        wait(0.3);
        led_red_l = false;
        led_red_r = false;
        led_green_l = false;
        led_green_r = false;
        wait(0.3);
        i++;
    }
    wait(3);
    armed = true;
    led_green_l = true;
    led_green_r = true;
}


void Mixer::disarm()
{
    if(armed == true)
    {
        motor_1 = 0;
        motor_2 = 0;
        motor_3 = 0;
        motor_4 = 0;

        wait(3);
        armed = false;
        led_red_l = true;
        led_red_r = true;
        wait(0.15);
        i = 0;
        while(i<3)
        {
            led_green_l = false;
            led_green_r = false;
            wait(0.15);
            led_green_l = true;
            led_green_r = true;
            wait(0.15);
            i++;
        }
        led_green_l = true;
        led_green_r = true;
    }
}