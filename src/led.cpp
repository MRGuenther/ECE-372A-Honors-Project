//----------------------------------------------------------------------//
// Author:         John Ure / Dr. Garrett Vanhoy
// Net ID:         johnlure
// Date:           23 Jan 2017
// Assignment:     Lab 0 part 1
//
// File: led.cpp
//
// Description: This file implements turnOnLED and initLED to control
//              the LEDs.
//
// Note: This file was provided in part from the git
//       repository git@uaecegit372a.com:ece372a/lab0-part1.git.  Liberal
//       changes have been made to the initLED() and turnOnLED(int led)
//       functions.
//
// Libraries: led.h, avr/io.h, util/delay.h
// Dependencies: N/A
//
// Changes: 01/23/17 - JLU - Initial Release of initLED(), turnOnLED(int led)
//----------------------------------------------------------------------//

//----------------------------------------------------------------------//
// Libraries:
//----------------------------------------------------------------------//
#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

 //----------------------------------------------------------------------//
 // Function: initLED()
 //
 // Description: Initializes pins B6, B5, and B4 to be in output mode using
 //              the DDR register and bit operations. Other bits in DDRB must
 //              not be affected by this assignment.
 //
 // Requirements:  White LED = RB4 (PIN 10)
 //                Red LED = RB5 (PIN 11)
 //                Yellow LED = RB6 (PIN 12)
 //
 // Libraries: led.h, avr/io.h
 // Dependencies: N/A
 // Changes: 01/23/17 - JLU - Initial Release
 //----------------------------------------------------------------------//
void initLED(){

  DDRH |= (1<<DDH4);    //DDB4 = bit 4 = PIN 7 per scehmatic  (White)

}

void turnOnLED(){
    PORTH |= (1<<PH4);   //White on
}
void turnOffLED(){
    PORTH &= ~(1<<PH4);   //White on
}
