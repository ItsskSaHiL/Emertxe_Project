/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A24 - Implement a 8 field password access to screen
 * Date : 25/09/2022
 * Discription : 
 * Problem Statement:

 * Implement a 8 field password access to screen (Shown in the video). The user has to enter a key press pattern to unlock the Easter egg. If the user succeeds in unlocking the screen, he will be able to read the message. On failure attempt the LED will blink faster for every attempt. The max attempt would be 5.

Output Requirements:
  As soon as the board is powered up or reset, CLCD display the title in the first line.
  In second line, an ?_? (underscore) should blink at rate of 0.5Hz to display the password entry which is indicated as ?*? (star).
  Combination of Key1 and Key2 has to be used as a password.
  You should provide a max if 5 chances to unlock the system.
  On every wrong entry an LED should blink constant rate
  The rate of blink doubles on every failure attempt.
  On the fifth failure attempt the LED should glow constant and a message has to be put on screen indicating failure.
  You have to reset the board to retry.
  On a successful attempt the Embedded message should be displayed on screen.
Inputs:
     MKS1 and MKS2 as Password Keys.
 */

#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"
#include"main.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void)
{
    LED_ARRAY1 = 0x80;
    LED_ARRAY1_DDR = (LED_ARRAY1_DDR & 0x7F) ;
    init_clcd();  // Ini
    init_matrix_keypad();  // Ini
    
}

void main(void) 
{
       
    init_config();
    unsigned long int wait = 0,wait2 = 0,first;
    int attempt = 5;
    unsigned char key ,temp,key_copy;
    char message[] = "00000000",user_pass[9];
    static int i = 0;
    user_pass[9] = '\0';
       
    
    while (1) 
    {
        
        key = read_matrix_keypad(STATE); // 0 1 2 3 4 5 6 7 8 9 * #
        if(key != ALL_RELEASED)
        {
             key_copy = key;
             user_pass[i] = key + '0';
             i++;
             __delay_ms(50);  
        }
            if(i < 8)
            {
              clcd_print("Enter Password",LINE1(0));
              if(i == 0)
              {
                if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(4));
                }
                else
                  clcd_print(" ",LINE2(4));  
              }
              if(i == 1)
              {
                 clcd_print("*",LINE2(4));
                 if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print(" ",LINE2(5));
                }
                else
                  clcd_print("_",LINE2(5));  
              }
              if(i == 2)
              {
                clcd_print("**",LINE2(4));
                if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(6));
                }
                else
                  clcd_print(" ",LINE2(6));  
              }
              if(i == 3)
              {
              clcd_print("***",LINE2(4));
              if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(7));
                }
                else
                  clcd_print(" ",LINE2(7));  
              }
              if(i == 4)
              {
              clcd_print("****",LINE2(4));
              if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(8));
                }
                else
                  clcd_print(" ",LINE2(8));  
              }
              if(i == 5)
              {
              clcd_print("*****",LINE2(4));
              if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(9));
                }
                else
                  clcd_print(" ",LINE2(9));  
              }
              if(i == 6)
              {
              clcd_print("******",LINE2(4));
              if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(10));
                }
                else
                  clcd_print(" ",LINE2(10));  
              }
              if(i == 7)
              {
              clcd_print("*******",LINE2(4));
              if(wait2++ == 4)
                {
                    wait2 = 0;
                 clcd_print("_",LINE2(11));
                }
                else
                  clcd_print(" ",LINE2(11));  
              }
          }
           if(i == 8)
           {
               if(strcmp(message,user_pass) == 0)
                {
                  clcd_print("Yes, Password is",LINE1(0));  
                  clcd_print("Correct Password",LINE2(0));  
                  LED;
                }
               else
                {  
                   if(attempt > 0)
                   {
                       if(attempt == 5)
                       {
                       clcd_print("Incorrect pass 5",LINE1(0));    
                       clcd_print(" Attempt Left  ",LINE2(0)); 
                       }
                       if(attempt == 4)
                       {
                       clcd_print("Incorrect pass 4",LINE1(0));    
                       clcd_print(" Attempt Left  ",LINE2(0)); 
                       }
                       if(attempt == 3)
                       {
                       clcd_print("Incorrect pass 3",LINE1(0));    
                       clcd_print(" Attempt Left  ",LINE2(0)); 
                       }
                       if(attempt == 2)
                       {
                       clcd_print("Incorrect pass 2",LINE1(0));    
                       clcd_print(" Attempt Left  ",LINE2(0)); 
                       }
                       if(attempt == 1)
                       {
                       clcd_print("Incorrect pass 1",LINE1(0));    
                       clcd_print(" Attempt Left  ",LINE2(0));  
                       }
                       for(long int j = 250000;j--; );
                       attempt--;
                       i = 0; 
                       clcd_print("                ",LINE1(0));    
                       clcd_print("                ",LINE2(0)); 
                   }
                   else
                   {
                     clcd_print("Attmpt Maximum",LINE1(0));  
                     clcd_print("Reset the Board",LINE2(0)); 
                     i = 8;
                   }
                }
            }  
        if(attempt == 5)
        {
            if(wait++ == 10)
            {
              wait = 0;
              LED = !LED; 
            }
        }
        else if(attempt == 4)
        {
           if(wait++ == 5)
            {
              wait = 0;
              LED = !LED; 
            }      
        }
        else if(attempt == 3)
        {
           if(wait++ == 4)
            {
              wait = 0;
              LED = !LED; 
            }         
        }
        else if(attempt == 2)
        {
            if(wait++ == 3)
            {
              wait = 0;
              LED = !LED; 
            }        
        }
        else if(attempt == 1)
        {
            if(wait++ == 2)
            {
              wait = 0;
              LED = !LED; 
            }        
        }
        else if(attempt == 0)
        {
           LED = 1;   
        }
      }
    return;
}