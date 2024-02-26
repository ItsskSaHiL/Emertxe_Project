/* 
  Name : Sk Sahil 
  Assigment No : 03
  Assigment Subject : WAP to understand usage of dup and dup2 system calls
  
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Command line arguments, File operation system calls (open, read, write, close ..etc)
	Working of dup system calls.
 
  Objective:
	To understand and implement using basic system calls.

  Requirements:
	Using dup or dup2 redirect printf out to a given file instead of printing to stdout.
	Pass the file name using command-line arguments.
	Try using both system calls (dup and dup2).
  Sample Execution:
	./dup_dup2 f1.txt
	Print this message into STDOUT

 Discription : 
	Using the system call dup() and dup2() , implementing a program where printf() (library function)
	output show in a file and another printf()  output show in terminal.
	Here we using the file descriptor value for showing the output in different file .
	
 Date of Submission : 27/12/2022 
	
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<errno.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	
	// validate the CLA
	if(argc != 2)
	{
		printf("ERROR : Pass the file name\n");
		return 1;
	}
	
	// user pass the option
	int option;
	
	printf("Menu : \n 1. dup \n 2. dup2 \n Option : ");
	scanf("%d",&option);
	
	if(option == 1)
	{
	 	// variable decleration
         	int fd,new_fd;

         	// store the stdout
        	int std_cpy,back_up;
	
        	// open the file
         	fd = open(argv[1],O_CREAT | O_TRUNC | O_WRONLY,0664);
	
        	// store stdout
        	std_cpy = dup(1);
	
        	// close stdout
        	close(1);
	
        	// store in new fd
        	new_fd = dup(fd); // 1 -> new_fd -> file.txt
	
        	// store into a file
         	printf("Print the message into FILE \n");
	
        	// flush stdout
        	fflush(stdout);
	
        	// close the stdout as file
        	close(new_fd);

         	// reinitilize stdout
         	back_up = dup(std_cpy); // 1 -> stdout
	
	 	// print in stdout
         	printf("Print the message into STDOUT \n");
	
	}
	else if(option == 2)
	{
		// variable decleration
         	int fd,new_fd;
 		
		// variable store stdout
		int std_cpy;
          	
		// open the file
          	fd = open(argv[1],O_CREAT | O_TRUNC | O_WRONLY,0664);
 
        	// store stdout
        	std_cpy = dup(1);
	
	      	// using dup 2 and store stdout
        	dup2(fd,1);
		
          	// store into a file
          	printf("Print the message into FILE \n");
		
		fflush(stdout);

		// close anothe for fd
		close(fd);

		// restoring 
		dup2(std_cpy,1);
			
		// print in stdout
                printf("Print the message into STDOUT \n");
  
	}
	else
	{
		// if different option is pass then print error
		printf("ERROR : Enter a valid Option \n \t 1 -> dup1 \n \t 2 -> dup2 \n");
	} 
      return 0;
}
