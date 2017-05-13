#include "switch.h"
#include <avr/io.h>


void initSwitchPB2(){
  PORTB |= (1 << PORTB2);   //PIN 51
  DDRB &= ~(1 << DDB2);
  // enable pin-change interrupts
  PCICR |= (1 << PCIE0);
  // enable interrupts on PB2
  PCMSK0 |= (1 << PCINT2);
}
