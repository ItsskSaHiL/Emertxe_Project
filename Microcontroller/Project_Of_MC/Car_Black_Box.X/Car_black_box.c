/*
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
  */


#include "main.h"
unsigned char clock_reg[3];
char time[7];  // "HH:MM:SS"
char pwd[] = "1010";  // For soring the password
char log[11];         // For Storing the logs in EEPROM
int pos = -1,event_count;  // For calculate every event 
extern unsigned short sec;  //
char return_time = 3;       // Using for Password screen return in 3 second 
char *menu[] = {"View log","Clear log","Download log","Set time","Change passwd"};  //  Menu we use 
extern unsigned char ch;


/* For geating time from RTC and store in the global array time */
void get_time(void)     
 {
    clock_reg[0] = read_ds1307(HOUR_ADDR); // HH -> BCD 
    clock_reg[1] = read_ds1307(MIN_ADDR); // MM -> BCD 
    clock_reg[2] = read_ds1307(SEC_ADDR); // SS -> BCD 
    
    time[0] = ((clock_reg[0] >> 4) & 0x03) + '0';
    time[1] = (clock_reg[0] & 0x0F) + '0';
    
    // MM 
    time[2] = ((clock_reg[1] >> 4) & 0x07) + '0';
    time[3] = (clock_reg[1] & 0x0F) + '0';
    
    // SS
    time[4] = ((clock_reg[2] >> 4) & 0x07) + '0';
    time[5] = (clock_reg[2] & 0x0F) + '0';
    time[6] = '\0';
 }
/* For Display the time in CLCD */
void display_time(void)
{
    get_time(); // Get time 
        
    clcd_putch(time[0], LINE2(1)); 
    clcd_putch(time[1], LINE2(2)); 
    clcd_putch(':', LINE2(3)); 
    clcd_putch(time[2], LINE2(4)); 
    clcd_putch(time[3], LINE2(5)); 
    clcd_putch(':', LINE2(6)); 
    clcd_putch(time[4], LINE2(7));
    clcd_putch(time[5], LINE2(8)); 
    
}

/* For DIsplay the Dashboard Screen */
void display_dashboard(char event[],unsigned char speed)
{
    clcd_print("  TIME    Ev  SP",LINE1(0));
    display_time();   // Function Call
    clcd_print(event,LINE2(10)); // Show  the events ON GN GR G1 G2 G3 G4 C 
    clcd_putch((speed / 10) + '0',LINE2(14));  // For showing speed in clcd 
    clcd_putch((speed % 10) + '0',LINE2(15));
    
 }
