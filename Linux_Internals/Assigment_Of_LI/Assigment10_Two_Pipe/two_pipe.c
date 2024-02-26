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
	if(argc < 6)
	{
		printf("Error: Insufficient arguments passed Usage: ./pipe  <command1 > '|'   <command2>\n");
		return 1;
	}
	
	// variable decleration
	int pipe_count1 = 0;
	int pipe_count2 = 0;
	
	// find the pipe position
	for(int i = 1; i < argc; i++)
	{
		if(!(strcmp(argv[i],"|")))
		{
			if(pipe_count2 == 0 && pipe_count1 != 0)
			{
				pipe_count2 = i;
			}
			if(pipe_count1 == 0)
			{
				pipe_count1 = i;
			}
		}
	}
	
	// error check for pipe
	if(pipe_count1 == 0)
	{
		printf("Please pass the pipe '|' through CLA\n");
		return 1;
	}
	
	if(pipe_count2 == 0)
	{
		printf("Please pass the pipe '|' through CLA\n");
		return 1;
	}

	// storing the command from CLA
	char *cmd1[pipe_count1];
	char *cmd2[pipe_count2 - pipe_count1];
	char *cmd3[argc - pipe_count2];
	int i,j,k;	

	// sote 1st Command pass through CLA
	for(i = 0;i < (pipe_count1 - 1);i++)
	{
		cmd1[i] = argv[i+1];
	}
	cmd1[i] = NULL;
	
	// sote 2nd Command pass through CLA
	for(j = pipe_count1;j < (pipe_count2 - 1);j++)
	{
		cmd2[j - pipe_count1] = argv[j+1];
	}
	cmd2[j - pipe_count1] = NULL;
	
	// sote 2nd Command pass through CLA
	for(k = pipe_count2;k < (argc - 1);k++)
	{
		cmd3[k - pipe_count2] = argv[k+1];
	}
	cmd3[k - pipe_count2] = NULL;

	// creat pipe
	int pipe1fd[2];
	int pipe2fd[2];
	
	pid_t firstChildPid;
	pid_t secondChildPid;
	pid_t thirdChildPid;

	//create first pipe
	pipe(pipe1fd);

	//firstchild forking
	if (-1 == (firstChildPid = fork()))
	{ 
		//first child
		// indicates the fork was unsuccessful
		perror("cannot fork\n");
		exit(1);
	}
	else if (0 == firstChildPid)
	{
		// first of two child processes 
		// redirect to parent [stdout]
		if (dup2(pipe1fd[1],1) < 0)
		{
			perror("ERROR: dup2 failed!");
			exit(2);
		}

		// close the file descriptor 
		close(pipe1fd[0]);
		close(pipe1fd[1]);

		//execute the command
		if(execvp(argv[1], cmd1)<0)
		{ 
			perror("exec");
			exit(3);
		}
	}

	//open the second pipe
	pipe(pipe2fd);

	//secondChildPid = fork();	
	if (-1 == (secondChildPid = fork()))
	{ 
		//second child
		// indicates the fork was unsuccessful
		perror("cannot fork\n");
		exit(4);
	}
	else if (0 == secondChildPid)
	{
		//close unwanted fd of pipe 1
		close(pipe1fd[1]);
		
		// second of three child processes 
		// redirect output from previous child to input [stdin] 
		if (dup2(pipe1fd[0],0)<0)
		{
			perror("ERROR: dup2 failed!");
			exit(5);
		}

		// close the file descriptor 
		close(pipe1fd[0]);

		//close unwanted fd of pipe2
		close(pipe2fd[0]);

		//redirect from input to pipe2
		if (dup2(pipe2fd[1],1)<0)
		{
			perror("ERROR: dup2 failed!");
			exit(5);
		}

		// close the file descriptor 
		close(pipe2fd[1]);

		//execute the command
		if(execvp(argv[pipe_count1 + 1], cmd2)<0)
		{ 
			perror("exeec");
			exit(3);
		}
	
	}
	
	// close the file descriptor for pipe1
	close(pipe1fd[0]);
	close(pipe1fd[1]);
	
	//thirdChildPid = fork();	
	if (-1 == (thirdChildPid = fork()))
	{ 
		//third child
		// indicates the fork was unsuccessful
		perror("cannot fork\n");
		exit(4);
	}
	else if (0 == thirdChildPid)
	{
		//close unwanted end of pipe 2
		close(pipe2fd[1]);
		
		// third of three child processes 
		// redirect output from previous child to input [stdin] 
		if (dup2(pipe2fd[0],0)<0)
		{
			perror("ERROR: dup2 failed!");
			exit(5);
		}

		// close the file descriptor 
		close(pipe2fd[0]);
		
		//execute the command
		if(execvp(argv[pipe_count2 + 1],cmd3)<0)
		{ 
			perror("Exec");
			exit(3);
		}
				
	}

	// close the file descriptor 
	close(pipe2fd[0]);
	close(pipe2fd[1]);
	

	// wait() might find the first child; continue reaping children until the second child is found 
	for(;;)
	{
		pid_t pid;
		pid = wait(NULL);
		if(pid == secondChildPid)
		{
			break;
		}
		if(pid == firstChildPid)
		{
			break;
		}
		if(pid == thirdChildPid)
		{
			break;
		}
	}


	return 0;	
}
