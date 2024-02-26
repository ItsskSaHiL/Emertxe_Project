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
