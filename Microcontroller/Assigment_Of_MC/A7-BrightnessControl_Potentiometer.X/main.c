/*
 * Name : Sk Sahil 
 * File:   main.c
 * Assigment :  A07 - Implement a brightness control using potentiometer
 * Date :  27/09/22
 * Discription : 
 * Problem Statement:

    Implement a LED dimmer application with bit banging PWM. The brightness of the LED illumination should be based on the user input tuning the Knob of potentiometer.

Output Requirement:

      On giving power supply to the board, read the value of pot. Based on that value, set the duty cycle. Again read the pot value
      If it is different from previous value, update duty cycle accordingly
      If it is same do nothing
      Repeat the same on regular interval or continuously. 
       Use program cycles to generate PWM
Inputs:
      Potentiometer 1 as Knob
      Program Cycles as Period

 */

#include <xc.h>
#include "main.h"
#include "adc.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
#define PERIOD              1023
/* Directly use ADC  value for making PWM By Making PERIOD as 1023*/
void glow_led(unsigned short adc_reg_val)
{
    static unsigned short duty_cycle;
    static unsigned short loop_counter;
    static unsigned int wait = 0;
    
       if (!wait--)
    {
        wait = 50;
       duty_cycle = adc_reg_val;        
    }
    
    if (loop_counter <= duty_cycle)
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
    
    if (loop_counter == PERIOD)
    {
        loop_counter = 0;
    }
    
    loop_counter++;
}


static void init_config(void) {
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = 0x00;
    
    init_adc();
}

void main(void) {
    unsigned short adc_reg_val; //0 to 1023
    
    init_config();

    while (1) {
        adc_reg_val = read_adc();//10 bits -> 0 to 1023
        
        glow_led(adc_reg_val);
    }
    return;
}
