/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A18 - Implement a 10 digit down counter
 * Date : 20/09/2022
 * Discription : 
 * 
Problem Statement:
 *  Implement a 10 digit down counter on CLCD. 

Output Requirements:

  As soon as the board is powered up or reset, CLCD display the title (Down Counter) on the first line.  
  On second line, 9999999999 (10 digit number) starts decrementing. 
  Decrement happens at constant rate (You may have lesser delay as possible since it's a 10 digit counter).
  The counter stops after reaching count value of 0000000000. 
Inputs:
  Program Cycles as Count

 */

#include <xc.h>
#include"main.h"
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void)
{
    init_clcd(); //configure the clcd
}

void main(void)
{
    init_config();

	int wait = 400;
	char str[] = "9999999999";

    //Print a given message on LINE1
	clcd_print(" DOWN COUNTER ", LINE1(0));
    clcd_print("Count:", LINE2(0));
    clcd_print(str, LINE2(6));
    while (1)
    {
		if (wait-- <= 0)
		{
			wait = 400;
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
                str[0] = '9';
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
            if((str[0] == '0') && (str[1] == '0') && (str[2] == '0') && (str[3] == '0') && (str[4] == '0') && (str[5] == '0') && (str[6] == '0') && (str[7] == '0') && (str[8] == '0') && (str[9] == '0'))
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
            }
  			
             
            clcd_print(str, LINE2(6));   //Write string to clcd in line 	
		}
    }
}







