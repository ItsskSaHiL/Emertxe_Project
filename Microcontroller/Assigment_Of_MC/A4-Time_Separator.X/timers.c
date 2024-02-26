/*
 * Name : Sk Sahil
 *  Ceating Time Separator  using timer 
 * File : timer.c
 * Date : 04/09/2022
 */
#include <xc.h>

void init_timer0(void)
{
    /* Setting the internal clock source */
    T0CS = 0;
    
    /* Assinging no prescaler to Timer0 */
    PSA = 1;
    
    
    TMR0 = 6;
    
    /* The timer interrupt is enabled */
    TMR0IE = 1;
}

void init_timer2(void)
{
    /* Selecting the scale as 1:1 */
    T2CKPS0 = 0;
    T2CKPS1 = 0;

    /* Loading the Pre Load register with 250 */
    PR2 = 250;
    
    /* The timer interrupt is enabled */
    TMR2IE = 1;
       
    /* Switching on the Timer2 */
    TMR2ON = 1;
}

// FDunction for Timer 1 

void init_timer1(void)
{
   // Use for internal clock 
  TMR1CS = 0;
  
  // I cant use prescale value
  T1CKPS1 = 0;
  T1CKPS0 = 0;
  
  // Timer1 Eneble bit
  TMR1IE = 1;
  
  // For on the timer
  TMR1ON = 1;
  
  // Assigning Prescale Value for get 250 ticks happen 
  TMR1H = 0xFF;
  TMR1L = 0x05;
  
}