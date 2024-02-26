/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A15 - Implement a left scrolling number marquee
 * Discription : 
 * 
 * Problem Statement:

Implement a left scrolling number marquee on SSDs.

Output Requirements:

As soon as the board is powered up or reset, a static message (hardcoded) should start scrolling from right to left on SSD.

The scroll should repeat indefinitely.

The scroll frequency should be 0.5Hz (Approximately, Non Timer Based).

Inputs:
Static number message in code (10 digit number + 2 spaces)
            
 * Date : 12/09/2022
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
    unsigned char ssd[MAX_SSD_CNT]; //optional
     
    
    init_config();
    unsigned int wait = 0, i = 0;
    while (1) {

	/* shift the numbers 0123 to 1234 to 3456  .... to 6789 to 789_ 89_ _ to 9__0 to __01*/
        /* 0++ ,1++,2++,3++ -> 1234 */
        if(wait++ == 50)
        {
            wait = 0;
            ssd[0] = digit[i % 12];
            ssd[1] = digit[(i + 1) % 12];
            ssd[2] = digit[(i + 2) % 12];
            ssd[3] = digit[(i + 3) % 12];
            i++;
        } 
    
        display(ssd);
        
    }
    return;
}
