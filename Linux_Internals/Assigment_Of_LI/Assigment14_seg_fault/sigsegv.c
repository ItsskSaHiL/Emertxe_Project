/*
  Name : Sk Sahil
  Assigment : A14 - WAP to print the address which is causing Segmentation fault
  Date of Submission : 12/01/2023
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about signals and signal handling.
	Working of sigaction system calls. 
  Objective: 
	To understand working of signal handling. 
  Requirements: 
	Write a signal handler function to print address which caused seg-fault(SIGSEGV). 
	Use sigaction system call to register signal. 
	Use struct siginfo from sa_sigaction to print address (Read man page). 
	Create a segmentation fault from code. 
	When error occurs program should print address and exit. 
  Sample execution: 
	 ./sigsegv 

	 Segmentation fault ..!! 

	Address 0x123456 caused error
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum,siginfo_t *siginfo,void *data)
{
	// print the address which cause segmentation fault
	printf("Address %p caused error\n",siginfo->si_addr);
	exit(0);
}



int main()
{
	// variable decleration
	struct sigaction act;
	char *ptr = "Hello";
	
	// store the lower address for segmentation fault
//	ptr =(void*) (long)20;
	
	// clear the memory of structure
	memset(&act,0,sizeof(act));
	
	// store the flag and handler function	
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	
	// register the value
	sigaction(SIGSEGV,&act,NULL);
	
	*ptr = 'w';
	// cause the seg fault
//	printf("%d",*ptr);

	// wait
	pause();

	return 0;
}
