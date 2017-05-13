#include "rotEnc.h"
#include "switch.h"
#include <avr/io.h>

int deltaAngle(bool* prevSigA, bool* prevSigB){
	bool sigA = (!(PINJ & (1<<PINJ1)));
	bool sigB = (!(PINJ & (1<<PINJ0)));
	if(*prevSigA && !(*prevSigA = sigA)){ // Not a typo
		return ((*prevSigB == sigB) ? *prevSigB : *prevSigB++) ? 1 : -1;
	} else {
		*prevSigA = sigA;
		*prevSigB = sigB;
		return 0;
	}
}

void initRotSignalA_PJ1(){
  PORTJ |= (1 << PORTJ1);
  DDRJ &= ~(1 << DDJ1);
  // enable pin-change interrupts
  PCICR |= (1 << PCIE1);
  // enable interrupts on PB3
  PCMSK1 |= (1 << PCINT10);
}

void initRotSignalB_PJ0(){
  PORTJ |= (1 << PORTJ0);
  DDRJ &= ~(1 << DDJ0);
  // enable pin-change interrupts
  PCICR |= (1 << PCIE1);
  // enable interrupts on PB1
  PCMSK1 |= (1 << PCINT9);
}

void initRotaryEncoder(){
	initRotSignalA_PJ1();
	initRotSignalB_PJ0();
}
