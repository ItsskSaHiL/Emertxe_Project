/*
 * File:   main.c
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 * 
 * Description : Here we use all the peripherals of our module like   DIGITAL KEYPAD , TIMER , ADC, CLCD , 
 *               PROTOCOLS (I2C,UART), RTC, CUTECOM , for getting the required result for "Car Black Box". 
 *               
 * Switches :  SW1 : store event(Collution) , increment the time in RTC
 *             SW2 : store event(increment) , decrement the time in RTC
 *             SW3 : store events (decrement)
 *             SW4 : scroll in menu, Enter password ,View Menus,Change password , Return or Enter in Menu screen , Chose field of Change time  
 *             SW5 : scroll in menu, Enter password ,View Menus,Change password , Return or Enter in Menu screen , Chose field of Change time
 *             SW6 : Enter in any menu 
 * 
 * Created on October 5, 2022, 8:38 PM
 */


#include "main.h"

#pragma config WDTE = OFF //Watchdog timer disabled
char *gear[] = {"GN","GR","G1","G2","G3","G4"};  // storing the gear position 
extern unsigned char ch;
extern int event_count;  // storing the value of event maximum 10
extern char name[];
static void init_config(void)
{
    //Write your initialization code here
   init_clcd();
   init_adc();
   init_i2c(1000000);
   init_ds1307();
   init_digital_keypad();
   init_timer2();
   init_uart(9600);
   
   /*Intterupt enabel bits */
   GIE = 1;
   PEIE = 1;
   
  }

