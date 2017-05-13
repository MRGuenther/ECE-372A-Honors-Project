#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#define SET_BIT_1 |=
#define SET_BIT_0 &= ~

// #define SEG_G1(val) PORTF SET_BIT_##val (1<<PORTF3)
// #define SEG_A1(val) PORTF SET_BIT_##val (1<<PORTF4)
// #define SEG_B1(val) PORTF SET_BIT_##val (1<<PORTF5)
// #define SEG_E1(val) PORTF SET_BIT_##val (1<<PORTF6)
// #define SEG_D1(val) PORTF SET_BIT_##val (1<<PORTF7)
// #define SEG_C1(val) PORTK SET_BIT_##val (1<<PORTK0)
//
// #define SEG_G2(val) PORTK SET_BIT_##val (1<<PORTK1)
// #define SEG_F2(val) PORTK SET_BIT_##val (1<<PORTK2)
// #define SEG_A2(val) PORTK SET_BIT_##val (1<<PORTK3)
// #define SEG_B2(val) PORTK SET_BIT_##val (1<<PORTK4)
// #define SEG_E2(val) PORTK SET_BIT_##val (1<<PORTK5)
// #define SEG_D2(val) PORTK SET_BIT_##val (1<<PORTK6)
// #define SEG_C2(val) PORTK SET_BIT_##val (1<<PORTK7)
//
// // c1 --> a2 --> d1 --> f2 --> e1 --> g2 --> b2 --> c1

#define SEG_G1(val) PORTF SET_BIT_##val (1<<PORTF3) // Top left wire
#define SEG_A1(val) PORTF SET_BIT_##val (1<<PORTF4) // . * . . . . .
#define SEG_B1(val) PORTF SET_BIT_##val (1<<PORTF5) // . . * . . . .
#define SEG_G2(val) PORTF SET_BIT_##val (1<<PORTF6) // . . . * . . .
#define SEG_F2(val) PORTF SET_BIT_##val (1<<PORTF7) // . . . . * . .
#define SEG_A2(val) PORTK SET_BIT_##val (1<<PORTK0) // . . . . . * .
#define SEG_B2(val) PORTK SET_BIT_##val (1<<PORTK1) // Top right wire

#define SEG_E1(val) PORTK SET_BIT_##val (1<<PORTK2) // Bottom left wire
#define SEG_D1(val) PORTK SET_BIT_##val (1<<PORTK3) // . * . . . .
#define SEG_C1(val) PORTK SET_BIT_##val (1<<PORTK4) // . . * . . .
#define SEG_E2(val) PORTK SET_BIT_##val (1<<PORTK5) // . . . * . .
#define SEG_D2(val) PORTK SET_BIT_##val (1<<PORTK6) // . . . . * .
#define SEG_C2(val) PORTK SET_BIT_##val (1<<PORTK7) // Bottom right wire

//  Wire layout (* indicates increased brightness)
//  g1*  a1   b1   g2*  f2*  a2*  b2*
//  e1*  d1*  c1   e2   d2   c2

void initSevenSegment();
void dispNum(int num);

#endif // SEVENSEGMENT_H
