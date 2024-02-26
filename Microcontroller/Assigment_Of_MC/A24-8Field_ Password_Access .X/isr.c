/*
 * File:   isr.c
 * Author: sk sahil
 *
 * Created on September 14, 2022, 4:28 PM
 */


#include <xc.h>
#include "main.h"
#include "clcd.h"
void __interrupt() isr(void)
{
    unsigned long int count = 0;
    
    if (TMR2IF == 1)
    {
       
        if(count++ == 20000)
        {
            count=0;
            LED = !LED;
            clcd_print(" ",LINE2(4));
        }
        TMR2IF = 0;
    }
}