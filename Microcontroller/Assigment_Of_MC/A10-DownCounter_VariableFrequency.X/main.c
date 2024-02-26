/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A10 - Implement a 4 digit down counter with variable frequency
 * Date : 02/10/2022
 * Discription : 
Problem Statement:
  Implement a 4 digit down counter with variable frequency. The system should count from 9999 to 0000 and then should stop. The count source should be the program cycles. The frequency of the counting should be varied using a potentiometer. If the potentiometer is tuned to max position the counting should be 10 times faster than the default. The result would be displayed on SSDs

Output Requirement:

  As soon as the board is powered on or reset, it should start decrementing 
  The rate of the count should be based on the current position of the Potentiometer Knob.
  On clockwise rotation of the Knob, the rate of down count should increase.
  On anticlockwise rotation of the Knob, the rate of the count should decrease (approximately 10 times slower than the max rate)
  The counter should stop once it reaches 0.

Inputs:
  Potentiometer

 */

#include <xc.h>
#include "ssd.h"
#include "adc.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) 
{
    init_adc();
    init_ssd();
}

void main(void) {
    /* Initilization the SSD as an array data*/
    unsigned char ssd[MAX_SSD_CNT];
    
    /* Initilize all the Macros in one array */
    unsigned char digit[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    
    unsigned int count = 9999, delay = 0;
            
    init_config();

    while (1) 
    {    
        
        
         if(delay++ == read_adc())
         {
            delay= 0;
            ssd[3] = digit[count % 10];
            ssd[2] = digit[(count % 100) / 10];
            ssd[1] = digit[(count % 1000) / 100];
            ssd[0] = digit[(count / 1000)];
            if(count > 0)
            {
              count--;
            }
         }
         if(count == 0)
         {
             ssd[3] = ZERO;
             ssd[2] = ZERO;
             ssd[1] = ZERO;
             ssd[0] = ZERO;
         }
           display(ssd);
    }
    return;
}
