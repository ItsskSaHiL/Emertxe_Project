/* 
  Name : Sk Sahil 
  Assigment No : 06
  Assigment Subject : WAP to avoid child becoming zombie without blocking parent
  
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about processes & zombie process.
	Working of fork & wait system call.
  Objective:
	To understand different states of a process.
  Requirements: 
	Create a child process avoid it become a zombie.
	To avoid zombie we need to call wait(), but this block parent until child terminates.
	So we need to use waitpid() with proper arguments (Read man page). 
	When child is working parent has to continuously print some message.
	When ever child terminates parent has to print child terminated and print exit status of child process
  Sample execution:
	./nonblock_wait
	A child created with pid 1234
	parent is running
	parent is running
	parent is running . .
	............................
	Child 1234 terminated normally with exit status 0 parent terminating

  Date of submission : 31/12/2022
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	// declearing status variable
	int status;
		
	// ctrating the child process
	int pid = fork();
		
	// for the parent process
	if(pid)
	{
		// status finding
	//	wait(&status);
	
		// printing the status for child
		printf("A child created with pid %d\n",pid);
	
		// using loop and waitpid function for 
		while(waitpid(pid,NULL,WNOHANG) == 0)
		{
			printf("Parent is Running\n");
		}
		
		// print the exit status for child
		printf("Child %d terminated normally with exit status %d parent terminating\n",pid,getppid());
	}
	else
	{
		// using sleep 
		sleep(2);
	}
	
	
	return 0;
}
