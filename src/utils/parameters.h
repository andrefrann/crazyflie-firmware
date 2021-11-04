#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m
const float a1 = 1.172e-7;  
const float a2 = 9.879e-14;
const float kl = 1.726e-8;  // N.s^2
const float kd = 2.7e-10;   // N.m.s^2
const float wc = 1;        // rad/s
const float delta_t = 1.0/500.0;// s
const float alpha = wc*delta_t/(1+wc*delta_t);

// Controlador de roll/pitch
const float ts_att = 0.6;
const float up_att = 0.4/100;
const float zeta_att = abs(log(up_att))/(sqrt(pow(log(up_att),2)+pow(pi,2)));
const float wn_att = 4/(zeta_att*ts_att);
const float kp_att = pow(wn_att,2);
const float kd_att = 2*zeta_att*wn_att;

// Controlador yaw
const float ts_2 = 0.6;
const float up_2 = 0.5/100;
const float zeta_2 = abs(log(up_2))/(sqrt(pow(log(up_2),2)+pow(pi,2)));
const float wn_2 = 4/(zeta_2*ts_2);
const float kp_2 = pow(wn_2,2);
const float kd_2 = 2*zeta_2*wn_2;
#endif