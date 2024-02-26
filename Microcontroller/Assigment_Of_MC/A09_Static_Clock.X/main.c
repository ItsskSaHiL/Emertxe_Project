/*
 * Name : Sk Sahil
 * File:   isr.c
 * Assigment : A09 - Implement a static clock on SSD using internal timer
 * Discription : 
 * 
 Problem Statement:

   Implement a static (non configurable) clock on SSD (Shown in the video) using internal timer.

Output Requirements:

   As soon as the board is powered on or reset, the clock should start at 12.00.
   The decimal point of the hours field (one?s place) should blink every 500 msecs (0.5 Hz)
   The clock format should be 24 Hrs.

Inputs:
       Timer
 * Date : 18/09/2022
 */
#include <xc.h>
#include "ssd.h"
#include"main.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    //initialize ssd
    init_ssd();
    /* set Global Interrupt Enable bit , peripheral interrupt enable bit*/
    PEIE=1;
    GIE=1;
}

void main(void) {  
    
    init_config();
    
    init_timer2();

    while (1) {
   
     ssd[0] = digits[(hour / 10) % 10];
    if(flag)
    ssd[1] = (digits[(hour / 1) % 10])|DOT;
    else
    ssd[1] = (digits[(hour / 1) % 10]);
    ssd[2] = digits[(minute / 10) % 10];
    ssd[3] = digits[(minute / 1) % 10];

    display(ssd);
    }
    return;
}

