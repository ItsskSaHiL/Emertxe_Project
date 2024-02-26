/*
  Name : Sk Sahil
  Assigment : A15 - WAP to implement alarm with snooze for given time and date using SIGALRM
  Date of Submission : 12/01/2023
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about signals and signal handling.
	Working of sigaction  and alarm system calls. 
  Objective: 
	To understand signal and time related system calls. 
  Requirements: 
	1. User gives the time and date from command-line arguments.
	2. Validate the time eg: Do not go behind the current time.
	3. Date is an option, if user not providing date consider it as today.
	4. In handler, avoid all user communication(printf, scanf etc) and loops. Make it minimal as possible.
	5. After the alarm expires, display a ALARM message along with date and time.
	6. Prompt the user whether he wants to stop or snooze.
	7. If user selects stop, terminate the program.
	8. If user selects snooze, prompt for snooze time in minutes. If user enters the time, reset the alarm to the entered time in minutes .If user doesn't enter time, default the snooze time to 1 mins
  Sample execution: 
	1. ./alarm (No arguments) 
	Error: No arguments passed
	Usage: ./alarm  [dd/mm/yy] 

	2. ./alarm 30:15 

	Error: Invalid time 

	3. ./alarm 22:10 

	set alarm for 10:10 PM for today 

	4. ./alarm 22:10 02/03/16

	set alarm for 10:10 PM for today 

	5. When alarm occurs 

	Wake­up...Alarm..!! 

	1. Snooze     2. Exit 

	if user select 

	1 Enter snooze time :

	2 

	( After 2 sec above process will repeat until user gives exit)
*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

int stop = 1;
void signal_handler(int signum);
void snooze_or_stop();

int main(int argc, char *argv[])
{
	// variable for vaidate CLA
	int cla_flag;
	// validate the CLA
	if(argc < 2)
	{
		printf("Error: No arguments passed \nUsage: ./alarm 22:39 \nUsage: ./alarm 23:59 [dd/mm/yy]\n");
		exit(1);
	}
	else
	{
		if(argc == 2)
		{
			cla_flag = 1;
		}
		else if(argc == 3)
		{
			cla_flag = 0;
		}
		else
		{
			printf("Error \n");
			return 0;
		}
	}
	// variable decleration
	struct tm new_tm;
	struct tm *cur_tm;
	
	// clear the memory
	memset(&new_tm,0,sizeof(new_tm));
	memset(&cur_tm,0,sizeof(cur_tm)); 	
	
	// store the current time from epoch time
	time_t cur_time = time(NULL);
	
	// validate the date (DD/MM/YY)
	cur_tm = localtime(&cur_time);
	
	if(cla_flag)
	{
		// only date is apssed
		strptime(argv[1],"%H:%M",&new_tm);
		
		// store the date 
		new_tm.tm_mday = cur_tm->tm_mday;
		new_tm.tm_mon = cur_tm->tm_mon;
		new_tm.tm_year = cur_tm->tm_year;
		
		printf("Set Alarm for %d:%d ", new_tm.tm_hour, new_tm.tm_min);
		printf("Date: %d/%d/%d\n", new_tm.tm_mday,new_tm.tm_mon+1, new_tm.tm_year+1900);
	}
	else
	{
		strptime(argv[1],"%H:%M",&new_tm);
		strptime(argv[2],"%d/%m/%Y",&new_tm);
		
		printf("Set Alarm for %d:%d ", new_tm.tm_hour, new_tm.tm_min);
		printf("Date : %d/%d/%d\n", new_tm.tm_mday,new_tm.tm_mon+1, new_tm.tm_year+1900);
	}
	
	// check the error 
	time_t user_time = mktime(&new_tm);
	
	// error check
	if(user_time < cur_time)
	{
		printf("Invalid Input\n");
		exit(2);
	}
	
	// variable for register the signal
	struct sigaction act;
	
	memset(&act,0,sizeof(act));

	act.sa_handler = signal_handler;
	 
	// validate the alarm
	sigaction(SIGALRM,&act,NULL);

	time_t alarm_time = user_time - cur_time;

	// call the alarm signal
	alarm(alarm_time);
	
	while(stop);

	return 0;
}
	
void signal_handler(int signum)
{
	//handle the signal
	if (signum == SIGALRM)
	{
		snooze_or_stop();
	}
}

void snooze_or_stop()
{
		printf("\nWake up...Alarm!!!\n");
		char opt;
		int snz_time;
		printf("Select an option: 1. Snooze\
			  \n                  2. Stop\n");
		scanf("%hhd", &opt);
		switch (opt)
		{
				case 1://Snooze
						printf("Give time in SEC to snooze the alarm: ");
						scanf("%d", &snz_time);
						printf("Alarm snoozed for %d SEC \n", snz_time);
						alarm(snz_time);
						signal(SIGALRM, signal_handler);
						break;
				case 2://Stop
						printf("Alarm stopped!!\n\n");
						stop = 0;
						break;
				default : 
					printf("Pass Valid Option\n");
		}
}	
	