void main(void) 
{
    unsigned char control_flag = DASH_BOARD_FLAG, reset_flag; // Dashboard
    unsigned char key,key_level,gr = 0; // For read the key from digital keypad 
    char event[] = {"ON"};  // when we on the peripherals then it shows ON after we use this array for initilize other event
    unsigned char speed = 0,count = 0,pwd_flag = 0,wait = 0;  // use for storing value of ADC ,DELAY,STORING PASSWORD
    char login_menu_pos,sw4_flag = 0;    // use in show the menu
    char d_log[11];
    d_log[10] = '\0'; // use for dwonload flags
    unsigned char add_d;  // use for dwonload flags
    char ee_pos_d;   //use for dwonload flags
       
    init_config(); //Calling initializing function
    
    while (1)
    {
       /* For storing the Password in External EEPROM */
        if(pwd_flag == 0)
        {
            write_str_2404(0,"1010");
            pwd_flag++;
        }
        /* For show the event in CLCD */
        if(count == 0)
        {
            log_car_event(event,speed); //log_car_event(event,speed);// for storing the event in EEPROM
            count++;
        }
        else if(count == 10)    // Maximum 10 event 
        {
            count = 0;
        }
        
        speed = (read_adc() / 10);   // Read from ADC using Ptentiometer for Detecting speed
        /* If the speed is grater  than 99 then its become 99 bcz ADC value is 0 - 1023,
           if 1000 / 10 = 100 , 1010 /10 = 101 like 102, we cant use 3 digit so we fixed this value  */
        if(speed > 99)    
        {
            speed = 99;
        }
        /* Read from digital keypad */
        key = read_digital_keypad(STATE);
        for(int j = 300;j--; ); // Bouncing effect
        
        if(key == SW1 && control_flag == DASH_BOARD_FLAG) // For Collusion 
        {
            strcpy(event,"C ");
            log_car_event(event,speed);
            count++;
        }
        if(key == SW2 && (gr < 6) && control_flag == DASH_BOARD_FLAG ) // Up Gearing  char *gear[] = {"GN","GR","G1","G2","G3","G4"};
        {
           strcpy(event,gear[gr]);
           gr++;
           log_car_event(event,speed);
           count++;
        }
       
        if(key == SW3 && gr > 0) // Down Gearing
        {
            gr--;
            strcpy(event,gear[gr]);
            log_car_event(event,speed);
            count++;
        }
        else if((key == SW4 || key == SW5) && control_flag == DASH_BOARD_FLAG) // going to login screen 
        {
            clear_screen();
            clcd_print("Enter Password :",LINE1(0));
            clcd_write(COURSOR_POSITION,INST_MODE);         // For on the coursor position in line 2 6th position 
            clcd_write(DISP_ON_AND_CURSOR_ON, INST_MODE);
            __delay_us(100);
           control_flag = LOGIN_FLAG;    // Change the control flag and reset flag 
           reset_flag = RESET_PASSWORD;
           TMR2ON = 1;                   // On the timer 2 
        }       
        else if(control_flag == LOGIN_MENU_FLAG && key == SW6)   // For Explore the menu 
        {   
            switch(login_menu_pos)
               {
                case 0:   // For see the logs 
                      clear_screen();
                      clcd_print("   Log :    ",LINE1(0));
                      reset_flag = VIEW_LOG_RESET; 
                      control_flag = VIEW_LOG_FLAG;  
                      break;
                case 1:  // For clear the logs 
                      clear_screen();
                      reset_flag = RESET_MEMORY; 
                      control_flag = CLEAR_LOG_FLAG;  
                       break;
                case 2:    // For Download the logs
                     clear_screen();
                     ch = 'F';
                     if(ch != '\0')
                     {
                        puts("The Logs Are :\n");
                        puts("SL No     TIME     EVENT     SPEED\n");
                         if(event_count == -1)   // If no logs is present 
                           {
                              puts(" No Logs ");
                           }
                          else
                          {
                              for(ee_pos_d = 0;ee_pos_d < event_count;ee_pos_d++)   // Fetch logs from External EEPROM  
                              {
                                  for(int i = 0; i < 10;i++)
                                  {
                                    add_d = ee_pos_d * 10 + 5;    // Address from where we fetch the address  
                                    d_log[i] = read_24c04(add_d + i);  // For storing in an array from EEPROM
                                  }
                                  /*   Use for printing in cute com and clcd */
                                    clcd_print("Downloading ..",LINE1(0));    
                                    puts("  ");
                                    putchar(ee_pos_d + '0');
                                    puts("      ");
                                    putchar(d_log[0]);  
                                    putchar(d_log[1]);
                                    putchar(':');
                                    putchar(d_log[2]);
                                    putchar(d_log[3]);
                                    putchar(':');
                                    clcd_putch(" ",LINE1(12));
                                    putchar(d_log[4]);
                                    putchar(d_log[5]);
                                    puts("       ");
                                    putchar(d_log[6]);
                                    putchar(d_log[7]);
                                    puts("         ");
                                    putchar(d_log[8]);
                                    putchar(d_log[9]);
                                    putchar('\0');
                                    clcd_putch(" ",LINE1(13));
                              }
                              clear_screen();                          // Printing message after successful download
                              clcd_print("Logs Download ",LINE1(2));
                              clcd_print("successfully",LINE2(0)); 
                              __delay_ms(3000);                        
                              puts(" #$ Logs Downloaded $#\n");
                           }
                           ch = '\0';
                     }     
                      /* For Student Name  */
                      putchar('\n');
                      putchar('\n');
                      puts(name);
                    control_flag = LOGIN_MENU_FLAG;
                    reset_flag = RESET_LOGIN_MENU;
                      break;
                case 3:    // For set the RTC time 
                     clear_screen();
                     ds1307_off();   // For off the RTC 
                     reset_flag = RESET_TIME_FLAG;
                     control_flag = CHANGE_TIME;  
                      break;
                case 4:    // For change the password 
                     clear_screen();
                     reset_flag = RESET_CHANGE_PASSWORD; 
                     control_flag = RESET_PASSWORD_FLAG;  
                      break;
               }
              
        }
        else if(((control_flag == VIEW_LOG_FLAG) || (control_flag == CHANGE_TIME)) && key == LPSW5)  // For return in Menu screeen from specific menu 
        {
             
             if(control_flag == CHANGE_TIME)      // If the time change successful then print message and RTC on
             {
                 clear_screen();
                 clcd_print("time change",LINE1(2));
                 clcd_print("successfully",LINE2(0));
                 __delay_ms(3000);
                 clear_screen();
                 ds1307_on();     // RTC again on 
                 control_flag = LOGIN_MENU_FLAG;  
             }
             else
             {
               clear_screen();    // For other menus 
               control_flag = LOGIN_MENU_FLAG;  
             }
        }
        else if ( key == LPSW4 && control_flag == LOGIN_MENU_FLAG )   // Return from menu screen to dashboard screen  
        {
                control_flag = DASH_BOARD_FLAG;
                clear_screen();
        }
       
        /* Operation done here for every screen  */
        switch(control_flag)
        {
            case DASH_BOARD_FLAG:  
                    display_dashboard(event,speed);/* For displaying The DashBoard */
                    break;
            case LOGIN_FLAG:                       /* For password Screen */
                     switch(login(key,reset_flag))
                     {
                         case RETURN_BACK:         // If not match then return back to the Dashboard Screen 
                             clear_screen();
                             control_flag = DASH_BOARD_FLAG;
                             TMR2ON = 0;    
                             clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
                            __delay_us(100);
                             break;
                        case LOGIN_SUCCESS:           // If match then set condition to open the Menu screen  
                             control_flag = LOGIN_MENU_FLAG;
                             reset_flag = RESET_LOGIN_MENU;
                             TMR2ON = 0;
                             clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
                            __delay_us(100);
                            continue;
                             break;
                     }
                    break;
            case LOGIN_MENU_FLAG:    /* Going to the Menu screen  */
                  login_menu_pos = login_menu(key,reset_flag);   // Returning the Menu position 
                  break;
            case VIEW_LOG_FLAG:      /* For shows the storing logs */
                  view_log(key,reset_flag);
                  break;
            case CLEAR_LOG_FLAG :   // For clearing the EEPROM (logs clear)
                if(clear_log(reset_flag) == RETURN_SUCCESS)
                {
                    clear_screen();
                    control_flag = LOGIN_MENU_FLAG;
                    reset_flag = RESET_LOGIN_MENU;
                   continue;  
                }
                break;
            case CHANGE_TIME:    // For special user change the time 
                clcd_print("Change the Time",LINE1(1));
                change_rtc_time(key,reset_flag) ;
                break;
            case RESET_PASSWORD_FLAG:   // For Special user change the Password
                if(change_password (key, reset_flag) == RETURN_SUCCESS)
                {
                     clear_screen();
                     clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
                     __delay_us(100);
                    control_flag = LOGIN_MENU_FLAG;
                    reset_flag = RESET_LOGIN_MENU;
                   continue;  
                }
                break;  
        }
        reset_flag = RESET_NOTHING;
    }

}
