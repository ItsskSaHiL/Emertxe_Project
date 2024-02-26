/* 
  Name : Sk Sahil 
  Assigment No : 05
  Assigment Subject : WAP to make zombie process become orphan, print status of each state
	
  Description :
	Create a scenario to make zombie process become orphan, print status of each state.
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about processes, zombie and orphan.
	Working of fork system call.
  Objective:
	To understand different states of a process.
  Requirements: 
	Create a child process and print status that process is running
	After some time print status that process is zombie state
	After some time print zombie process cleared by init.
	To print status use help of /proc//status file.
	For eg: if child pid is 1234, open file /proc/1234/status and print first 3 lines
      		5. If that file is not available means that process is cleared.

  Sample execution:
	1. ./zomb_orph
	A child created with pid 1234
	Name:  ./zomb_orph
	State: S (sleeping)
	Name:  /zomb_orph   (After some time)
	State: Z (zombie)
	Process 1234 cleared by init  (After some time)
  
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
	
int main()
{
	// for storing status
	char path[50];
	
	// for fork return value
	int rett,pid2;
	
	// call fork
	rett = fork();
	
	switch(rett)
	{
		case -1:
			perror("fork()");
			break;
		case 0:
//			printf("I am Child Process \n");
//			printf("My(Child) process ID : %d\n",getpid());
			sleep(2);

			break;
		default :
//			printf("I am Parent Process \n");
//			printf("My(Parent) process ID : %d\n",getpid());
			
			// return value
			printf("A child created with pid %d\n",rett);
				
			// store the file name 
			sprintf(path,"/proc/%d/status",rett);
			
			// open the file in read mode
			int fd = open(path,O_RDONLY);
			
			int i = 0;
			int ret;
			char buff[35];
			
			ret = read(fd,buff,32); // read from ststus file
			write(1,buff,ret);	// write into stdout
					
			sleep(4);
			
			// open the file in read mode
			fd = open(path,O_RDONLY);
			
			ret = read(fd,buff,30); // read from ststus file 
			write(1,buff,ret);      // write into stdout
						
			// call another fork for 2nd child
			pid2 = fork();
			
			if(pid2 > 0)
			{
				// terminate the child process
				return 1;
			}
			else
			{
				// making orphan the first child 
				sleep(4);
					
				// print the exit status
				printf("child %d is terminted by init %d\n",rett,getppid());
			}
	}
			
	

	return 0;	
}

