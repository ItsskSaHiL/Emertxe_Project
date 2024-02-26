/*
 * Name : Sk Sahil
 * File:   main.c
 * Assigment : A21 - Implement a Stop Watch with 5 laps
 * Date : 24/09/2022
 * Discription : 
 * Problem Statement:
   Implement a Stopwatch with 5 lap.
Output Requirements:
  As soon as the board is powered up or reset, CLCD display the message shown .
  The Start / Stop Key is used to start the timer.
  The first line shows the current time running as HH:MM:SS:ss.
  The Lap / Reset key should capture the Lap time.
  The latest Lap record should be shown on the second line.
  Should be possible to capture 5 Lap time records max.
  To view the recorded laps you need to stop the timer using Start / Stop Key and Press, Scroll - Up and Down Keys .
  On press of the Lap /Reset Key while the timer is not running, all the timings including the recorded laps should get cleared.
Inputs:
  MKS1 as Start / Stop 
  MKS2 as Lap / Reset 
  MKS3 as Scroll Up 
  MKS4 as Scroll Down 
  Timer


 */

#include <xc.h>
#include "clcd.h"
#include "main.h"
#include "matrix_keypad.h"
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    //initialize clcd
    init_clcd();
    /* set Global Interrupt Enable bit , peripheral interrupt enable bit*/
    PEIE=1;
    
    GIE=1;
}

void main(void) 
{  
    
    // All the initilazition 
    init_config();
    
    init_timer2();
    unsigned long int wait = 0;
    unsigned int key,key_copy;
    static int sw1 = 0,laps = 5,sw2 = 0,sw3 = 0,laps_count = 0,view_flag = 0;
    clcd_print(" Press Switch 1 ",LINE1(0));    
    clcd_print("Srart Stop Watch",LINE2(0));       
    unsigned char watch[]={'0','1','2','3','4','5','6','7','8','9'}; 
    unsigned char cesec[3];
    unsigned char secA[3];
    unsigned char minA[3];
    unsigned char hourA[3];
    cesec[3] = '\0';
    secA[3] = '\0';
    minA[3] = '\0';
    hourA[3] = '\0';
    unsigned char L0[16] = "L0 :   :  :  :  ";
    unsigned char L1[16] = "L1 :   :  :  :  ";
    unsigned char L2[16] = "L2 :   :  :  :  ";
    unsigned char L3[16] = "L3 :   :  :  :  ";
    unsigned char L4[16] = "L4 :   :  :  :  ";
    
    while (1) 
    {
       
       key = read_matrix_keypad(STATE); // Read the keypad 
      
       cesec[0] = watch[csec / 10];
       cesec[1] = watch[csec % 10];
       secA[0] = watch[sec / 10];
       secA[1] = watch[sec % 10];
       minA[0] = watch[minute / 10];
       minA[1] = watch[minute % 10];
       hourA[0] = watch[hour / 10];
       hourA[1] = watch[hour % 10];
       
       if(key != ALL_RELEASED)
        {
           key_copy = key;
           if(key_copy == 1)
           {
             TMR2ON = !sw1;
              sw1 = !sw1;
              clcd_print("                ",LINE2(0));
              if(sw1 == 0)
              {
                view_flag = !view_flag;
              }
           } 
           if(key_copy == 2)
           {
              sw2 = !sw2;
           } 
           if((key_copy == 2) && (sw1 == 0))
           {
               sw1 = 0;
               sw2 = 0;
               TMR2ON = 0;
               hour = 0;
               minute = 0;
               sec = 0;
               csec = 0;
               laps = 5;
               view_flag = 0;
               laps_count = 0;
               clcd_print(" Press Switch 1 ",LINE1(0));    
               clcd_print("Srart Stop Watch",LINE2(0));   
           } 
           if(key_copy == 3)
           {
               laps_count++;
           }
           if(key_copy == 4)
           {
               laps_count--;
           }
        }
       
       if(sw1 && (view_flag == 0))
       {
           clcd_print("SW :   :  :  :  ",LINE1(0)); 
           clcd_print(cesec,LINE1(14));
           clcd_print(secA,LINE1(11));
           clcd_print(minA,LINE1(8));
           clcd_print(hourA,LINE1(5));
           //clcd_print("                ",LINE2(0));
       }
       if(sw1 && sw2)
       {  
           clcd_print(cesec,LINE2(14));
           clcd_print(secA,LINE2(11));
           clcd_print(minA,LINE2(8));
           clcd_print(hourA,LINE2(5));
           if(laps == 5)
           {
           clcd_copy(L0,hourA,minA,secA,cesec);
           clcd_print(L0,LINE2(0));
           }
           if(laps == 4)
           {
           clcd_copy(L1,hourA,minA,secA,cesec);
           clcd_print(L1,LINE2(0));
           }
           if(laps == 3)
           {
           clcd_copy(L2,hourA,minA,secA,cesec);
           clcd_print(L2,LINE2(0));
           }
           if(laps == 2)
           {
           clcd_copy(L3,hourA,minA,secA,cesec);
           clcd_print(L3,LINE2(0));
           }
           if(laps == 1)
           {
           clcd_copy(L4,hourA,minA,secA,cesec);
           clcd_print(L4,LINE2(0));
           laps = 6;
           }
           sw2 = 0;
           laps--;
       }
       if(view_flag)
       {
         if(laps_count == 0)
         {    
             clcd_print("  Stored Laps   ",LINE1(0));
             clcd_print(L0,LINE2(0));
         }     
              
         if(laps_count == 1)
         {
           clcd_print("  Stored Laps   ",LINE1(0));
           clcd_print(L1,LINE2(0));  
         }
         
         if(laps_count == 2)
         {
            clcd_print("  Stored Laps   ",LINE1(0));
            clcd_print(L2,LINE2(0));
         }
         if(laps_count == 3)
         {
             clcd_print("  Stored Laps   ",LINE1(0));
             clcd_print(L3,LINE2(0));
         }    
         if(laps_count == 4)
         {
             clcd_print("  Stored Laps   ",LINE1(0));
             clcd_print(L4,LINE2(0));
         }
       }
    }
    return;
}

