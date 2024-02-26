/*
 * Name : Sk Sahil 
 * File:   main.c
 * Assigment : A22- Implement a dynamic scrolling number marquee with rotation control
 * Date : 03/10/2022
 * Discription : 
  Problem Statement:
  
 Implement a dynamic (configurable) scrolling number marquee on CLCD with scroll direction control on a key press .
  
 Output Requirements:

 As soon as the board is powered up or reset, CLCD display the title in the first line In second line, should prompt for feeding user msg. The cursor should be blinking at rate of 0.5Hz (approx non timer implementation) with a default character 0 .Let's call this as preset mode
You should be able to set the required digit with the help of Up / Left or Down / Right Key
 On selection of the required char you should press the Accept Key and move the cursor to the next location.
On entering the required message you could start the Marquee using Start / Stop Key.
 The default direction should be from left to right for first character position, You may change the scroll direction using Up / Left or Down / Right Key
 The Start / Stop Key could be used to Stop the scroll
 One press of the Edit Key any instance the system should enter to Preset Mode
 In preset mode the Backspace Key is used to remove the accepted characters

   Inputs:

Program Cycles for Scroll Frequency
User entered number 
MKS1 as Up (increment in edit mode)/ Left Key(in marquee) 
MKS2 as Down(decrement in edit mode) / Right Key(marquee)
MKS3 as Stop / Start Key
MKS4 as Edit Key 
MKS5 as Accept Key
MKS6 as Backspace Key

 */

#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"
#include <string.h>
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

//Matrix  Keypad 
//key 01 pressed



static void init_config(void)
{
    init_clcd();  // Ini
    init_matrix_keypad();  // Ini
}

void main(void) 
{
    init_config();
    
             
    unsigned char key,temp,key_copy;
    unsigned char message[] = "0               ";
   // unsigned char arr[11];
    static int edit_flag = 1,left_flag = 1,right_flag = 0,scrol_flag = 0;
    static int pos = 0,wait = 0;
    int i;
    
    while (1) 
    {
        key = read_matrix_keypad(STATE); // 0 1 2 3 4 5 6 7 8 9 * #
        if(key != ALL_RELEASED)
        {
            key_copy = key;
        }
       /* For return into Edit mode */
        if(key == 4)
        {
            edit_flag = !edit_flag;
            scrol_flag = !scrol_flag;
            strcpy(message,"0                 ");
            pos = 0;
        }
        
        if(key == 2)
        {
           left_flag = !left_flag;
           right_flag = !right_flag;
        }
        if(key == 1)
        {
            left_flag = !left_flag;
            right_flag = !right_flag;
        }

        if(key == 3)
        {
            scrol_flag = !scrol_flag;
            if(scrol_flag)
            {
              edit_flag = 0;
            }
        }
    
        // Logic given for user input like at first all arry element is not present we add
      if(edit_flag)
      {     
          clcd_print("Enter the Number",LINE1(0));
          clcd_print("Num :           ",LINE2(0));
         /* Use for blink coursor */
          if(wait++ == 2)
          {
              wait = 0;
              clcd_putch(0xFF,LINE2(6+pos));
          }
          // Increment the digit value 
          if(key == 1)
          {
              message[pos]++; 
              if(message[pos] > '9')
              {
                message[pos] = '0';  
              }
              
          }
          // Decrement the digit value 
          if(key == 2)
          {
              message[pos]--; 
              if(message[pos] < '0')
              {
                message[pos] = '9';  
              } 
          }
          // For add new digit
          if(key == 5)
          {
              pos++; 
              message[pos] = '0';  
          }
          // For delete a digit 
          if(key == 6)
          {
              message[pos] = ' '; 
              pos--; 
          }
          clcd_print(message,LINE2(6));
       }
       
        /* Scrol The Number */
      if(scrol_flag) /* Logic for scrolling Left or Right */
       {
          if(left_flag)
          {
            // Right Scrolling 
            clcd_print(" Message Merquee ",LINE1(0));
            
            temp = message[15];
            for(int i = 15;i >= 0; i--)
            {
              message[i] = message[i - 1];
            }
            message[0] = temp;
            clcd_print(message,LINE2(0));
            for(unsigned int j = 2000;j--; );
         }
        if(right_flag)
        {
            //Left Scrolling
            clcd_print(" Message Merquee ",LINE1(0));
            temp = message[0];
            for(int i = 0;i < 16; i++)
            {
                message[i] = message[i + 1];
            }
            message[15] = temp;
            clcd_print(message,LINE2(0));
            for(unsigned int j = 2000;j--; );
        }
      } 
      }
    return;
}
