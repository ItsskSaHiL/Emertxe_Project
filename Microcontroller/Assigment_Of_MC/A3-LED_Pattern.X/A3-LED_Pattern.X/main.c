/*
 * File:   main.c
 * Author: Sk Sahil 
 * Problem Statement : Write a Embedded C program to display the multiple patterns on the LEDs controlled by the switches.
 *                     For every switch, dedicate a LEDs glow pattern.The pattern should change on key press
 Date : 26/08/22
 */


#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF

static void init_config(void) {
    /*To keep all LEDS OFF initially*/
    LED_ARRAY1 = OFF;
    
    /*To configure PORTD as output PORT*/
    LED_ARRAY1_DDR = 0x00; 
    
    /* Initializing digital keypad */
    init_digital_keypad();

}

void main(void) {
    //Variable declaration
    unsigned char key, key_copy = SW6;
    
    init_config();
    
    while (1) {
        
        /*To read key press*/
        key = read_digital_keypad(STATE);
        
        /*If switch is pressed, then only update key_copy*/
        if (key != ALL_RELEASED && key_copy != key)
        {
            LED_ARRAY1 = OFF;
            key_copy = key;
        }
        glow_on_press(key_copy);
    }

    return;
}

void glow_on_press(unsigned char key)
{
           
    unsigned char static flag = 0;
    static unsigned int wait = 0;
    wait++;
    static unsigned int i = 0;
     static unsigned int j = 0;
    if(key == SW1)
    {
        //Code for pattern1 same as assignment1
        //The LEDs should glow from Left to Right and Right to left as explained in the assignment-1.
         // First condition led ON top to bottom
        // First condition led ON top to bottom
        if(i < 8)
        {
        
           if( wait == 1000)
            {
            wait = 0;
            LED_ARRAY1 = LED_ARRAY1 | (1 << i) ;
            i++;
            }
        } 
        else if(i >= 8 && i < 16) // Second condition OFF led from top to bottom 
        {
        
           if( wait == 1000)
            {
             wait = 0;
           LED_ARRAY1 = LED_ARRAY1 & ~(1 << (i - 8));
            i++;
            }
        }
        else if(i >= 16 && i < 24)  //Condition for ON led from bottom to top 
        {
        
            if( wait == 1000)
            {
             wait = 0;
           LED_ARRAY1 = LED_ARRAY1 | (1 << (23 - i));
            i++;
            }
        }
        else if(i >= 24 && i < 32)  // Condition  for OFF led from bottom to top 
        {
            if( wait == 1000)
            {
             wait = 0;
           LED_ARRAY1 = LED_ARRAY1 & ~(1 << (31 - i));
           i++;
            }
        }
        if(i == 32)  // for continous process 
        {
           i = 0;
        }   
    }
    else if(key == SW2)
    {
        //Code for pattern2
        //The LEDs should glow from left to Right and switch off from left to right, no direction control/ direction change
        if(j < 8)
        {
        
           if( wait == 1000)
            {
            wait = 0;
            LED_ARRAY1 = LED_ARRAY1 | (1 << j) ;
            j++;
            }
        } 
        else if(j >= 8 && j < 16) // Second condition OFF led from top to bottom 
        {
        
           if( wait == 1000)
            {
             wait = 0;
           LED_ARRAY1 = LED_ARRAY1 & ~(1 << (j - 8));
            j++;
            }
        }
        if(j == 16)  // for continous process 
        {
           j = 0;
        }  
    }
    else if(key == SW3)
    {
        //Code for pattern3
        //The LEDs should blink alternately
         if( wait == 2000)
        {
            wait = 0;
            flag = !flag;
            LED_ARRAY1 = 0xAA;  
        }
        if( flag)
        {
            LED_ARRAY1 = ~(0xAA);
        }
    }
    else if( key == SW4)
    {
        //Code for pattern4
        //The LEDs has to blink nibble wise, i.e first 4 LEDs will be ON, next 4 LEDs will be OFF, 
        //after first 4 LEDs will be OFF, next 4 LEDs will be ON.
        if( wait == 2000)
        {
            wait = 0;
            flag = !flag;
            LED_ARRAY1 = 0xF0;  
        }
        if( flag)
        {
            LED_ARRAY1 = 0x0F;
        }
    
    }
    
}

