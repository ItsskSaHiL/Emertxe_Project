/*
 * Name : Sk Sahil 
 * File:   main.c
 * Project : A23 - Implement a temperature sensor node with CLCD display
 * Date : 01/10/2022
 * Discription : 
 Problem Statement:
   Implement a temperature sensor node with CLCD Display .

Output Requirements:
   As soon as the board is powered up or reset, CLCD display the title in the first line.
   In second line, room temperature is displayed with unit .
 Inputs:
    LM35 Temperature Sensor.
 */

#include <xc.h>
#include "clcd.h"
#include "adc.h"
#include <stdlib.h>

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) 
{
    init_clcd();
    init_adc();
}

void main(void) {
    
    
    unsigned int temp,temp2;
    unsigned char arr[4];
    
    init_config();

    while (1) 
    {    
        clcd_print("Temperature : ", LINE1(0));
        temp = (float)read_adc()/6.82; // Read input from ADC and convert into temparature with 10mV change of 1.c
        itoa(arr,temp,10);  // Integer to string 
       // clcd_print("Temp :", LINE2(3));
        clcd_print(arr, LINE2(10));
        clcd_print(".C", LINE2(13));
       // for(int i = 1000;i--; );
    }
    return;
}
