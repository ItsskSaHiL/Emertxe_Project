/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A19 - Implement a 10 digit down counter with preset
 * Date : 22/09/2022
 * Discription :
 * Problem Statement:

- Implement a 10 digit down counter with preset (Shown in the video). 

Output Requirements:
- As soon as the board is powered up or reset, CLCD display the title in the first line
- In second line, 0000000000 (10 digit number) with least significant   digit blinking, This indicates the Preset Mode
- The digits can be selected with Choose Field Key, The selected field should blink at the rate of (approx 500 mses non timer based) indicating the selection
- The Increment Key could be used to increment the value of selected field, It should be edge triggered,
- On reaching the max value the digit value should rollover to 0
- Once the count is set you may use the Start / Preset Key to start the counter and this mode is called a run mode.
- Decrement happens at constant rate (You may have lesser delay as possible since it's a 10 digit counter)
- No key except Start / Preset key should sensitive in run mode 
- The counter should countdown to 0 and enter the preset mode

Pre-requisites:
You should have knowledge on,
- I/O Port
- CLCD
- Tactile Switch
- Matrix Keypad


Inputs:
- Program Cycles as Count
- MKP 1 Increment (roll back once max is reached) 
- MKP 2 Choose Field 
- MKP 3 Start / Set counter
*/

#include <xc.h>
#include"main.h"
#include "clcd.h"
#include"matrix_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void)
{
    init_clcd(); //configure the clcd
    init_matrix_keypad();
}

void main(void)
{
    init_config();

	int wait = 0;
	char str[] = "0000000000";
    unsigned char key;
    int pos = 9;
    unsigned int flag = 1;
    //Print a given message on LINE1
	clcd_print(" DOWN COUNTER ", LINE1(0));
    clcd_print("Count:", LINE2(0));
    clcd_print(str, LINE2(6));
    while (1)
    {  
        key = read_matrix_keypad(STATE);
        if(key == 3)
        {
            flag = !flag;
        }
        if(flag)
        {
          if(key == 1)
          {
              str[pos]++;
              if(str[pos] > '9')
                  str[pos] = '0';
          }
          if(key == 2)
          {
              --pos;
              if(pos < 0)
                  pos = 9;
          }
          if(wait++ == 2000)
          {
              wait = 0;
           clcd_print((str + pos), LINE2(6 + pos));
          }
          else
            clcd_print(" ", LINE2(6 + pos));
        }
        else
        {
		
            str[9]--;
            if(str[9] < '0')
            {
                str[8]--;
                str[9] = '9';
                
            }
            
            if(str[8] < '0')
            {
                str[7]--;
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[7] < '0')
            {
                str[6]--;
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[6] < '0')
            {
                str[5]--;
                str[6] = '9';
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[5] < '0')
            {
                str[4]--;
                str[5] = '9';
                str[6] = '9';
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[4] < '0')
            {
                str[3]--;
                str[4] = '9';
                str[5] = '9';
                str[6] = '9';
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[3] < '0')
            {
                str[2]--;
                str[3] = '9';
                str[4] = '9';
                str[5] = '9';
                str[6] = '9';
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[2] < '0')
            {
                str[1]--;
                str[2] = '9';
                str[3] = '9';
                str[4] = '9';
                str[5] = '9';
                str[6] = '9';
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[1] < '0')
            {
                str[0]--;
                str[1] = '9';
                str[2] = '9';
                str[3] = '9';
                str[4] = '9';
                str[5] = '9';
                str[6] = '9';
                str[7] = '9';
                str[8] = '9';
                str[9] = '9';
                
            }
            if(str[0] < '0')
            {
                str[0] = '0';
                str[1] = '0';
                str[2] = '0';
                str[3] = '0';
                str[4] = '0';
                str[5] = '0';
                str[6] = '0';
                str[7] = '0';
                str[8] = '0';
                str[9] = '0';
                flag = !flag;
                pos = 9;
                
            }       
            clcd_print(str, LINE2(6));   //Write string to clcd in line 	
       }
        clcd_print(str, LINE2(6));   //Write string to clcd in line 	
    }
}







