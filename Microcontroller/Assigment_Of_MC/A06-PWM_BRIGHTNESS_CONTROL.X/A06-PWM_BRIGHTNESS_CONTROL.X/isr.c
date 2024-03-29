#include <xc.h>

void __interrupt() isr(void)
{
    static unsigned long int count1 = 0, count2 = 0;
    
    if (TMR0IF == 1)
    {
        TMR0 = TMR0 + 8;
        if (++count1 == 15000)
        {
            count1 = 0;
            if(++count2 == 5)
            {
                count2 = 0;
                TMR0IE = 0;
            }
               
        }
        TMR0IF = 0;
    }
}