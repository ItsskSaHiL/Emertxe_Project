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
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 100
#define FIFO_NAME "/tmp/p1"

// function prototype
void strrev(char* s, int size, char iter);

int main()
{
	/* Read from shared memory
	* Reverse the string 
	* store in FIFO
	*/
	
	// variable decleartion
	key_t key;
	char data_in[20] = {'\0'};

	key = 'A';
	
	
	// read from the shared memory
	int shmid = shmget(key,BUFF_SIZE, IPC_EXCL | 0664);
	
	//Attach a pointer which points to shared memory base address
	char* shm = shmat(shmid, NULL, 0);
	
	//Get the string from shared memory
	strcpy(data_in, shm);
	
	shmdt(shm);//Detach the pointer from this shared memory
	
	shmctl(shmid, IPC_RMID, NULL);//Destroy process P1

	// print data recive
	printf("Data recive Successful\n");

	int size = strlen(data_in);
	
	strrev(data_in,size,0);
	
	/* attached FIFO file 
	* store the reverse data 
	*/
	
	int fd; // variable decleartion
	
	fd = open(FIFO_NAME,O_WRONLY);
	
	if(fd < 0)
	{
		perror("open");
		exit(2);
	}
	else
	{
		write(fd,data_in,20);
		printf("Write operation is Successful\n");
		close(fd);
	}
	
	return 0;
}

void strrev(char* s, int size, char iter)
{
        //Swap lower half of the string with its upper half
        if (iter < (size) / 2)
        {
                //Using XOR swapping technique 
                s[iter] ^= s[size - 1 - iter];
                s[size - 1 - iter] ^= s[iter];
                s[iter] = s[size - 1 - iter] ^ s[iter];
                //Recursive call with incremented iter value
                strrev(s, size, ++iter);
        }
        //Implicit return
}
