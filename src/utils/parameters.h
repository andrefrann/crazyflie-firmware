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
const float wc = 15;        // rad/s
const float delta_t = 1.0/500.0;// s
const float alpha = wc*delta_t/(1+wc*delta_t);
#endif