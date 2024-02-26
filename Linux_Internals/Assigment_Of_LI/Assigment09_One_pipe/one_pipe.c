/*
* Name : Sk Sahil
* Assigment : A09 - Implement communication between two related processes using one pipe
* Date of Submission : 07/01/2023
*
*Pre-requisites:- 
*	Knowledge about system calls, How to read and understand ‘man pages’.
*	Good knowledge about processes and IPC. 
*	Working of pipe & dup system calls. 
* Objective: 
*	To understand working of pipe between two process. 
*
* Requirements: 
*	Create two child process and execute commands passed from command-line arguments 
*	Each command is separated by a '|' (pipe) character. 
*	First child execute first command (with or without options) and pass o/p to next. 
*	Second child executes second command (after '|') will reads I/p from first cmd. 
*	Parent will wait for both child process to finish .
*
* Sample execution: 
*	./pipe (No arguments)
*		Error: No arguments passed Usage: ./pipe   <command1 > '|'   <command2>   
*
*	2. ./pipe ls
*    		Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2>   
*
*	3. ./pipe ls '|' wc
* 	   	5 25 4. 
*
*	4. ./pipe ls ­ -l -­a '|' wc -­l ­-w 
*    		10 15
*/


#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	// Validate the CLA
	if(argc < 4)
	{
		printf("Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2>\n");
		return 1;
	}
	
	// variable decleration
	int pipe_count = 0;
	
	// find the pipe position
	for(int i = 1; i < argc; i++)
	{
		if(!(strcmp(argv[i],"|")))
		{
			pipe_count = i;
		}
	}
	
	// error check for pipe
	if(pipe_count == 0)
	{
		printf("Please pass the pipe '|' through CLA\n");
		return 1;
	}

	// storing the command from CLA
	char *cmd1[pipe_count];
	char *cmd2[argc - pipe_count];
	int i,j;	

	// sote Command
	for(i = 0;i < (pipe_count - 1);i++)
	{
		cmd1[i] = argv[i+1];
	}
	cmd1[i] = NULL;
	
	// sote Command
	for(j = pipe_count;j < (argc - 1);j++)
	{
		cmd2[j - pipe_count] = argv[j+1];
	}
	cmd2[j - pipe_count] = NULL;
	
	// craet pipe 
	int pipe_fd[2];
	
	if(pipe(pipe_fd) == -1)
	{
		perror("Pipe");
		exit(1);
	}
	
	
	// create child process
	int pid_c1 = fork();
		
	if(pid_c1 > 0)     // parent process
	{
		// execute the 2nd child
		int pid_c2 = fork();
	
		if(pid_c2 > 0)
		{
			// parent Process
			wait(NULL);
		}
		else if(pid_c2 == 0)
		{
			// read the content from pipe 
			// display in stdout
			// close the write end 
			// reading 
			close(pipe_fd[1]);
			
			dup2(pipe_fd[0],0);
			
			execvp(argv[pipe_count+1],cmd2);
		}
		else
		{
			perror("Fork");	
			exit(1);
		}
	}
	else if(pid_c1 == 0)   // child process
	{
		// execute the ls command with extention 
		// store the output of ls in pipe 
		// using file discreptor
		
		// write into pipe
		close(pipe_fd[0]); // close the read fd
		
		dup2(pipe_fd[1],1);
		
		
		execvp(argv[1],cmd1); 
			
		
	}
	else
	{
		perror("fork");
	}
	
	return 0;	
}
