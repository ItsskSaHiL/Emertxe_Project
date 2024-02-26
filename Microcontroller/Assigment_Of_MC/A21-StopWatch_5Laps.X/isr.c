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
    static unsigned long int count = 0;
    
    if (TMR2IF == 1)
    {
        
        if(++count == 200)
        {
            count = 0;
            csec++;
        }
        if(csec == 99)
        {
            csec = 0;
            sec++;
        }
        if(sec == 60)
        {
            sec = 0;
            minute++;
        }
        if(minute == 59)
        {
            minute = 0;
            hour++;
        }
        TMR2IF = 0;
    }
}