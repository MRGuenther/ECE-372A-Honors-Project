// Author:         Garrett Vanhoy
// Net ID:         gvanhoy
// Date:           16 February 2017
// Assignment:     Lab 2
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//

#define DEBUG_ON 0 // Set to 1 to enable debug lines, 0 to disable.
//#define DEBUG_CODE if(DEBUG_ON)
#if DEBUG_ON
	#define DEBUG_CODE(code) do{ code } while(0);
#else
	#define DEBUG_CODE(code) // do nothing
#endif

#include <Arduino.h>
#include <avr/io.h>
#include "pwm.h"
#include "switch.h"
#include "led.h"
#include "rotEnc.h"
#include "sevenSegment.h"

#define SWITCH_PORT B
#define SWITCH_BIT 2

#define SET_PWM(A_or_B,pwm,motorDirState) \
	if((motorDirState) == forwardActive){ \
		setPWMfwd##A_or_B(pwm); \
	} else if((motorDirState) == reverseActive){ \
		setPWMrev##A_or_B(pwm); \
	} else { \
		zeroPWM##A_or_B(); \
	}

#define MAX_PWM(A_or_B,motorDirState) \
	if((motorDirState) == forwardActive){ \
		maxPWMfwd##A_or_B(); \
	} else if((motorDirState) == reverseActive){ \
		maxPWMrev##A_or_B(); \
	} else { \
		zeroPWM##A_or_B(); \
	}

typedef enum rotState_enum{
	lowAngPos,
	highAngPos
} rotState;

typedef enum dirState_enum{
	reverseIdle,
	forwardActive,
	forwardIdle,
	reverseActive
} dirState;

typedef struct stateType_struct{
	rotState rot;
	dirState dir;
} stateType;

volatile stateType state = {
	.rot = lowAngPos,
	.dir = forwardIdle
};

volatile stateType stateISR = {
	.rot = lowAngPos,
	.dir = forwardIdle
};

volatile int rotaryEncoderPos_ISR = HALF_ROTATION;
volatile bool rotSignalA = true; // Input A from rotary encoder.
volatile bool rotSignalB = true; // Input B from rotary encoder.

volatile bool stateChangeExpressed	= false;
volatile bool stateChangeISR_dir	= false;
volatile bool rotChangeExpressed	= false;

int main(){

	DEBUG_CODE(
		Serial.begin(9600);
	);

	// initialize here
	sei();
	//initADC0();
	initRotaryEncoder();
	initPWM();
	initSwitchPB2();
	initLED();
	initSevenSegment();

	int rotaryEncoderPos = 0;	// Angular position of rotary encoder.

	while(1){

		if(!rotChangeExpressed){
			if(rotaryEncoderPos_ISR > rotaryEncoderPos){
				rotaryEncoderPos++;
			} else if(rotaryEncoderPos_ISR < rotaryEncoderPos){
				rotaryEncoderPos--;
			}
			rotaryEncoderPos_ISR = rotaryEncoderPos;

			dispNum(rotaryEncoderPos);
			// SEG_A1(0); // works
			// SEG_B1(0); // works
			// SEG_C1(0); // affects a2
			// SEG_D1(0); // affects f2
			// SEG_E1(0); // affects g2
			// SEG_G1(0); // works
			// SEG_A2(0); // affects d1
			// SEG_B2(0); // affects c1
			// SEG_C2(1); // works
			// SEG_D2(0); // works
			// SEG_E2(0); // works
			// SEG_F2(0); // affects e1
			// SEG_G2(0); // affects b2

			// a1 <-> a1
			// b1 <-> b1
			// g1 <-> g1
			// c2 <-> c2
			// d2 <-> d2
			// c1 --> a2 --> d1 --> f2 --> e1 --> g2 --> b2 --> c1
			// e2 --> []

			rotChangeExpressed = true;
		}
		if(rotaryEncoderPos < HALF_ROTATION){
			state.rot = lowAngPos;
		} else {
			state.rot = highAngPos;
		}
		state.dir = stateISR.dir;

		DEBUG_CODE(
			Serial.print(state.rot);
			Serial.print(" ");
			Serial.print(state.dir);
			Serial.print(" ");
			Serial.print(rotaryEncoderPos);
			Serial.print(" ");
			Serial.print(OCR1AL);
			Serial.print(" ");
			Serial.print(OCR3AL);
			Serial.print(" ");
			Serial.print(OCR1BL);
			Serial.print(" ");
			Serial.println(OCR3BL);
		);

		switch(state.rot){
			case lowAngPos:
				MAX_PWM(A,						state.dir);
				SET_PWM(B,	rotaryEncoderPos,	state.dir);
				if(state.dir == reverseActive)	turnOnLED();
				else							turnOffLED();
				stateChangeExpressed = true;
				break;
			case highAngPos:
				SET_PWM(A,	rotaryEncoderPos,	state.dir);
				MAX_PWM(B,						state.dir);
				if(state.dir == reverseActive)	turnOnLED();
				else							turnOffLED();
				stateChangeExpressed = true;
				break;
			default:
				break;
		}
	}
	return 0;
}

// ISR for button pin-change interrupts
ISR(PCINT0_vect){
	if( !BUTTON_IS_DOWN(SWITCH_PORT,SWITCH_BIT) && stateChangeExpressed ){
		switch(state.dir){
			case forwardIdle:
				stateISR.dir = forwardActive;
				break;
			case forwardActive:
				stateISR.dir = reverseIdle;
				break;
			case reverseIdle:
				stateISR.dir = reverseActive;
				break;
			case reverseActive:
				stateISR.dir = forwardIdle;
				break;
			default:
				stateISR.dir = state.dir;
				break;
		}
		stateChangeExpressed = false;
		stateChangeISR_dir = true;
		//_delay_ms(50); // Are we sure we want this? It might desync the button with its FSM state.
	}
}

// ISR for rotary-encoder pin-change interrupts
ISR(PCINT1_vect){
	if(rotChangeExpressed){
		// Update angular position of rotary encoder.
		rotaryEncoderPos_ISR += deltaAngle((bool*)&rotSignalA, (bool*)&rotSignalB);
		if(rotaryEncoderPos_ISR > ROTARY_MAX) rotaryEncoderPos_ISR = ROTARY_MAX;
		else if(rotaryEncoderPos_ISR < 0) rotaryEncoderPos_ISR = 0;
		rotChangeExpressed = false;
	}
}
