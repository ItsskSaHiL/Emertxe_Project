/*
 * Name : Sk Sahil 
   Assigment  : to toggle direction of train using digital keypad
 * File:   main.c
 * Date : 26/08/22

 *  */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

static void init_config(void) {
	
	/* Turn off LEDs initially */
	LED_ARRAY1 = 0x00;
	
	/* Configure as Ouput Port */
    	LED_ARRAY1_DDR  = 0x00;

	/* Initialize digital keypad */    	
	init_digital_keypad();
}

void main(void) {

    unsigned char key, flag = 1,flag2 = 1;
    unsigned int delay = 8000;
    unsigned int i = 0,j = 0;
    init_config();

    while(1)
    {

		/* read digitalkeypad value store it in variable called key */
        	key = read_digital_keypad(STATE);
	
		/* remember key  holds value of key when pressed and 0x3f when released */
		
		if (key == SW1)
		{
        	  	/* take flag as variable to toggle the direction for pattern */
			flag = !flag;
            
            LED_ARRAY1 = 0x00;
        }
		
		/* use if loops don't use blocking loops 
		   in blocking codes u cannot detect keys */
				
			
			if (flag)
			{
        			/* Code for left to right pattern */
               if(i < 8)
               {
                 if(delay-- == 0)
                 {
                   delay = 8000;
                   LED_ARRAY1 = LED_ARRAY1 | (1 << i) ;
                   i++;
                 }
              } 
              else if(i >= 8 && i < 16) // Second condition OFF led from top to bottom 
              {
                if(delay-- == 0)
                 {
                 delay = 8000;
                 LED_ARRAY1 = LED_ARRAY1 & ~(1 << (i - 8));
                 i++;
                 }
              }
               if(i == 16)
               {
                   i = 0;
               }
               
			}
			else
			{
				/* Code for right to left pattern */
                 if(j < 8)  //Condition for ON led from bottom to top 
                 {
        
                   if(delay-- == 0)
                    {
                      delay = 8000;
                      LED_ARRAY1 = LED_ARRAY1 | (1 << (7 - j));
                      j++;
                    }
                 }
                else if(j >= 8 && j < 16)  // Condition  for OFF led from bottom to top 
                {
                   if(delay-- == 0)
                     {
                       delay = 8000;
                       LED_ARRAY1 = LED_ARRAY1 & ~(1 << (15 - j));
                       j++;
                     }
                 }
                 if(j == 16)
               {
                   j = 0;
               }
			}
			/* End of loop toggle flag to continue in other direction even key not pressed */
		}
}
     
   
