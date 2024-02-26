/* 
 * File:   main.h
 * Author: CFT
 *
 * Created on 22 April, 2020, 11:03 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#define LED1                RD0

#define LED_ARRAY1          PORTD
#define LED_ARRAY1_DDR      TRISD

#define ON                  1
#define OFF                 0
unsigned short read_adc(void);
#define  PERIOD             100

#endif	/* MAIN_H */

