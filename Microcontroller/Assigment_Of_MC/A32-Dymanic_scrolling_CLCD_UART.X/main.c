/*
 * NAME: Sk Sahil
 * DATE: 7/10/2022
 * Assigment : A32 - Implement a dynamic scrolling message marquee with scroll control
 * 
 * Discription :
 *  
 *  Problem Statement:
Implement a dynamic scrolling message marquee (10 Chars) with scroll direction control.

Output Requirements:
As soon as the board is powered up or reste, system is scroll the a static message.
The scroll rate should be 0.5 HZs (approx, non time implementation) .
On press of the '#' key on host keyboard, target to should start accepting the new message from the user.
On the press of ?#? key for the second time, message should start the scroll on the left direction.
You may change the scroll direction using Left or Right Key.
The Start / Stop Key could be used to Stop the scroll.
The scroll should continue from the same instance on detecting the above keys.
Setup required
Host with a serial application (minicom in Linux, Teraterm in Windows).
Baud  rate of 9600, No parity and 8 data bits.
Inputs:
User entered message via Serial Port
DKS 1 as Left Key
DKS 2 as Right Key
DKS 3 as Stop Key

 */

#include <xc.h>
#include <string.h>
#include "uart.h"
#include "clcd.h"
#include"digital_keypad_1.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

extern unsigned char ch;

static void init_config(void)
{
    
    init_clcd();
    init_uart(9600);
    init_digital_keypad();
    
    
    puts("UART CLCD Scrolling Marquee\n");
    
    /* Enabling peripheral interrupt */
    PEIE = 1;
    
    /* Enabling global interrupt */
    GIE = 1;
}

void main(void)
{
    unsigned char key,key_copy = ALL_RELEASED;
    char message[] = "CLCD_Demo_Code_for",ch;
    static char scrol_flag = 1,msg_flag = 0;
    char temp;
    int len = strlen(message),i = 0;    
    
    init_config();

    while (1) 
    {
          key = read_digital_keypad(STATE); // For reading the key;
        
          if(key != ALL_RELEASED)
          {
              key_copy = key;
          }
          /* Use for get the user input and Scrolling continue */
           if(msg_flag)
          {
              clcd_print("Enter input Msg",LINE1(0));
              clcd_print("Pass Min 16 Char",LINE2(0));
             
              if(RCREG != '\0')
              {
                msg_flag = !msg_flag;  
                gets(message);  // Get the Steing from user 
                puts(message);  // Print in cutecom
              }
          }
          
          /* Get the First charecter For user input */
          if (RCREG == '#')
          {
              clear_screen(); 
              if(msg_flag == 0 && scrol_flag == 0)
               {
                  scrol_flag = !scrol_flag;
               }
              else if(msg_flag == 0 && scrol_flag == 1)
               {
                 scrol_flag = !scrol_flag;
                 msg_flag = !msg_flag;
               }
              RCREG == '\0';
          }
          if(key == SW3)   // For Stop the scrolling 
          {
              if(scrol_flag == 1)
              {
                 clear_screen();
                 scrol_flag = 0;
              }
              else
              {
                  key_copy = ALL_RELEASED;
                  scrol_flag = 1;
              }
          }
       /* For Scrol in clcd */   
        if(scrol_flag)
        {
            if(key_copy == ALL_RELEASED)
            {
               // Right Scrolling 
               clcd_print(">Right Scrolling ",LINE1(0));
               temp = message[len - 1];
               for(int i = (len - 1);i > 0; i--)
               {
                  message[i] = message[i - 1];
               }
               message[0] = temp;
               clcd_print(message,LINE2(0));
               for(unsigned int j = 2000;j--; );
            }
            else if(key_copy == SW2)
            {
               // Right Scrolling 
               clcd_print(">Right Scrolling ",LINE1(0));
               temp = message[len - 1];
               for(int i = (len - 1);i > 0; i--)
               {
                  message[i] = message[i - 1];
               }
               message[0] = temp;
               clcd_print(message,LINE2(0));
               for(unsigned int j = 2000;j--; );
            }
            else if(key_copy == SW1)
            {
                 //Left Scrolling
                clcd_print("<Left Scrolling ",LINE1(0));
                temp = message[0];
                for(int i = 0;i < len; i++)
                {
                  message[i] = message[i + 1];
                }
                message[len - 1] = temp;
                clcd_print(message,LINE2(0));
                for(unsigned int j = 2000;j--; );  
            }
        }
        else if((key_copy == SW3) && (scrol_flag == 0))   // For Stop the Scroll 
        {
           clcd_print("Stop Scroll ->",LINE1(1)); 
        }  
          
    }
    
    return;
}

