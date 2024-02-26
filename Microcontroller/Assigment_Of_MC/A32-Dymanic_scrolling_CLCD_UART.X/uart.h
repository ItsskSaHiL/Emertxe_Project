/* 
 * File:   uart.h
 */

#ifndef UART_H
#define	UART_H

#define FOSC                20000000

void init_uart(unsigned long baud);
unsigned char getchar(void);
void putchar(unsigned char data);
void puts(const char *s);
void gets(char *string);

#endif	/* UART_H */