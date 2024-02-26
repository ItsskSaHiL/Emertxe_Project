/*
 * NAME : Sk Sahil
 * 
 * DATE : 03/10/2022
 * Assigment : A06-Implement a point brightness control

 * Discription : 
 * Problem Statement:

Implement a point brightness control using PWM (Timer ISR Based). The LED should dim to a fixed brightness (say 10% duty cycle). Once the user presses a switch the LED should glow at 100% duty cycle for 5 seconds and then after 5 seconds time out, the LED should dim back to 10% duty cycle.

Output Requirements:

As soon as the board is powered on or reset, LED should glow with half brightness (Duty cycle = 10%)
On Interrupt, LED should glow with 100% brightness for 5 seconds
After 5 seconds, the LED should go back to 10% brightness
Inputs:
DKS1 (Digital Keypad Switch 1) as Interrupt
Timer for Dimming
 *  */

#include <xc.h>
#include "main.h"
#include "timers.h"
#include "digital_keypad.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

extern int flag;
void software_pwm(unsigned char key)
{
    static unsigned long int period = 100, loop_counter = 0, wait = 0, duty_cycle = 50;            
    while (1) 
    {        
        /*checking if timer 0 interrupt flag is 0*/
        /*10%-LED blinking*/
        if (TMR0IE == 0)
        {
            duty_cycle = 10;
        }
        /*reading key pressed*/
        key = read_digital_keypad(LEVEL);
        
        if (wait-- == 0)
        {

            wait = 1000;

            if (key == SW1)
            {
                /*changing duty cycle to 100 on key press*/
                  duty_cycle=100;
                  
                  TMR0IE = 1;
                  
            }
            
        }
        /*50%-LED Blinking*/
        if (loop_counter < duty_cycle)
        {
            LED1 = 1;
        }
        else if (loop_counter > duty_cycle)
        {
            LED1 = 0;
        }
        if(loop_counter++ == period)
        {
            loop_counter = 0;
        }
        
    }
}
void init_config(void) {
    	
    LED_ARRAY = 0x00;    // off allLED
	LED_ARRAY_DDR = 0x00;
    
    init_digital_keypad();
    init_timer0();
    
    /*Global interrupt enable*/
    GIE = 1;    
}
void main(void) {
    init_config();
    unsigned char key;
    
    while (1) {
        
        key = read_digital_keypad(LEVEL);       
        software_pwm(key);       
    }
    return;
}

    
