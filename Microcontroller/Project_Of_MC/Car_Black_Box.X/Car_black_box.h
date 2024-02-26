/* 
 * File:   Car_black_box.h
 *Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 */

#ifndef CAR_BLACK_BOX_H
#define	CAR_BLACK_BOX_H

void display_dashboard(char event[],unsigned char speed);
void log_car_event(char event[],unsigned char speed);
void clear_screen(void);
char login(unsigned char key,unsigned char reset_flag);
char login_menu(unsigned char key,unsigned char reset_flag);
void view_log(unsigned char key,unsigned char reset_flag);
char clear_log(unsigned char reset_flag);
char change_password (unsigned char key,unsigned char reset_flag);
char download_logs(unsigned char reset_flag);
void change_rtc_time(unsigned char key, unsigned char reset_flag);
void ds1307_on(void);
void ds1307_off(void);

#endif	/* CAR_BLACK_BOX_H */

