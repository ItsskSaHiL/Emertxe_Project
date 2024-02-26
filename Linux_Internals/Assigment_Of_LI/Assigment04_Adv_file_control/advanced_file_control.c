/*
* Name : Sk Sahil
* Assigment : A04 - WAP to understand advanced file control system calls
* Date of Submission : 07/01/2023
* Pre-requisites:
*	Knowledge about system calls, How to read and understand ‘man pages’.
*	Command line arguments, File operation system calls (open, read, write, close ...etc)
*	Working of fcntl system calls.
* Objective:
*	To understand and implement using advanced system calls.
*	Understand the need of file synchronization between processes.
* Requirements:
*	Using fcntl system call synchronize a file between two processes (parent and child process).
*	Pass the file name using command-line arguments.
*	Before writing to file check file is locked, in case it is locked must wait the process until its unlocked.
*	If its unlocked, lock file and continue with writing.
*	Both process will do the same procedure.
* Sample Execution:
*	1.When no arguments are passed
*	./a.out
*	Insufficient arguments
*	Usage:- ./a.out filename
*	2. ./a.out f1.txt
*	PARENT PROCESS: locked file
*	PARENT PROCESS: writing to file f1.txt
*	PARENT PROCESS: unlocked file
*	CHILD PROCESS: locked file
*	CHILD PROCESS: writing to file f1.txt
*	CHILD PROCESS: unlocked file

Note : Parent will perform some task Ex: Print prime numbers upto 15
Child may perform another task Ex : Print Fibonacci series upto 10
These things should be present in the file


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>	

void prime_number(char *arr);
void fibonacci_series(char *arr);

int main(int argc, char **argv)
{
	//check argument
	if (argc < 2)
	{
		printf(" No args passed (Print usage info)\n ./a.out <File Name>\n");	
		return 0;
	}
	
	// variable decleartion
	int fd;

	// if the file not present in current directory creat it if present the truncted
	fd = open(argv[1],O_CREAT | O_EXCL | O_WRONLY, 0664);
	
	// error check
	if(fd == -1)
	{
		if(errno == EEXIST)
		{
			fd = open(argv[1],O_TRUNC | O_WRONLY, 0664);	
		}
		else
		{
			exit(1);
		}
	}	
	
	
	// variable for lock and unlock the file
	struct flock st;
	memset(&st,0,sizeof(st)); // clear the memory
	
	// creat the child process
	int pid = fork();
	
	if(pid > 0)
	{
		// lock the file for writing
		st.l_type = F_WRLCK;
		
		printf("PARENT PROCESS: locked file\n");
		
		// call the system call
		if(fcntl(fd, F_SETLKW,&st) == -1)
		{
			perror("fcntl");
			exit(1);
		}
		
		char buff[100] = "The Prime Number upto 15 : ";
		
		prime_number(buff);

		printf("PARENT PROCESS: writing to file %s\n",argv[1]);
	
		write(fd,buff,strlen(buff));
		
		// lock the file for writing
                st.l_type = F_UNLCK;
		
		printf("PARENT PROCESS: uncked file\n");

	        // call the system call
                if(fcntl(fd, F_SETLKW,&st) == -1)	 
		{
			perror("fcntl");
			exit(1);
		}
	}
	else
	{
		// lock the file for writing
		st.l_type = F_WRLCK;
		
		printf("CHILD PROCESS: locked file\n");

		// call the system call
		if(fcntl(fd, F_SETLKW,&st) == -1)
		{
			perror("fcntl");
			exit(1);
		}
		
		char buf[100] = "Fibonacci Series upto 10 : ";
		
		fibonacci_series(buf);

		printf("CHILD PROCESS: writing to file %s\n",argv[1]);

		write(fd,buf,strlen(buf));
		
		// lock the file for writing
                st.l_type = F_UNLCK;

		printf("CHILD PROCESS: unlocked file\n");

	        // call the system call
                if(fcntl(fd, F_SETLKW,&st) == -1)	 
		{
			perror("fcntl");
			exit(1);
		}
	}

	return 0;	
}


void prime_number(char *arr)
{
	//variable decleration
	int str_len, num,i,count = 0;
	
	str_len = strlen(arr);
	
	for(num = 1;num<= 15;num++)
	{
      		count = 0;
      		for(i=2;i<=num/2;i++)
		{
      			if(num%i==0)
			{
           			count++;
         			break;
      			}
   		}	
   		if(count==0 && num!= 1)
		{
			char buff[3];
      			//itoa(num,buff,10);
			sprintf(buff,"%d ",num);
			for(int j = 0;j < strlen(buff);j++)
			{
				arr[str_len] = buff[j];
				str_len++;
			}
		}
   	}	
	
	arr[str_len++] = '\n';
	arr[str_len] = '\0';
	
	
}
	
	
void fibonacci_series(char *arr)
{
	// variable declration
	int n1 = 0;
	int n2 = 1;
	int next_term = n1+n2;
	
	int str_len = strlen(arr);
	
	char buff[6];
	
	sprintf(buff,"%d %d ",n1,n2);
        for(int j = 0;j < strlen(buff);j++)
        {
      		arr[str_len] = buff[j];
        	str_len++;
        }
	
	while(next_term <= 15)
	{
		sprintf(buff,"%d ",next_term);
        	for(int j = 0;j < strlen(buff);j++)
        	{
      			arr[str_len] = buff[j];
        		str_len++;
        	}
		
		n1 = n2;
		n2 = next_term;
		next_term = n1 + n2;
	}
		
	arr[str_len++] = '\n';
	arr[str_len] = '\0';

}
