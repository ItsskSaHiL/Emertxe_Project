/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A12 - Implement a Timer Down Count
 * Date : 22/09/2022
 * Discription : 
 * 
 * Problem Statement:

Implement a Timer (Down Count). Timer should start down counting from set Time to 0. The user should be able to preset the timer value from 99 min (Max) to 1 sec (Min) with the help of switches. The preset mode should be indicated by blinking the field choose every half second. The user will choose the field with the help of switches. The previous set value should be loaded after time expiration.

Output Requirement:

   As soon as the board is powered on or reset, the time should start in set mode
   The decimal point of the hours field (one?s place) should glow
   The set mode is indicated by a blink on the seconds field every 500 msecs
   The fields can be selected with Choose Field Key, The selected field should blink at the rate of 500 msecs indicating the selection
   The Increment Key could be used to increment and the Decrement Key could be used to decrement the value of selected field, It should be level triggered
   Once the time is set you may use the Set / Edit Key to start the timer and this mode is called a run mode.
   No key except Set / Edit key should sensitive in run mode
   No key except Set / Edit key should sensitive in run mode

Inputs:
    DKS1 (Digital Keypad Switch 1) as Increment key
    DKS2 (Digital Keypad Switch 2) as  Decrement key
    DKS3 (Digital Keypad Switch 3) as  Choose Field key
    DKS4 (Digital Keypad Switch 4) as Set/Edit key
    Timer

 * 
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
    TMR2ON=0;
    GIE=1;
}

void main(void) {  
    
    // All the initilazition 
    init_config();
    
    init_timer2();
    unsigned long int wait = 0;
    unsigned char key;
    static int min_temp,sec_temp;
    unsigned int sw4_flag = 0,bnk_flag = 0,sw3_flag = 0;
    
    while (1) 
    {
        key = read_digital_keypad(STATE); // Read the keypad 
      
        
        
        if(key == SW4)  // When we press SW4
        { 
           sec_temp = sec;
           min_temp = min;
           sw4_flag = !sw4_flag ; 
           TMR2ON = !tmr_flag;   // Timer off
           tmr_flag = !tmr_flag;
           
        }
        
             
        if(key == SW3) // SW3 Press for Edit Mode
        {
            sw3_flag = !sw3_flag;
        }
        if(tmr_flag) // Without press the key normal mode for display DIgital clock value and also timer on mode
        {
            if((min < 0))
            {
                min = min_temp;
                sec = sec_temp;
            }
          ssd[0] = digits[min / 10];
          if(flag)
          ssd[1] = digits[min % 10]|DOT;
          else
          ssd[1] = digits[min % 10];
          ssd[2] = digits[sec / 10];
          ssd[3] = digits[sec % 10];
        }
    
           
    if(sw4_flag == 0)  // Blinking the led when it in Edit mode 
    {
         ssd[0] = digits[min / 10];
         ssd[1] = digits[min % 10]; 
         
         
         ssd[2] = digits[sec / 10];
         ssd[3] = digits[sec % 10]; 
         
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
    
        if((sw3_flag == 0) && (sw4_flag == 0))  // Increment or decrement the minute field for SW1 & SW2 press 
        {
          
           if(key == SW1)
            {
                sec++;
                if(sec > 59)  // When 0 1 2 3 ...58 59 -- 0 1 2 3 ...
                {
                    sec = 0;
                }
            }
          
           if(key == SW2)
            {
                
                if((sec == 0) && (key == SW2)) // For Decremt logic
                {
                    sec = 59;
                }
                else
                {
                    sec--;
                }          
           }  
          
        }
        if((sw3_flag == 1) && (sw4_flag == 0) ) // Increment or decrement hour field 
        {          
            if(key == SW1)
            {
                min++;
                if(min > 99) // when 0 1 2 3....22 23 -- 0 1 2 3 ... 22 23
                {
                    min = 0;
                }
            }
            if(key == SW2)
            {
              if((min== 0) && (key == SW2))
                {
                    min = 99;
                }
                else
                {
                  min--;  
                }    
            }
             
        }
        if(sw4_flag)//Whwn SW4 press for start mode 
            display(ssd);
    }
    return;
}

