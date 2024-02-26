#include <xc.h>
#include "uart.h"

void init_uart(unsigned long baud)
{
    /* Setting RC6 and RC7 to work as Serial Port */
    SPEN = 1;
    
    /*high speed baud rate*/
    BRGH = 1;
    
    /*TRANSMISSION enabale bit*/
    TXEN = 1;
    
    /* Continuous Reception Enable Bit */
    CREN = 1;
    
    /* Baud Rate Setting Register */
    SPBRG = (FOSC / (16 * baud)) - 1;
}

unsigned char getchar(void)
{
    /* Wait for the byte to be received */
    while (RCIF != 1)
    {
       continue;
    }
    
    /* Clear the interrupt flag */
    RCIF = 0;
    
    /* Return the data to the caller */
    return RCREG;
}

void putchar(unsigned char data)
{
    /* Transmit the data to the Serial Port */
    TXREG = data;
    
    /* Wait till the transmission is complete */
    do
    {
        continue;
    } while (TXIF != 1);
    
    /* Clear the interrupt flag */
    TXIF = 0;
}

void puts(const char *s)
{
    while (*s)
    {
        putchar(*s++);
    }
}
void gets(char *string)  //Receive a character until carriage return or newline
{

unsigned char i=0,J=0;
do
{
    *(string+i)= getchar();

    J = *(string+i);

    i++;
}
while(J!='\n');

    i++;
    *(string+i) = '\0';
}