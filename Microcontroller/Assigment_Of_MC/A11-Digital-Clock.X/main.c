/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A11 - Implement dynamic clock on SSD using internal timer
 * Date : 22/09/2022
 * Discription : 
 * Problem Statement:

Implement a dynamic (configurable) clock on SSD using internal timer

Output Requirement:

        As soon as the board is powered on or reset, the clock should start at 00.00.
        The decimal point of the hours field (one?s place) should blink every 500 msecs (0.5 Hz).
        The clock format should be 24Hrs
        The clock enters into configuration mode by pressing Set / Edit Key.
        The configuration mode is indicated by a blink on the minute field every 500 msecs
        The fields can be selected with Choose Field Key, The selected field should blink at the rate of 500 mses indicating the selection
        The Increment Key could be used to increment and the Decrement Key could be used to decrement the value of selected field, It should be level triggered
        Once the time is set you may use the Set / Edit Key to start the clock and this mode is called a run mode.
        No key except Set / Edit key should sensitive in run mode
Inputs:
      DKS1 (Digital Keypad Switch 1) as Increment key
      DKS2 (Digital Keypad Switch 2) as  Decrement key
      DKS3 (Digital Keypad Switch 3) as  Choose Field key
      DKS4 (Digital Keypad Switch 4) as Set/Edit key
      Timer

 */

#include <xc.h>
#include "ssd.h"
#include"main.h"
#include"digital_keypad.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    //initialize ssd
    init_ssd();
    /* set Global Interrupt Enable bit , peripheral interrupt enable bit*/
    PEIE=1;
    TMR2ON=1;
    GIE=1;
}

void main(void) {  
    
    // All the initilazition 
    init_config();
    
    init_timer2();
    unsigned long int wait = 0;
    unsigned char key;
    unsigned int sw4_flag = 0,bnk_flag = 0,sw3_flag = 0;
    
    while (1) 
    {
        key = read_digital_keypad(STATE); // Read the keypad 
      
        
        
        if(key == SW4)  // When we press SW4
        {
           sw4_flag = !sw4_flag ; 
           TMR2ON = !dis_flag;   // Timer off
           dis_flag = !dis_flag;
        }
        if(key == SW3) // SW3 Press for Edit Mode
        {
            sw3_flag = !sw3_flag;
        }
        if(dis_flag) // Without press the key normal mode for display DIgital clock value and also timer on mode
        {
          ssd[0] = digits[hour / 10];
          if(flag)
          ssd[1] = digits[hour % 10]|DOT;
          else
          ssd[1] = digits[hour % 10];
          ssd[2] = digits[minute / 10];
          ssd[3] = digits[minute % 10];
        }
    
           
    if(sw4_flag)  // Blinking the led when it in Edit mode 
    {
         ssd[0] = digits[hour / 10];
         ssd[1] = digits[hour % 10]; 
         
         
         ssd[2] = digits[minute / 10];
         ssd[3] = digits[minute % 10]; 
         
         if(sw3_flag == 0)  // Blink for minute field 
         {
             if(wait++ == 5)
             {
                 wait = 0;
              display_mnt(ssd); // Function for blink minute field
             }
            else
            {
              display_hour(ssd);
            }
         }
         if(sw3_flag == 1)  //blink for hour field
         {
             if(wait++ == 5)
             {
                 wait = 0;
              display_hour(ssd); //Function for blink hour field
             }
            else
            {
              display_mnt(ssd);
            }    
         }
          
         
    }
    
        if((sw3_flag == 0) && sw4_flag)  // Increment or decrement the minute field for SW1 & SW2 press 
        {
          
           if(key == SW1)
            {
                minute++;
                if(minute > 59)  // When 0 1 2 3 ...58 59 -- 0 1 2 3 ...
                {
                    minute = 0;
                }
            }
          
           if(key == SW2)
            {
                
                if((minute == 0) && (key == SW2)) // For Decremt logic
                {
                    minute = 59;
                }
                else
                {
                    minute--;
                }          
           }   
        }
        if((sw3_flag == 1) && sw4_flag ) // Increment or decrement hour field 
        {          
            if(key == SW1)
            {
                hour++;
                if(hour > 23) // when 0 1 2 3....22 23 -- 0 1 2 3 ... 22 23
                {
                    hour = 0;
                }
            }
            if(key == SW2)
            {
              if((hour == 0) && (key == SW2))
                {
                    hour = 23;
                }
                else
                {
                  hour--;  
                }    
            }  
        }
        if(sw4_flag == 0)//Whwn SW4 press for start mode 
            display(ssd);
    }
    return;
}

