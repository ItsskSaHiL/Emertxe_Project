/*
  Name : Sk Sahil
  Assigment : A17 - WAP to avoid child become zombie by using signal handlers
  Date of Submission : 13/01/2023
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’. 
	Good knowledge about signals and signal handling. 
	Working of sigaction system call. 
  Objective: 
	To understand, how to avoid zombie asynchronously . 
  Requirements: 
 	Write two separate programs for both methods.
 	Method 1 ﻿﻿

	1. Create a child process. 
	2. Write a signal handler function for SIGCHLD to avoid child become zombie (Do man 7 signal for SIGCHLD) . 
	3. Write code inside handler to avoid zombie and print child exit status.﻿ 

	 Method 2

 	1. Create a child process. 
 	2. Use sa_flag from struct sigaction to avoid zombie (Refer man ). 
 	3. Prints the child exit status inside handler.

	Sample execution:  

	1. ./avoid_zombie 
	child  terminated with exit code 0.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

// handler function
void sig_handler(int signum,siginfo_t *siginfo,void *data)
{
	int status;
	int wpid = wait(&status);
					
	//check exit status of child
	if(WIFEXITED(status))
	{
		printf("Child with PID %d terminated with exit code %d \n", wpid, WEXITSTATUS(status));
	}
}	

int main()
{
	// variable declration
	struct sigaction act;
	
	// clear the memory 
	memset(&act,0,sizeof(act));
	
	// add flags and handler func
	act.sa_flags = SA_SIGINFO | SA_NOCLDWAIT;
	act.sa_sigaction = sig_handler;

	// register the signal
	sigaction(SIGCHLD,&act,NULL);
	// make child process
	int pid = fork();
	
	if(pid > 0)
	{
		sleep(4);		
	}
	else if(pid == 0)
	{
		sleep(1);
	}
	else
	{
		perror("fork");
		exit(0);
	}
	
	return 0;	
}
