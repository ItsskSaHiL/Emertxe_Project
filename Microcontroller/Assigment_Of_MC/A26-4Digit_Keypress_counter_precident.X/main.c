/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A26 - Implement a 4 digit key press counter with persistence
 * Date : 20/09/2022
 * Discription : 
Problem Statement:
    Implement a 4 digit key press counter with persistence using Internal EEPROM. 

Output Requirements:
  - As soon as the board is powered up or reset, counter should display 0000 on SSDs.
  - On every key press  counter value should increment by 1.
  - On a  long key press (2 seconds), Count should  reset to zero.
  - On pressing STORE switch, the current count should be  stored in internal EEPROM.
  - On subsequent power ups or reset the counter should start from the previous stored value in the EEPROM.
Inputs:
   DKS 1 as Count input .
   DKS 1 Long press to reset the count .
   DKS 2 Store Input.

 */

#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    init_ssd();
}

void main(void) {
    /* Initilization the SSD as an array data*/
    unsigned char ssd[MAX_SSD_CNT] = { ZERO,ZERO,ZERO,ZERO };
    
    /* Initilize all the Macros in one array */
    unsigned char digit[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    
    /* Initilize all integers for Up Counter and Delay */
    unsigned int count,wait = 0;
    if(eeprom_read(0x04) != 1) 
      {
      eeprom_write(0x00,0);
      eeprom_write(0x01,0);
      eeprom_write(0x02,0);
      eeprom_write(0x03,0);
      eeprom_write(0x04,1);
      }
    count =  eeprom_read(0x00) + (eeprom_read(0x01) * 10) + (eeprom_read(0x02) * 100) + (eeprom_read(0x03) * 1000);
    /* Initilize the varialbe for switch */
    unsigned char key;
    unsigned char key2;

    init_config();

    while (1) 
    {
        /* Use State for Up Counting */ 
        key = read_digital_keypad(STATE);
        /* Use Level For Reset the value */
        key2 = read_digital_keypad(LEVEL);

        /* Logic For The Display the number in SSD */
        if(key == SW1)
        {
           count++;
        }
        if(key == SW2)
        {
          eeprom_write(0x00, (count % 10));
          eeprom_write(0x01, ((count / 10) % 10));
          eeprom_write(0x02, ((count / 100) % 10));
          eeprom_write(0x03, (count / 1000));
        }
        
        /* For Reset the value */
        if(key2 == SW1)
        {
          if(wait++ == 325)
            {
              wait = 0;
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
