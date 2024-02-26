/*
 * Name : Sk Sahil 
 * File:   main.c
 * Assigment : A05 - Using Timer based PWM, implement a LED dimmer application.
 * Date : 28/09/2022
 * Discription : 
Problem Statement:

   Implement a LED dimmer application using PWM (Timer ISR Based). The brightness of the LED illumination should be based on 
   the user input using the switches.

Output Requirement:

  As soon as the board is powered on or reset, The LED should glow with 50% Duty Cycle (i.e the glow, half of its maximum intensity).
  The Increment Brightness Input should increase the Duty Cycle upto 100% (Total ON)
  The Decrement Brightness Input should decrease the Duty Cycle to 0% (Total OFF)
Inputs:

  DKS1 as Increase Brightness Input, Level Triggered
  DKS2 as Decrease Brightness Input, Level Triggered
  Program Cycles as Period

 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"
#include "timers.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

unsigned short duty_cycle = 50;    
    
static void init_config(void)
{
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
    init_timer2();
     PEIE=1;
    GIE=1;
}

void main(void) 
{
   
    unsigned char key;
    
    init_config();

    while (1)
    {
        key = read_digital_keypad(LEVEL);
        
       
        if(key == SW1)
        {
            if(duty_cycle < PERIOD)
            {
                duty_cycle++;
                for(int i = 5000; i--; );
            }
        }
        if(key == SW2)
        {
            if( (duty_cycle > 0) && (duty_cycle <= PERIOD))
            {
                duty_cycle--;
                for(int i = 5000; i--; );
            }
        }
       
    }
    return;
}
