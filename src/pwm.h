// Author:
// Net ID:
// Date:
// Assignment:
//
// Description:
//----------------------------------------------------------------------//

#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

#define ROTARY_RES		33
#define ROTARY_MAX		(ROTARY_RES - 1)
#define HALF_ROTATION	(ROTARY_RES / 2)
#define ROT_HALF_MAX	(HALF_ROTATION - 1)
#define ROT_MIDPOINT	(HALF_ROTATION + 1)
#define PWM_DUTY_MAX	255

void initPWM();

// void setPWMfwdA(double duty);
//
// void setPWMfwdB(double duty);
//
// void setPWMrevA(double duty);
//
// void setPWMrevB(double duty);

void setPWMfwdA(int angPos);

void setPWMfwdB(int angPos);

void setPWMrevA(int angPos);

void setPWMrevB(int angPos);

void zeroPWMA();

void zeroPWMB();

void maxPWMfwdA();

void maxPWMfwdB();

void maxPWMrevA();

void maxPWMrevB();


#endif
