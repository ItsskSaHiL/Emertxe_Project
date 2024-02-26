/* 
 * File:   ssd.c
 */
#include <xc.h>
#include "ssd.h"

void init_ssd(void)
{
    /* Seeting the SSD data line as Output */
    SSD_DATA_PORT_DDR = 0x00;
    
    /* Setting SSD Control Line as Output (RA5 - RA2) */
    SSD_CONTROL_PORT_DDR = SSD_CONTROL_PORT_DDR & 0xC3;
    
    SSD_CONTROL_PORT = SSD_CONTROL_PORT & 0xC3;
}

void display(unsigned char data[])
{
    unsigned char digit;
    
    for (digit = 0; digit < MAX_SSD_CNT; digit++)
    {
        //load the display value to data port
        SSD_DATA_PORT = data[digit];
        //load the control value to control port
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x04 << digit);
        
        for (unsigned int wait = 3000; wait--; );
       
    }
}
void display_mnt(unsigned char data[])
{
    unsigned char digit;
    
    for (digit = 2; digit < MAX_SSD_CNT; digit++)
    {
        //load the display value to data port
        SSD_DATA_PORT = data[digit];
        //load the control value to control port
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x04 << digit);
        
        for (unsigned int wait = 4000; wait--; );
       
    }
}
void display_hour(unsigned char data[])
{
    unsigned char digit;
    
    for (digit = 0; digit < 2; digit++)
    {
        //load the display value to data port
        SSD_DATA_PORT = data[digit];
        //load the control value to control port
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0xC3) | (0x04 << digit);
        
        for (unsigned int wait = 4000; wait--; );
       
    }
}