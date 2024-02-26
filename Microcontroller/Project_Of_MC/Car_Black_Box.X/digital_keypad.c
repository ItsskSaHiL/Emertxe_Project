/*
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 * */
#include <xc.h>
#include "digital_keypad.h"
//static int count = 0;
static int count=0;

void init_digital_keypad(void)
{
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad(unsigned char mode)
{
    static unsigned char once = 1;
    
    if (mode == LEVEL_DETECTION)
    {
        return KEYPAD_PORT & INPUT_LINES;
    }
    else
    {
        count++;
        if (((KEYPAD_PORT & INPUT_LINES) == SW4) && count > 50)  /* Use For Long press of SW4*/
        {
            count = 0;
            return LPSW4;
        }
        else if (((KEYPAD_PORT & INPUT_LINES) == SW5) && count > 30)  /* Use For Long press of SW5*/
        {
            count = 0;
            return LPSW5;
        }
        else if (((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
        {
            once = 0;
            count = 0;
            return KEYPAD_PORT & INPUT_LINES;
        }
        else if ((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED)
        {
            once = 1;
        }
    }
    
    return ALL_RELEASED;
}



