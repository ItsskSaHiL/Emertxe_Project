/*
 * File:   stdio.c
 * Author: WROST^SAD
 *
 * Created on August 19, 2022, 8:29 PM
 */


#include <stdio.h>

#pragma config WDTE = OFF //Watchdog timer disabled

//static void init_config(void) {
    //Write your initialization code here\\}

void main(void) 
{
    //init_config(); //Calling initializing function
    unsigned char *PORTB = 0x06;
    unsigned char *TRISB = 0x86;
    *PORTB = 0xFF;
    *TRISB = 0x00;

}
