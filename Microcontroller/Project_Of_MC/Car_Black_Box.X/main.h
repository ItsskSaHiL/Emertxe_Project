/* 
 * File:   main.h
 * Name : Sk Sahil
 * Project : Car Black Box
 * Submission Date: 18/10/2022
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include<string.h>

#include"adc.h"
#include"clcd.h"
#include"ds1307.h"
#include"i2c.h"
#include"Car_black_box.h"
#include"digital_keypad.h"
#include"at_24c04.h"
#include"timers.h"
#include"uart.h"

#define DASH_BOARD_FLAG  0x01
#define LOGIN_FLAG       0x02
#define LOGIN_MENU_FLAG  0x03
#define MENU_FLAG        0x04
#define VIEW_LOG_FLAG    0x05
#define CLEAR_LOG_FLAG   0x06
#define RESET_PASSWORD_FLAG 0x07
#define CHANGE_TIME        0x08
#define DOWNLOAD_LOG_FLAG   0x09


#define RESET_PASSWORD   0x10
#define RESET_NOTHING    0x20
#define RESET_LOGIN_MENU 0x30
#define VIEW_LOG_RESET   0x40
#define RESET_MEMORY     0x50
#define RESET_CHANGE_PASSWORD 0x60
#define RESET_DOWNLOAD_FLAG   0x70
#define RESET_TIME_FLAG     0x80

#define RETURN_BACK      0x0A
#define LOGIN_SUCCESS    0x0B
#define RETURN_SUCCESS   0x0C
#define RETURN_FAIL      0x0D


#endif	/* MAIN_H */

