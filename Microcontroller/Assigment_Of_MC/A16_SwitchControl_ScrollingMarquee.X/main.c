/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A16 - Implement a scrolling number marquee with direction control
 * Discription : 

 Problem Statement:

Implement a scrolling number marquee on SSDs with scroll direction control on a key press

Output Requirement:

As soon as the board is powered on or reset, a static message (hardcoded) should start scrolling from right to left SSD.
The scroll should repeat indefinitely unless and until the direction change keys are pressed. 
The scroll frequency should be 0.5Hz (Approximately, Non Timer Based). 
On press of Right Direction Key, the scroll direction should change from left to right on the same instance. 
On press of Left Direction Key, the scroll direction should change from right to left on the same instance. 
On press of Stop / Start Key the scroll should be stopped on the same instance. 
On press of any key the scroll should start on the same instance.

Inputs:
Static number message in code (10 digit number + 2 spaces) 
DKS1 to Left Direction Key 
DKS2 to Right Direction Key
DKS3 to Stop / Start Key

 * Date : 15/09/2022
 */

#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"


static unsigned char ssd[MAX_SSD_CNT]={ZERO, ZERO, ZERO, ZERO};
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, UNDERSCORE, UNDERSCORE};


#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_ssd();
}
 
void main(void) {
    unsigned char ssd[MAX_SSD_CNT]; //optional
     
    unsigned int flag = 1,left_flag = 0,right_flag = 0;
    unsigned char key;
    init_config();
    unsigned int wait = 0, i = 0,count = 0, j = 0;
    while (1)
    {
        
       
        key = read_digital_keypad(STATE);

        /*logic for display value 0 1 2 3 when on the Board*/
        if(count == 0)
        {
              ssd[0] = ZERO; //digit[i % 12];
              ssd[1] = ONE ;  //digit[(i + 1) % 12];
              ssd[2] = TWO; // digit[(i + 2) % 12];
              ssd[3] = THREE; //digit[(i + 3) % 12];  
              count++;
        }
        if(key == SW3) // Use Switch 3 for stop or start the SSD
        {
            flag = !flag;
        }
        /* with Switch 1 change the Flag value For Left Scrolling*/
        if(key == SW1)
        {
          left_flag = !left_flag; 
          if(right_flag != 0)
             right_flag = 0; 
          i = 0;
        }
        /* with Switch 2 change the Flag value For right Scrolling*/
        if(key == SW2)
        {
          right_flag = !right_flag; 
           if(left_flag != 0)
             left_flag = 0; 
          j = 0;
        }
        /* For Left Scorlling */
        if(left_flag && flag)
        {
            if(wait++ == 50)
            {
              wait = 0;
              ssd[0] = digit[i % 12];
              ssd[1] = digit[(i + 1) % 12];
              ssd[2] = digit[(i + 2) % 12];
              ssd[3] = digit[(i + 3) % 12];
              i++;
            }
        }
        /*For Right Scorlling */
        if(right_flag && flag)
        {
            if(wait++ == 50)
            {
              wait = 0;
              ssd[0] = digit[(12 - j) % 12];
              ssd[1] = digit[(13 - j) % 12];
              ssd[2] = digit[(14 - j) % 12];
              ssd[3] = digit[(15 - j) % 12];
              j++;
              if(j == 11)
              {
                  j = 0;
              }
            }
        }
        display(ssd);
    }
    return;
}
