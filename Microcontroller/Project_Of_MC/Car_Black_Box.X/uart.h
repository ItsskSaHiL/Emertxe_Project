/*
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 * 
 */
#ifndef UART_H
#define	UART_H

#define FOSC                20000000

void init_uart(unsigned long baud);
unsigned char getchar(void);
void putchar(unsigned char data);
void puts(const char *s);

#endif	/* UART_H */