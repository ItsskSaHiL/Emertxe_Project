/*
 * File:   24c04.c
 * Author: WROST^SAD
 *
 * Created on October 6, 2022, 9:59 AM
 */


#include <xc.h>
#include "i2c.h"
#include "at_24c04.h"

unsigned char read_24c04(unsigned char addr)
{
    unsigned char data;
    
    i2c_wait_for_idle();
    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
   // i2c_write(SLAVE_READ);
    i2c_write(addr);
    i2c_rep_start();
    i2c_write(SLAVE_READ_EE);
    data = i2c_read(0);
    i2c_stop();
    
    return data;
}

void write_24c04(unsigned char addr, unsigned char data) // SEc_ADDR, data
{
    i2c_wait_for_idle();
    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(addr);
    i2c_write(data);
    i2c_stop();
}
