/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A25 - Self counter using SSDs with storage on key press
 * Date : 20/09/2022
 * Discription : 
 Problem Statement
    Implement a self counter using SSDs with storage on key press.

Output Requirements
   As soon as the board is powered up or reset, counter should start self incrementing at rate of 1Hz from 0000 up to 9999 and then roll of to 0000 (Approximately, Non Timer Implementation).
   On save key press, count value should be  stored in internal EEPROM.
   On subsequent power ups or reset the counter should start from the previous stored value.
Inputs:
   DKS 2 as Save Count Key.
   Program Cycles as Count. 
 */

#include <xc.h>
#include "digital_keypad.h"
#include "ssd.h"

#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
 
static void init_config(void)
{
    init_digital_keypad();
    init_ssd();
}

void main(void) 
{
      unsigned char key, count;
      if(eeprom_read(0x04) != 1) 
      {
      eeprom_write(0x00,0);
      eeprom_write(0x01,0);
      eeprom_write(0x02,0);
      eeprom_write(0x03,0);
      eeprom_write(0x04,1);
      }
    unsigned int delay = 0;
    count =  eeprom_read(0x00) + (eeprom_read(0x01) * 10) + (eeprom_read(0x02) * 100) + (eeprom_read(0x03) * 1000);
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char digits[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
                       //     0     1   2    3       4     5    .......................
    init_config();

    while (1)
    {
        key = read_digital_keypad(STATE);
        if(key == SW2)
        {
          count =  eeprom_read(0x00) + (eeprom_read(0x01) * 10) + (eeprom_read(0x02) * 100) + (eeprom_read(0x03) * 1000); 
        }    
        if (key == SW1)
       {
         eeprom_write(0x00, (count % 10));
         eeprom_write(0x01, ((count / 10) % 10));
         eeprom_write(0x02, ((count / 100) % 10));
         eeprom_write(0x03, (count / 1000));
      }
        
     if(delay++ == 250)
        {
            delay = 0;
            if (count++ == 9999)
            {
              count = 0;
            }
        }
        ssd[3] = digits[count%10]; 
        ssd[2] = digits[(count/10)%10]; 
        ssd[1] = digits[(count/100)%10]; 
        ssd[0] = digits[count/1000]; 
        display(ssd);
      
    }
    return;
}
