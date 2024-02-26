/* 
 * File:   main.h
 * Author: Sk Sahil
 *
 * Created on : 26/08/22
 */

#ifndef MAIN_H
#define	MAIN_H

#define OFF              0x00

#define  LED_ARRAY1      PORTD
#define  LED_ARRAY1_DDR  TRISD
void glow_on_press(unsigned char key);
#endif	/* MAIN_H */

