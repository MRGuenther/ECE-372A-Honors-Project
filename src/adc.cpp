/*
  Author: Alexander Osborn
  Net ID: acosborn
  Date: 2/24/2017
  Assignmetn: Lab2

  Description: Initialization of ADC

  Change Log: Feb 22, 2017 - AO - Initialization complete and working
              Feb 24, 2017 - AO - Added clearer comments
*/

#include "adc.h"
#include <avr/io.h>

/*
 * initialize ADC to accept one input ADC0 (Mega Pin A0) and convert to
 * digital relative to ADCC and ground in free-running mode.
 */
void initADC0()
{

  //set ADC to work with internal AVCC
  ADMUX |= (1 << REFS0);
  ADMUX &= ~(1 << REFS1);

  //MUX0:5 set to 0 for single ended ADC0 input (default setting)

  //ADTS2:0 set to 0 in ADCSRB register for free-running mode (default setting)

  //set clock prescaler to 128 to run the clock in the
  //documented frequency range of 50kHz to 200kHz
  ADCSRA |= (1 << ADPS2 | 1 << ADPS1 | ADPS0 << 1);

  //Disable digital input for ADC0 input to minimize noise
  DIDR0 |= (1 << ADC0D);

  //turn on ADC, enable auto-trigger, enable interrupt flag, and start conversion
  ADCSRA |= (1 << ADEN | 1 << ADSC | 1 << ADATE | 1 << ADIE);

}
