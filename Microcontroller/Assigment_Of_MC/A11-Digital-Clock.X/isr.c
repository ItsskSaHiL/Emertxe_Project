/*
 * File:   isr.c
 * Author: Sk Sahil
 *
 * Created on September 14, 2022, 4:28 PM
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