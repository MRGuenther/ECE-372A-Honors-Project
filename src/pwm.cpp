// Author:
// Net ID:
// Date:
// Assignment:
//
// Description:
//----------------------------------------------------------------------//
#include "pwm.h"
#include <Arduino.h>


void initPWM(){

    //Set Timer 1 to use 8-bit fast PWM mode with output set low on OCR match
    TCCR1A |= (1 << WGM10 | 1 << COM1A1 | 1 << COM1B1);
    TCCR1A &= ~(1 << WGM11 | 1 << COM1A0 | 1 << COM1B0);

    //Set Timer 1 prescalar to 64
    TCCR1B |= (1 << WGM12 | 1 << CS10 | 1 << CS12);
    TCCR1B &= ~(1 << WGM13 | 1 << CS11);

    //Init duty cycles to 0%
    OCR1AL = 0;
    OCR1BL = 0;

    //Set DDR on pins 11 and 5
    DDRB |= (1 << DDB5);
    DDRE |= (1 << DDE3);

    //Set Timer 2 to use 8-bit fast PWM mode with output set low on OCR match
    TCCR3A |= (1 << WGM30 | 1 << COM3A1 | 1 << COM3B1);
    TCCR3A &= ~(1 << WGM31 | 1 << COM3A0 | 1 << COM3B0);

    //Set Timer 1 prescalar to 64
    TCCR3B |= (1 << WGM32 | 1 << CS30 | 1 << CS32);
    TCCR3B &= ~(1 << WGM33 | 1 << CS31);

    //Init duty cycles to 0%
    OCR3AL = 0;
    OCR3BL = 0;

    //Set DDR on pins 12 and 2
    DDRB |= (1 << DDB6);
    DDRE |= (1 << DDE4);
}

// void setPWMfwdA(double duty){ //PWMA on board 11
//     int boundCheck = (int)(duty * 255);
//     // Prevent overflow/underflow of OCR1AL
//     OCR1AL = (unsigned char)((boundCheck < 0) ? 0 : ((boundCheck > 255) ? 255 : boundCheck));
// }
//
// void setPWMfwdB(double duty){ //PWMB on board 12
//     int boundCheck = (int)(duty * 255);
//     // Prevent overflow/underflow of OCR1BL
//     OCR1BL = (unsigned char)((boundCheck < 0) ? 0 : ((boundCheck > 255) ? 255 : boundCheck));
// }
//
// void setPWMrevA(double duty){ //PWMA on board 5
//     int boundCheck = (int)(duty * 255);
//     // Prevent overflow/underflow of OCR3AL
//     OCR3AL = (unsigned char)((boundCheck < 0) ? 0 : ((boundCheck > 255) ? 255 : boundCheck));
// }
//
// void setPWMrevB(double duty){ //PWMB on board 2
//     int boundCheck = (int)(duty * 255);
//     // Prevent overflow/underflow of OCR3BL
//     OCR3BL = (unsigned char)((boundCheck < 0) ? 0 : ((boundCheck > 255) ? 255 : boundCheck));
// }

void setPWMfwdA(int angPos){ //PWMA on board 11
    OCR1AL = (unsigned char)(((ROT_HALF_MAX - angPos) % ROT_MIDPOINT) * PWM_DUTY_MAX / HALF_ROTATION);
	OCR3AL = 0;
	// Serial.print(angPos);
	// Serial.print(" ");
	// Serial.print((ROT_HALF_MAX - (angPos % HALF_ROTATION)));
	// Serial.print(" ");
	// Serial.println(OCR1AL);
}

void setPWMfwdB(int angPos){ //PWMB on board 12
    OCR1BL = (unsigned char)((angPos % HALF_ROTATION) * PWM_DUTY_MAX / ROT_HALF_MAX);
	OCR3BL = 0;
}

void setPWMrevA(int angPos){ //PWMA on board 5
	OCR1AL = 0;
    OCR3AL = (unsigned char)(((ROT_HALF_MAX - angPos) % ROT_MIDPOINT) * PWM_DUTY_MAX / HALF_ROTATION);
}

void setPWMrevB(int angPos){ //PWMB on board 2
	OCR1BL = 0;
    OCR3BL = (unsigned char)((angPos % HALF_ROTATION) * PWM_DUTY_MAX / ROT_HALF_MAX);
}

void zeroPWMA(){
	OCR1AL = 0;
	OCR3AL = 0;
}

void zeroPWMB(){
	OCR1BL = 0;
	OCR3BL = 0;
}

void maxPWMfwdA(){
	OCR1AL = 255;
	OCR3AL = 0;
}

void maxPWMfwdB(){
	OCR1BL = 255;
	OCR3BL = 0;
}

void maxPWMrevA(){
	OCR1AL = 0;
	OCR3AL = 255;
}

void maxPWMrevB(){
	OCR1BL = 0;
	OCR3BL = 255;
}
