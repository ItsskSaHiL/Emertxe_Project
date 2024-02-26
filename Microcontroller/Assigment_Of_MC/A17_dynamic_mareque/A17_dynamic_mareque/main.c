/*
 * File:   main.c
 */

#include <xc.h>
#include "ssd.h"

static unsigned char ssd[MAX_SSD_CNT]={ZERO, ZERO, ZERO, ZERO};
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, UNDERSCORE, UNDERSCORE};

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_ssd();
}
 
void main(void) {
    unsigned char ssd[MAX_SSD_CNT];
    
    init_config();

    while (1) {
	/*read switches*/
	key = ;
	if (key == SW1)
	{
		flag = !flag;
	}
	if (wait++ == ?)// provide delay
	{
		wait = 0;
	if (flag)
	{
	/* shift the numbers 0123 to 1234 to 3456  .... to 6789 to 789_ 89_ _ to 9__0 to __01*/
        /* 0++ ,1++,2++,3++ -> 1234 */
	/* limit the count should not exceed 12*/
	}
	else
	{
	/* shift the numbers 0123 to 1234 to 3456  .... to 6789 to 789_ 89_ _ to 9__0 to __01*/
        /* 0-- ,1--,2--,3-- -> _012 */
	/*limit the count should not go less than 0 */	
	}
}
        ssd[0] = digit[?];
        ssd[1] = digit[?];
        ssd[2] = digit[?];
        ssd[3] = digit[?];
        
        display(ssd);
    }
    return;
}
