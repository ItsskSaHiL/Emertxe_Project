/*
  Name : Sk Sahil
  Assigment : A12 - Implement communication between two different processes using SHM
  Date of Submission : 11/01/2023
  Pre-requisites:- 
	Knowledge about system calls, How to read and understand ‘man pages’.
	Good knowledge about Shared memory 
  Objective: 
	To understand how to establish communication between 2 different process.
  Requirements: 
	Create 2 different process by executing 2 different a.out (executable) file’s
	Create SHM from any of the process. Either Process 1 or Process 2
	In process 1 
	Prompt the user to enter a string 
	Convert the string into Upper case
	Write the Upper case string  in shared memory
	4.In process 2

	Read the data from the shared memory 
	Reverse input which is read from SHM
	Write the Reverse string  in shared memory
	5.Read the data from shared memory in process 1
	6.Print the output string on stdout
	Sample output :

	Run the two process executable in two different tabs 

	1. ./Process1 

	Enter the string: Hello

	Writing to shared memory ......
	
	Reading from shared memory:  OLLEH

	2. ./Process 2

	Reading from shared memory :olleh

	Writing to Shared memory ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SMSIZE 100
// function prototype
void strrev(char* s, char size, char iter);


int main()
{
	// variable decleartion
    	int shmid;
	char data[20] = {'\0'};
    	key_t key;
    	char *shm,*shm2;

    	/* Use the same key as in writer */
 	key = 'B';

    	/* Get the shared memory, creation is already done */
	shmid = shmget(key,SMSIZE, IPC_EXCL | 0666);

    	if (shmid < 0)
    	{
    		perror("shmget");
    		exit(1);
    	}

	/* Attach to shared memory */
    	shm = shmat(shmid,NULL,0);
    
		// copy the string
		strcpy(data,shm);
		
		printf("Recive DATA from shared memory: %s\n",data);		
		// revers the string
		strrev(data,strlen(data),0);

		/* Read the value from shared memory and print */
		printf("After reverse the data store in Shared Memory \n");
		
		shmdt(shm);//Detach the pointer from this shared memory
		
		shm2 = shmat(shmid,NULL,0);
		
		// rewrite in shared memory
		strcpy(shm2,data);
 	
	
	/*
	 * TODO: 1. Detach & remove the shared memory. Confirm deletion by executing ipcs
	 *       2. Extend this program for assignment in order to exhange string
	 */
}

void strrev(char* s, char size, char iter)
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
