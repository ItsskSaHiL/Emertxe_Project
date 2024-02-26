#include <xc.h>

void init_pwm(void)
{
    /* Set CCP1 as output pin */
    TRISC2 = 0;
    
    /* Load the pulse period in PR2 register for 5kHz signal */
    PR2 = 249;
    
    /* Seting the scale of 1:4 */
    T2CKPS0 = 1;
    T2CKPS1 = 0;
    
    /* Start Timer2 */
    TMR2ON = 1;
    
    /* Setting the PWM Mode */
    CCP1CON = 0x0C;
}

void set_pwm_duty(unsigned char duty)
{
    unsigned int reg_val;
    
    reg_val = ((float) duty / 100) * 250 * 4; 
    
    CCPR1L = reg_val >> 2;        // 8 MSBs   
                                        //00
    CCP1CON = (CCP1CON & 0xCF) | ((reg_val & 0x03) << 4); // 5th and 4th
}
