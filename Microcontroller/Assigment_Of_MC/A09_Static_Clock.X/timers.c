/*
 * Name : Sk Sahil
 * File:   timer.c
 * Assigment : A09 - Implement a static clock on SSD using internal timer
 * Date : 18/09/2022
 */

#include<xc.h>

void init_timer2(void)
{
    //1:16 scaling
    T2CKPS0=0;
    T2CKPS1=0;
    //preload register
    PR2=250;
    //timer2 interrupt enable
    TMR2IE=1;
    TMR2ON=1;
}
