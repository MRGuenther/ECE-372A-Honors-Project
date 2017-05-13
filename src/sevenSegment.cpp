#include "sevenSegment.h"
#include <avr/io.h>

void initSevenSegment(){
	DDRF |= (1<<DDF3 | 1<<DDF4 | 1<<DDF5 | 1<<DDF6 | 1<<DDF7);
	DDRK |= (1<<DDK0 | 1<<DDK1 | 1<<DDK2 | 1<<DDK3 | 1<<DDK4 | 1<<DDK5 | 1<<DDK6 | 1<<DDK7);
}

void dispNum(int num){
	switch(num / 10){
		case 1:
			SEG_A1(0);
			SEG_B1(1);
			SEG_C1(1);
			SEG_D1(0);
			SEG_E1(0);
			SEG_G1(0);
			break;
		case 2:
			SEG_A1(1);
			SEG_B1(1);
			SEG_C1(0);
			SEG_D1(1);
			SEG_E1(1);
			SEG_G1(1);
			break;
		case 3:
			SEG_A1(1);
			SEG_B1(1);
			SEG_C1(1);
			SEG_D1(1);
			SEG_E1(0);
			SEG_G1(1);
			break;
		default:
			SEG_A1(0);
			SEG_B1(0);
			SEG_C1(0);
			SEG_D1(0);
			SEG_E1(0);
			SEG_G1(0);
			break;
	}
	switch(num % 10){
		case 0:
			SEG_A2(1);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(1);
			SEG_E2(1);
			SEG_F2(1);
			SEG_G2(0);
			break;
		case 1:
			SEG_A2(0);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(0);
			SEG_E2(0);
			SEG_F2(0);
			SEG_G2(0);
			break;
		case 2:
			SEG_A2(1);
			SEG_B2(1);
			SEG_C2(0);
			SEG_D2(1);
			SEG_E2(1);
			SEG_F2(0);
			SEG_G2(1);
			break;
		case 3:
			SEG_A2(1);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(1);
			SEG_E2(0);
			SEG_F2(0);
			SEG_G2(1);
			break;
		case 4:
			SEG_A2(0);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(0);
			SEG_E2(0);
			SEG_F2(1);
			SEG_G2(1);
			break;
		case 5:
			SEG_A2(1);
			SEG_B2(0);
			SEG_C2(1);
			SEG_D2(1);
			SEG_E2(0);
			SEG_F2(1);
			SEG_G2(1);
			break;
		case 6:
			SEG_A2(1);
			SEG_B2(0);
			SEG_C2(1);
			SEG_D2(1);
			SEG_E2(1);
			SEG_F2(1);
			SEG_G2(1);
			break;
		case 7:
			SEG_A2(1);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(0);
			SEG_E2(0);
			SEG_F2(0);
			SEG_G2(0);
			break;
		case 8:
			SEG_A2(1);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(1);
			SEG_E2(1);
			SEG_F2(1);
			SEG_G2(1);
			break;
		case 9:
			SEG_A2(1);
			SEG_B2(1);
			SEG_C2(1);
			SEG_D2(1);
			SEG_E2(0);
			SEG_F2(1);
			SEG_G2(1);
			break;
		default:
			SEG_A2(0);
			SEG_B2(0);
			SEG_C2(0);
			SEG_D2(0);
			SEG_E2(0);
			SEG_F2(0);
			SEG_G2(0);
			break;
	}
}