/*  For display the Login (Passwird) Screen */
char login(unsigned char key,unsigned char reset_flag)
{
    static unsigned char npassword[4],spassword[4];  // For storing the user input password and fetch from the External EEPROM
    static char attempts_rem = 3,i;  // Minimum three attempt given for correct Password given 
    
    if(reset_flag == RESET_PASSWORD)
    { 
        attempts_rem = 3;    /* for initilize every things which required */
        npassword[0] = '\0';
        npassword[1] = '\0';
        npassword[2] = '\0';
        npassword[3] = '\0';
        i = 0;
        key = 0xFF;
        return_time = 3;
    }
    
    if(key == SW4 && i < 4)   /* If we press SW4 then it can store 1 */
    {
        npassword[i] = '1';
        i++;
        clcd_putch('*',LINE2(6+i));
        return_time = 3;  // Every key press get 3 fresh second
    }
   if(key == SW5 && i < 4)    /* If we press SW5 then it can store 1 */
   {
       npassword[i] = '0';
       i++;
       clcd_putch('*',LINE2(6+i));
       return_time = 3;  // Every key press get 3 fresh second
   }
    if(return_time == 0)
    {
        return RETURN_BACK;   /* After 3 sec it back to the dasoard screen */ 
    }
    
    /*Check for password wrong or not*/
    if(i == 4)
    { 
        /* Copy PAssword from EEPROM */
        for(int j=0;j<4;j++)
        {
          spassword[j] = read_24c04(j);  
        }
        /* Compare Password */
        if(strncmp(npassword,spassword,4) == 0)
        {
           return LOGIN_SUCCESS ; // Menu screen
        }
        else
        {
            attempts_rem--; // DEcrement The attempts
            if(attempts_rem == 0)
            {
               sec = 900;// Lock for 15 min  (900 sec)
               clear_screen();
               clcd_print("You are blocked",LINE1(0));
               clcd_print("Wait for..   sec",LINE2(0));
               clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
               __delay_us(100);
               while(sec)
               {
                   clcd_putch((sec/100) + '0',LINE2(10));      /* Show the time which user shows */
                   clcd_putch(((sec/10)%10) + '0',LINE2(11));
                   clcd_putch((sec%10) + '0',LINE2(12));
               }   
               attempts_rem = 3;   // Return the Fresh 3 Attempt 
            }
            else
            {
                clear_screen();
                clcd_print("Wrong Password",LINE1(0));    // For Geving wrong password 
                clcd_putch(attempts_rem + '0',LINE2(0));
                clcd_print("Attempts Rem ",LINE2(3));
                __delay_ms(3000);
            }
            clear_screen();
            clcd_print("Enter Password :",LINE1(0));
            i = 0;
            return_time = 3; // Every key press get 3 fresh second
            clcd_write(COURSOR_POSITION,INST_MODE);
            clcd_write(DISP_ON_AND_CURSOR_ON, INST_MODE);
            __delay_us(100);
        }
        
    }
    return 0xFF;
}
/* Storing the logs in EXTERNAL EEPROM */
void log_event(void)
{
    char addr = 5; // Sorig from address 5 
    pos++;        
    if(pos == 10)
    {
        pos = 0;
    }
    addr = pos * 10 + 5;   // Need 10 byte to store every logs 
    
    for(int i = 0; log[i] != '\0';i++)
    {
      write_24c04(addr,log[i]);  // Storing the logs 
      addr++;
    }
    /* Here we monitor the no of Event */
    if(event_count < 10)
    {
        event_count++;
    }
}
/*  Fetch the logs and store in EEPROM */
void log_car_event(char event[],unsigned char speed)
{
    get_time(); // Fetch time 
    strncpy(log,time,6); //HHMMSS Store time 
    strncpy(&log[6],event,2);  // Store Event
    log[8] = (speed / 10) + '0';  // Store speed 
    log[9] = (speed % 10) + '0';
    log[10] = '\0';
    log_event();   // Sore in EEPROM 
}

/*  For clear the screen */
void clear_screen(void)
{
     clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}
