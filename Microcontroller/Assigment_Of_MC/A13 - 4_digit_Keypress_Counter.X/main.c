/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A13 - Implement a 4 digit key press counter
 * Date : 09/09/2022
 */

#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_ssd();
}

void main(void) {
    /* Initilization the SSD as an array data*/
    unsigned char ssd[MAX_SSD_CNT] = { ZERO,ZERO,ZERO,ZERO };
    
    /* Initilize all the Macros in one array */
    unsigned char digit[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    
    /* Initilize all integers for Up Counter and Delay */
    unsigned int count = 0,wait = 0;
    
    /* Initilize the varialbe for switch */
    unsigned char key;
    unsigned char key2;

    init_config();

    while (1) 
    {
        /* Use State for Up Counting */ 
        key = read_digital_keypad(STATE);
        /* Use Level For Reset the value */
        key2 = read_digital_keypad(LEVEL);

        /* Logic For The Display the number in SSD */
        if(key == SW1)
        {
           count++;
           ssd[3] = digit[count % 10];
           ssd[2] = digit[(count % 100) / 10];
           ssd[1] = digit[(count % 1000) / 100];
           ssd[0] = digit[(count / 1000)];
        }
        
        /* For Reset the value */
        if(key2 == SW1)
        {
          if(wait++ == 325)
            {
              wait = 0;
              count = 0;
              ssd[3] = ZERO;
              ssd[2] = ZERO;
              ssd[1] = ZERO;
              ssd[0] = ZERO;
            }   
          
        }
        
        display(ssd);
    }
    return;
}
