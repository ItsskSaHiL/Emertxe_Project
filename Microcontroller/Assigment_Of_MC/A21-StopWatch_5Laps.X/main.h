/* 
 * File:   main.h
 */

#ifndef MAIN_H
#define	MAIN_H

#define _XTAL_FREQ  20000000
unsigned int hour=0,minute=0,sec = 0,flag=0;
unsigned char csec = 0;
static int tmr_flag = 0, dis_flag = 0;
void init_timer2(void);
#endif	/* MAIN_H */