/* Menu Screen and Scroll Between every menu */
char login_menu(unsigned char key,unsigned char reset_flag)
{
   static char menu_pos;
   if(reset_flag == RESET_LOGIN_MENU)
   {
       menu_pos = 0;
       clear_screen(); 
   }
   if(key == SW5 && menu_pos <= 3)   // Increment the menu position 
   {
       menu_pos++;
       clear_screen();
   }
   if(key == SW4 && menu_pos > 0)   // Decrement the menu position 
   {
       menu_pos--;
       clear_screen();
   }
   if(menu_pos < 4)      // Print the menu 
   {
       clcd_putch('*',LINE1(0));
     clcd_print(menu[menu_pos],LINE1(2));
     clcd_print(menu[menu_pos+1],LINE2(2));
   }
   else if(menu_pos == 4)
   {
     clcd_print(menu[menu_pos - 1],LINE1(2));
     clcd_print(menu[menu_pos],LINE2(2));  
       clcd_putch('*',LINE2(0));  // At the end of the menu * reqireq for show  selected the menu  
   }
   return menu_pos;    // Return the menu position 
}
/* Inside the view log mwnu */
void view_log(unsigned char key,unsigned char reset_flag)
{
    char v_log[11];   // Initilize all the required members 
    unsigned char add;
    static char ee_pos;
    if(event_count == -1)
    {
        clcd_print(" No Logs ",LINE2(5));   // If no logs present 
    }
    else
    {
        if(reset_flag == VIEW_LOG_RESET)
        {
            ee_pos = 0;
        }
        if(key == SW4 && ee_pos < (event_count - 1) )   // Increment the view log position till the event count 
        {
            ee_pos++;
            
        }
        else if(key == SW5 && ee_pos > 0)     // Decrement the view log position
        {
            ee_pos--;
        }
        for(int i = 0; i < 10;i++)       // Read 10 byte from the External EEPROM 
        {
            add = ee_pos * 10 + 5;
            v_log[i] = read_24c04(add + i);
        }
        //Print view log 
        clcd_putch(ee_pos%10 + '0',LINE2(0));
        
        clcd_putch(v_log[0],LINE2(2));
        clcd_putch(v_log[1],LINE2(3));
        clcd_putch(':',LINE2(4));
        
        clcd_putch(v_log[2],LINE2(5));
        clcd_putch(v_log[3],LINE2(6));
        clcd_putch(':',LINE2(7));
        clcd_putch(v_log[4],LINE2(8));
        clcd_putch(v_log[5],LINE2(9));
        
        clcd_putch(v_log[6],LINE2(11));
        clcd_putch(v_log[7],LINE2(12));
        
        clcd_putch(v_log[8],LINE2(14));
        clcd_putch(v_log[9],LINE2(15));
      }
}
/* For clearing the logs */
char clear_log(unsigned char reset_flag)
{
    if(reset_flag == RESET_MEMORY)
    {
        event_count = -1;     // Set this value 
        pos = -1;
        clcd_print(" Logs Cleared",LINE1(1)); // Print Success message 
        clcd_print(" Successfully ",LINE2(1));
        __delay_ms(3000);
        return RETURN_SUCCESS;
    }
    return RETURN_FAIL;
}

char change_password (unsigned char key,unsigned char reset_flag)
{
    
    static char pwd[9];          // Initilize the Array 
    static int pos,once,i;
    
    if(reset_flag == RESET_PASSWORD_FLAG)
    {
        pos = 0;
        once = 1;
        i = 0;
    }
    if(pos < 4)
    {
       clcd_print("Enter New PWD ",LINE1(0));   
    }
    
    if(pos < 4 && once)         // When we enter the new password 
    {
         once = 0;                              
        clcd_write(COURSOR_POSITION,INST_MODE);
        clcd_write(DISP_ON_AND_CURSOR_ON, INST_MODE);
        __delay_us(100);
    }
    else if(pos >= 4 && (once == 0))   // For re-entering the password 
    {
        once = 1;
        clear_screen();
        clcd_print("Re-Enter New PWD",LINE1(0));
        clcd_write(COURSOR_POSITION,INST_MODE);
        clcd_write(DISP_ON_AND_CURSOR_ON, INST_MODE);
        __delay_us(100);
    }
    
    if(key == SW4)           // SW4 == 1 
    {
        pwd[pos] = '1';
        clcd_putch('*',LINE2(6+i));
        i++;
        pos++;
    }
    else if(key == SW5)     // SW5 == 0 
    {
        pwd[pos] = '0';
        clcd_putch('*',LINE2(6+i));
        i++;
        pos++; 
    }
    
    if(pos == 8)       // when the both paassword enter then 
    {
        if(strncmp(pwd,&pwd[4],4) == 0)     // Compare the Entered password
        {
            for(int i = 0; i < 4; i++)
            {
                write_24c04(i,pwd[i]);       // When matched then store in EEPROM External 
            }
            clear_screen();                  // Show the success message 
            clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
           __delay_us(100);
           clcd_print("Password change",LINE1(1));
           clcd_print(" Successfully ",LINE2(1));
           __delay_ms(3000);
           pos = 0;
           return RETURN_SUCCESS;
        }
        else
       {
         clear_screen();               // If not matched then Show the Failed messahe 
         clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
         __delay_us(100);
         clcd_print("Password change",LINE1(1));
         clcd_print(" Failed !! ",LINE2(1));
        __delay_ms(3000);
           
             return RETURN_SUCCESS;  
      }
  }
    return 0xFF;
}

