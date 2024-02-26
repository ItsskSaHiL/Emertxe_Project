/*
 * Name : Sk Sahil
 * File:   isr.c
 * Assigment : A09 - Implement a static clock on SSD using internal timer
 * Date : 18/09/2022
 */


#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned long int count1 = 0,count2 = 0;
    
    if (TMR2IF == 1)
    {
        if (++count1 == 10000)
        {
            count1 = 0;
            flag = !flag;
        }
        if(++count2 == 1200000)
        {
            count2 = 0;
            minute++;
        }
        if(minute == 60)
        {
            minute = 0;
            hour++;
        }
        if(hour > 23)
        {
            hour = 0;
        }
        TMR2IF = 0;
    }
}