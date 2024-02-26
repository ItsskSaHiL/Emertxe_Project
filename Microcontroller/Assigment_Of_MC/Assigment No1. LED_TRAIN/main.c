/*
 * File:   main.c
 * Author: Sk Sahil
 * Project : LED TRAIN PATTERN 
 * Created on August 22, 2022, 11:49 AM
 */


#include <xc.h>
#include "main.h"
#pragma config WDTE = OFF //Watchdog timer disabled

static void init_config(void)
{
   
   LED_ARRAY_2 = 0x00;
   LED_ARRAY_2_DDR = 0x00;     //Write your initialization code here
}

void main(void) 
{
    init_config(); //Calling initializing function
    unsigned long int delay = 1000;
    int i = 0;
    while (1) 
    {
        // First condition led ON top to bottom
        if(i < 8)
        {
        
            if(delay-- == 0)
            {
            delay = 1000;
            LED_ARRAY_2 = LED_ARRAY_2 | (1 << i) ;
            i++;
            }
        } 
        else if(i >= 8 && i < 16) // Second condition OFF led from top to bottom 
        {
        
            if(delay-- == 0)
            {
            delay = 1000;
           LED_ARRAY_2 = LED_ARRAY_2 & ~(1 << (i - 8));
            i++;
            }
        }
        else if(i >= 16 && i < 24)  //Condition for ON led from bottom to top 
        {
        
            if(delay-- == 0)
            {
            delay = 1000;
           LED_ARRAY_2 = LED_ARRAY_2 | (1 << (23 - i));
            i++;
            }
        }
        else if(i >= 24 && i < 32)  // Condition  for OFF led from bottom to top 
        {
            if(delay-- == 0)
            {
            delay = 1000;
           LED_ARRAY_2 = LED_ARRAY_2 & ~(1 << (31 - i));
           i++;
            }
        }
        if(i == 32)  // for continous process 
        {
           i = 0;
        }
    }
   
    }

