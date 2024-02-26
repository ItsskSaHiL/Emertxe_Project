/*
 * Name : Sk Sahil 
 * File:   main.c
 * Assigment : A20 - Implement a right scrolling message marquee
 * Date :  21/09/2022
 * Discription : 
Problem Statement:
     Implement a right scrolling message marquee on CLCD.

Output Requirements:
    As soon as the board is powered up or reset, a static message (hardcoded) should start scrolling from left to right CLCD. 
    The scroll should repeat indefinitely. 
    The scroll frequency should be 0.5Hz (Approximately, Non Timer Based).
Inputs:
    Static message in embedded code
 */

#include <xc.h>
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void)
{
   init_clcd(); 
}

void main(void) 
{   
    init_config();
    
    clcd_print("Right Scrolling",LINE1(0));
    
    int wait;
    unsigned char temp;
    char message[] = "Good_Morning____";
    
    
    while (1) 
    {
            // Right Scrolling    
        if(wait++ == 5000)
        {
            temp = message[15];
            for(int i = 15;i > 0; i--)
            {
                message[i] = message[i - 1];
            }
            message[0] = temp;
           clcd_print(message,LINE2(0));
        }          
    }
    return;
}

