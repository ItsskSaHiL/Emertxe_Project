/*
 * NAME: Sk Sahil
 * DATE: 7/10/2022
 * Assigment : A31 - Implement a message display using UART and CLCD 
 * Discription : 
 * Problem Statement:
Implement a message display using UART and CLCD.The message typed on the serial application should be displayed on the CLCD.

Output Requirements:
Any message typed on the host system should be shown in a CLCD.
On completion of the first line it should start on the second line.
One full screen the second line should be moved to first line.
Setup required
Host with a serial application (minicom in Linux, Teraterm in Windows).
Baud  rate of 9600, No parity and 8 data bits.
Inputs:

UART.
 */

#include <xc.h>
#include <string.h>
#include "uart.h"
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

extern unsigned char ch;
static void clcd_write(unsigned char byte, unsigned char mode)
{
    CLCD_RS = mode;
    
    CLCD_DATA_PORT = byte & 0xF0;
    CLCD_EN = HI;
    __delay_us(100);
    CLCD_EN = LOW;

    CLCD_DATA_PORT = (byte & 0x0F) << 4;
    CLCD_EN = HI;
    __delay_us(100);
    CLCD_EN = LOW;
    
    __delay_us(4100);
}
static void init_config(void) {

    init_clcd();
    init_uart(9600);
    
    puts("UART CLCD Print\n");
    
    /* Enabling peripheral interrupt */
    PEIE = 1;
    
    /* Enabling global interrupt */
    GIE = 1;
}

void main(void) {
    unsigned long int wait = 0;
    char ch, str[90]="", str1[17]="",str2[17]="";
    unsigned int i = 0, count = 0;
    init_config();

    while (1) 
    {
        gets(str); // function call
        puts(str);
        for(i = 0; i < strlen(str); i++)
        {
            count++;
            if(count > 32)
            {
                count = 17;
               strncpy(str1,"",strlen(str1));
                for(i = 0; i < 16; i++)
                {
                    str1[i] = str2[i];
                }
                strncpy(str2,"",strlen(str2));
                 
            }
            if(count > 16)
            {
                str2[count-17] = str[i];               
            }
            else if(count <= 16)
            {
                str1[count-1] =str[i];
            }
        }
        str1[16] = '\0';
        str2[16] = '\0';
        strncpy(str,"",strlen(str));
        CLEAR_DISP_SCREEN1;
        /*display the result in clcd*/
        clcd_print(str1,LINE1(0));
        clcd_print(str2,LINE2(0));            
    }
    
    return;
}

