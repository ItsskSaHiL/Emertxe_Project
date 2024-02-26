/*
 * Name : Sk Sahil 
 * File:   main.c
 * Assigment :  A08 - Implement a LED dimmer application using PWM (Timer ISR Based)
 * Date : 27/09/2022
 * Discription : 
 * Problem Statement:

     Implement a LED dimmer application using PWM (Timer ISR Based). The brightness of the LED illumination should be based on the user input tuning the Knob of potentiometer.

Output Requirements:

     On giving power supply to the board, read the value of pot. Based on that value, set the duty cycle. Again read the pot value
     If it is different from previous value, update duty cycle accordingly
     If it is same do nothing
     Repeat the same on regular interval or continuously. 
     Use timer to generate PWM
Inputs:
     Potentiometer 1 as Knob
     Timer for PWM
 */

#include <xc.h>
#include "main.h"
#include "timers.h"
#include "adc.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
/*Using Gloabal variable for ADC input*/
unsigned char duty_cycle;

static void init_config(void)
{
    /*All initilization done here*/
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    init_timer0();
    
    /* Enable all the Global Interrupts */
    GIE = 1;
    init_adc();
}

void main(void)
{  
    init_config();

    while (1) 
    {
        /*Read ADC value and /10 for storing in 1 byte of data */
      duty_cycle = (unsigned char*)(read_adc()/10);
      for(int i = 500;i--; );
    }
    return;
}
