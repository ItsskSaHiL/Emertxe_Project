/*
  Name : Sk Sahil
  Assigment : A13 - Implement communication between three processes using PIPE, FIFO and SHM
  Date of Submission : 11/01/2023
  Pre-requisites:- 
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about Pipe ,FIFO and Shared memory 
  Objective: 
	To understand how to establish communication between 3 different process using 3 different IPC mechanism.
  Requirements: 
	Create 2 different process by executing 2 different a.out (executable) file’s
	Create a new process (child process) in Process 1
	Create a Pipe between Parent and Child Process
	Create SHM from any of the process. Either Process 1 or Process 2
	In Parent Process 1 
	Prompt the user to enter a string 
	Write the string in pipe 
	Read the string from pipe into child process
	Convert the string into Upper case
	Write the Upper case string  in shared memory
	6.In process 2
	Read the data from the shared memory 
	Reverse input which is read from SHM
	Write the Reverse string  in FIFO
	7.Read the data from FIFO in Parent process 1
	8.Print the output string on stdout

*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 100
#define FIFO_NAME "/tmp/p1"

void convert_to_uppercase(char* s);


int main()
{
	/* in process 1 creat child process
	* then make  pipe between child and the parent process
	* read input from parent and convert in upper case
	*/
	
	// variable declearation
	int pid; // for child process
	char data_in[20] = {'\0'}; // for store input
	char data_out[20] = {'\0'};
	char data_res[20] = {'\0'};
	int pipe_fd[2]; // for pipe file descriptor
	int fd; // for FIFO
	
	// creat pipe
	pipe(pipe_fd);

	// creat child process
	pid = fork();
	
	if(pid > 0)
	{
		// read input from stdin
		printf("Enter the String : ");
		scanf("%[^\n]s",data_in);
		
		// write the data in pipe
		close(pipe_fd[0]); // close the read end of pipe
		
		write(pipe_fd[1],data_in,20);
		
		printf("Write On PIPE Successful\n");
				
		close(pipe_fd[1]);
		
		/* Recive data from FIFO file
		 * creat the FIFO file
		 * read from FIFO
		*/

		//  make fifo
		mkfifo(FIFO_NAME,0666);
		
		fd = open(FIFO_NAME,O_RDONLY);
		
		// error check
		if(fd < 0)
		{
			perror("open");
			exit(2);	
		}
		else
		{
			// read data from FIFO
			read(fd,data_res,20);
			
			// print result
			printf("Reading Successful\n");
			
			printf("Return Data is : %s\n",data_res);
		} 		
	}
	else if(pid == 0)
	{
		// child read the data from pipe 
		close(pipe_fd[1]);
		
		read(pipe_fd[0],data_out,20);
		
		close(pipe_fd[0]);
		
		// convert the data to UPPERCASE
		convert_to_uppercase(data_out);
	
		/* creat the shared memory 
		* store the string 
		* in UPPERCASE 
		*/
		key_t key;
		key = 'A';

		int shmid = shmget(key, BUFF_SIZE, IPC_CREAT | 0664);
		
		//Attach a ponter to the starting address of shared mem
		char* shm = shmat(shmid, NULL, 0);
		
		//Copy the string into shared memory
		strcpy(shm, data_out);
	
		shmdt(shm);//Detach the process P2			
	}
	else
	{
		perror("fork");
		exit(1);	
	}
	
	return 0;
}



void convert_to_uppercase(char* s)
{
		while(*s != '\0')
		{
				if (*s >= 'a' && *s <= 'z')
						*s -= 32;
				s++;
		}
}
