/*
 * File:   isr.c
 * Author: sk sahil
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
        if(++count2 == 20000)
        {
            count2 = 0;
            sec--;
        }
        if(sec == 0)
        {
            sec = 59;
            min--;
        }
        
        
        
        TMR2IF = 0;
    }
}