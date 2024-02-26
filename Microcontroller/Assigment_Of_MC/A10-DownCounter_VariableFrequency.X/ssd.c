/*
 * Name : Sk Sahil 
 * File:   ssd.c
 * Project : A13 - Implement a 4 digit key press counter
 * Date : 09/09/2022
 */

#include <xc.h>
#include "ssd.h"

void init_ssd(void)
{
    /* Seeting the SSD data line as Output */
    SSD_DATA_PORT_DDR = 0x00;
    
    /* Setting SSD Control Line as Output (RA5 - RA2) */
    SSD_CONTROL_PORT_DDR = SSD_CONTROL_PORT_DDR & 0xC3;
    
    /* To turn off all the four SSD */
    SSD_CONTROL_PORT = SSD_CONTROL_PORT & 0xC3;
}

void display(unsigned char data[])
{
    unsigned char digit ;
    
    for (digit = 0; digit < MAX_SSD_CNT; digit++)
    {
        SSD_DATA_PORT = data[digit];
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x04 << digit);
        
       for (unsigned long int wait = 20; wait--; );
    }
}