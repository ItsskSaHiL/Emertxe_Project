/*
* Name : Sk Sahil
* Assigment : A07 - WAP to create child process to execute command passed through command line
* Date of Submission : 07/01/2023
* Pre-requisites:-
*	Knowledge about system calls, How to read and understand ‘man pages’.
* 	Good knowledge about processes.
*	Working of fork, wait and exec system calls.
* Objective:
*	To understand how to use exec system calls.
*Requirements:
*	Create child and execute a command passed from command-line arguments.  
*	If no arguments passed print a usage message.
*	In case any wrong command passed, print an error message.
*	After child terminates print the exit status of child process.
* Sample execution: -
*	1. No args passed (Print usage info)
*	./exe_child Usage: ./exe_child args...
*	2. Valid arg. passed
*	./exe_child date
*	This is the CHILD process, with id 11612
*	Wed Apr  4 13:27:19 IST 2012
*	Child exited with status 0


*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>	

int main(int argc,char *argv[])
{
	// validate the CLA
	if(argc < 2)
	{
		printf("Pass the Correct Command : ./a.out <command>\n");
		exit(1);
	}
	
	// variable decleartion 
	char *data[argc];
	int i;
	
	// store the CLA in the array pointer
	for(i = 0;i < (argc - 1) ;i++)
	{
		data[i] = argv[i+1];
	}
	data[i] = NULL;
	
	// crating child process
	int pid = fork();
	
	// for parent
	if(pid)
	{
		//wait for child
		int status;
		
		wait(&status);
		
		if(WIFEXITED(status))
		{
			printf("Child %d exited with status %d \n",pid, WEXITSTATUS(status));
		}
	}
	else
	{
		// print status
		printf("This is the CHILD process with id %d\n",getpid());

		// execute the command
		if(execvp(argv[1], data) < 0)
		{ 
			perror(data[0]);
			exit(1);
		} 
		else
		{
			printf("execvp not executed\n");
		}
	}
		

	return 0;	
}
	
