/*
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 * 
 */


#include <xc.h>
#include "i2c.h"
#include "at_24c04.h"

unsigned char read_24c04(unsigned char mem_loc)
{
    unsigned char data;
    
    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(mem_loc);
    i2c_rep_start();
    i2c_write(SLAVE_READ_EE);
    data = i2c_read(0);
    i2c_stop();
    
    return data;
}

void write_24c04(unsigned char mem_loc, unsigned char data) // SEc_ADDR, data
{
    //i2c_wait_for_idle();
    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(mem_loc);
    i2c_write(data);
    i2c_stop();
}

void write_str_2404(unsigned char mem_loc, unsigned char *data)
{
    while(*data != '\0')
    {
      write_24c04(mem_loc, *data) ; 
      data++;
      mem_loc++;
    }
}
