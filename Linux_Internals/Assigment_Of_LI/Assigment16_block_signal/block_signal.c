/* 
  Name : Sk Sahil
  Assigment : A16 - WAP to block certain signals from being received from command line.
  Date of Submission : 13/01/2023
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’. 
	Good knowledge about signals and signal handling.
	Working of sigaction system call and signal masking. 
  Objective: 
	To understand importance of signal masking. 
  Requirements: 
	1. Write a signal handler function for any signal, say SIGINT .
	2. While its running inside handler (use loop) block other signals(atleast 3) being received . 
	3. Use sa_mask from struct sigaction to set signals to be blocked (Refer man ). 
	4. To create a signal set use variable of sigset_t. 
	5. To add or remove signals from set use sigaddset, sigdelset functions (refer man). 
	6. Process will receive blocked signals once its out from handler. ﻿
  Sample execution: 
	1. ./block_signal
	      Process 2345 waiting for signal.. press ctrl + c from terminal. 
	      SIGINT received  
	Inside handler 
	Inside handler 
	. .
	.....

	2. Now open another terminal and send signal to process using kill command. 
	Bash$ kill ­SIGUSR1 2345 
	Bash$ kill ­SIGTERM 2345 
	Bash$ kill ­SIGABRT 2345 

	3. After exiting from handler will respond to blocked signal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sig_handler(int shmid)
{
	printf("Signal Number : %d \n",shmid);
	
	int i = 5;
	
	while(i > 0)
	{
		printf("I am the handler\n");
		sleep(2);
		i--;
	}
}

int main()
{
	// Variable Decleartion
	struct sigaction act; // for handler
	sigset_t set; // for add signal
	
	// clear the memory of structure
	memset(&act,0,sizeof(act));
	
	// add flags
	//act.sa_flags = SA_SIGINFO;
	
	// add handler function
	act.sa_handler = sig_handler;
		
	// Initilize the signal set
	sigemptyset(&set);
	
	// add the signals
	sigaddset(&set,SIGABRT);
	sigaddset(&set,SIGTERM);
	sigaddset(&set,SIGUSR1);
	sigaddset(&set,SIGSEGV);

	// add those signal to structure
	act.sa_mask = set;
	
	// print the value
	printf("Process %d  waiting for signal.. press ctrl + c from terminal\n",getpid());
	
	// register signal
	sigaction(SIGINT,&act,NULL);
	sigaction(SIGTERM,&act,NULL);
	sigaction(SIGABRT,&act,NULL);
	sigaction(SIGSEGV,&act,NULL);
	sigaction(SIGUSR1,&act,NULL);
	
	while(1);
	
	return 0;
}
