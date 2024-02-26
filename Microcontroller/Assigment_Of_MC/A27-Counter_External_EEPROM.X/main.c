/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A27 - Implement a 4 digit key press counter with persistence using external EEPROM
 * Date : 05/10/2022
 * Discription : 
Problem Statement:
   Implement a 4 digit key press counter with persistence using external EEPROM. 

Output Requirements:
  - As soon as the board is powered up or reset, counter should display 0000 on SSDs.
  - On every key press  counter value should increment by 1.
  - On a  long key press (2 seconds), Count should  reset to zero.
  - On pressing STORE switch, the current count should be  stored in external EEPROM.
  - On subsequent power ups or reset the counter should start from the previous stored value in the external EEPROM.
Inputs:
  DKS 1 as Count input .
  DKS 1 Long press to reset the count .
  DKS 2 Store Input.
  */

#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"
#include"at_24c04.h"
#include"i2c.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) 
{
    init_i2c(100000);
    init_digital_keypad();
    init_ssd();
}

void main(void) 
{
    /* Initilization the SSD as an array data*/
    unsigned char ssd[MAX_SSD_CNT] = { ZERO,ZERO,ZERO,ZERO };
    
    /* Initilize all the Macros in one array */
    unsigned char digit[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    
    /* Initilize all integers for Up Counter and Delay */
    unsigned int count,count2,wait = 0;
    
    unsigned char key;
    unsigned char key2;
    
    init_config();

    while (1) 
    {
         count2 = read_24c04(0x01) + (read_24c04(0x02) * 10) + (read_24c04(0x03) * 100) + (read_24c04(0x04) * 1000);
         
         if(count == 0) 
         {
           count = count2;  
          /* write_24c04(0x01, 0);
           write_24c04(0x02, 0);
           write_24c04(0x03, 0);
           write_24c04(0x04, 0);*/
         }
           /* Use State for Up Counting */ 
        key = read_digital_keypad(STATE);
        /* Use Level For Reset the value */
        key2 = read_digital_keypad(LEVEL);
        for(int i = 300;i--; );

        /* Logic For The Display the number in SSD */
       if(key == SW1)
        {
           if(count <= 9999)
           {
               count++;
           }
           else if(count > 9999)
           {
               count = 0;
           }
        }
        /* For storing data in EEPROM */
        if(key == SW2)
        {
          write_24c04(0x01, (count % 10));
          write_24c04(0x02, ((count / 10) % 10));
          write_24c04(0x03, ((count / 100) % 10));
          write_24c04(0x04, (count / 1000));
          write_24c04(0x05,1);
        }
        
        // For Reset the value 
        if(key2 == SW1)
        {
          if(wait++ == 500)
            {
              wait = 0;
             write_24c04(0x01, 0);
             write_24c04(0x02, 0);
             write_24c04(0x03, 0);
             write_24c04(0x04, 0);
              count = 0;
            }   
        }
           ssd[3] = digit[count % 10];
           ssd[2] = digit[(count % 100) / 10];
           ssd[1] = digit[(count % 1000) / 100];
           ssd[0] = digit[(count / 1000)];
           display(ssd);
    }
    return;
}
