#include<xc.h>
int tmr_flag;

void init_timer2(void)
{
    //1:1 scaling
    T2CKPS0=0;
    T2CKPS1=0;
    //preload register
    //PR2 = 250;
    //timer2 interrupt enable
    TMR2IE=1;
    TMR2ON=1;
}
