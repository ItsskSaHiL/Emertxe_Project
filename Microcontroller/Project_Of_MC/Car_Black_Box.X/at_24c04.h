/*
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 * */

#ifndef at_24c04_H
#define	at_24c04_H


#define SLAVE_WRITE_EE            0b10100000 // 0xA0
#define SLAVE_READ_EE             0b10100001 // 0xA1

void i2c_wait_for_idle(void);
unsigned char read_24c04(unsigned char addr);
void write_24c04(unsigned char addr, unsigned char data);
void write_str_2404(unsigned char mem_loc, unsigned char *data);

#endif	/* 24C04_H */

