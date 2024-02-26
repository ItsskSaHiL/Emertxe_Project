/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A29 - Implement system sleep and wake up while Interrupt on change
 * Date : 24/09/2022
 * Discription : 
 *  Problem Statement:
     Implement system sleep and wake up while Interrupt on change (Shown in the video).

Output Requirements:
    As soon as the board is powered up or reset, a message (say 1234) should be displayed in SSD.
    A LED is toggled  every second.
    System should go into sleep mode if no activity is detected.
    System should wake up from sleep on detecting interrupt key.
Inputs:
    INT0 as Interrupt to wake.

 */

#include <xc.h>
#include "external_interrupt.h"
#include "main.h"
#include "ssd.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = (LED_ARRAY1_DDR & 0x3F) ;
    
    init_ext_int();
    init_ssd();
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void)
{
    // All initilization
    static int count = 5;
       unsigned long i;
       unsigned char key;
       unsigned char ssd[MAX_SSD_CNT]  = {ONE,TWO,THREE,FOUR};
       init_config();
    
    while (1) 
    {
       
       
       if (count != 0)
        {   
              
             // LED2 will toggle till count becomes 0. After that systems goes to sleep
            if(i++ == 100)
            {
                i = 0;
                LED2 = !LED2;
                count--;
            } 
            /*For print data in SSD*/
            ssd[0] = ONE;
            ssd[1] = TWO;
            ssd[2] = THREE;
            ssd[3] = FOUR;
            display(ssd);
        }
        else
        {
            count = 5;
            
            ssd[0] = 0x00;
            ssd[1] = 0x00;
            ssd[2] = 0x00;
            ssd[3] = 0x00;
            display(ssd);
            /* Put system to sleep. System resumes when interrupt occurs
             * Press a switch to generate interrupt.
             */
            SLEEP();
        }
               
               
    }
    return;
}