/* Change the RTC value By user */
void change_rtc_time(unsigned char key, unsigned char reset_flag)
{
    static char time_count = 0,wait = 0;
    char dummy;
    char hour = (time[0] & 0x0F ) * 10 + (time[1] & 0x0F),     /* Store the value from the RTC register */
          min = (time[2]  & 0x0F ) * 10 + (time[3] & 0x0F),
          sec = (time[4] & 0x0F ) * 10 + (time[5] & 0x0F);
    
    
    if(key == SW4 && time_count < 3)
    {
        time_count++;                 // For change the position like  HH : MM : SS 
    }
    if(key == SW5 && time_count > 0)
    {
        time_count--;                 // For change the position like  HH : MM : SS 
    }
    
    if(time_count == 0)
    {
        if(key == SW1)
        {
            hour++;                    /* For increment the hour value  */ 
            if(hour > 23)
            {
                hour = 0;
            }
        }
        if(key == SW2)
        { 
            hour--;                 // For Decremt the hour value 
            if(hour < 0)
            {
                hour = 0;
            }
        }
       dummy = ((hour / 10 ) << 4 ) | (hour % 10) ;            // For storing the hour value in RTC HOUR register in 24 Hour format
       clock_reg[0] = (clock_reg[0] & 0xc0) | dummy ;
	   write_ds1307(HOUR_ADDR, clock_reg[0] );  
     }
    else if(time_count == 1)
    {
        if(key == SW1)
        { 
            min++;                           // For Increment the min position
            if(min > 59)
            {
                min = 0;
            }
        }
        if(key == SW2)
        { 
            min--;                         // For Decrement the min poition 
            if(min < 0)
            {
                min = 59;
            }
        }
        dummy = ((min / 10 ) << 4 ) | min % 10 ;        // For storing the min value in MIN register in RTC 
		clock_reg[1] = (clock_reg[1] & 0x80) | dummy;
		write_ds1307(MIN_ADDR, clock_reg[1] );
     }
    else if(time_count == 2)
    {
        if(key == SW1)
        {
            sec++;                     // Increment the second  position 
            if(sec > 59)
            {
                sec = 0;
            }
        }
        if(key == SW2)
        { 
            sec--;                       // Decrement the Second Position 
            if(sec < 0)
            {
                sec = 59;
            }
        }
        
        dummy = ((sec / 10 ) << 4 ) | sec % 10 ;        // Storing the values of second in RTC SEC Register 
		clock_reg[2] = (clock_reg[2] & 0x80) | dummy;
		write_ds1307(SEC_ADDR, clock_reg[2] );
    }   
    switch( time_count )                             // For BLINKIN the required Position 
    {
      case 0:
		clcd_print("  ",LINE2(3));
		break;
	  case 1:
		clcd_print("  ",LINE2(6));
		break;
      case 2:
		clcd_print("  ",LINE2(9));
		break;
	}
    get_time();                    // For display the time in CLCD 
    
    clcd_putch(time[0], LINE2(3)); 
    clcd_putch(time[1], LINE2(4)); 
    clcd_putch(':', LINE2(5)); 
    clcd_putch(time[2], LINE2(6)); 
    clcd_putch(time[3], LINE2(7)); 
    clcd_putch(':', LINE2(8)); 
    clcd_putch(time[4], LINE2(9));
    clcd_putch(time[5], LINE2(10)); 
}
/* For OFF the RTC */
void ds1307_off(void)
{
    unsigned char dummy_off;
   
    dummy_off = read_ds1307(SEC_ADDR);
    dummy_off = dummy_off | 0x80;
    write_ds1307(SEC_ADDR, dummy_off);// ch = 1
}
/* For on the RTC */
void ds1307_on(void)
{
    unsigned char dummy_on;
   
    dummy_on = read_ds1307(SEC_ADDR);
    dummy_on = dummy_on & 0x7F;
    write_ds1307(SEC_ADDR, dummy_on);// ch = 0
}

char name[] = "Hello It's  Sahil Project : \n";

