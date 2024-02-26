/*
  Name : Sk Sahil 
  Assigment No : 01
  Assigment Subject : Implement a cp(copy) command with –p option
  
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Command line arguments, File operation system calls (open, read, write, close, fstat ..etc

  Objective:
  	To understand and implement using basic system calls
  
  Discription : 
	Pass the file name through CLA, validate them and then copy the content from source file and write into destination file, also with -p option which set the file permission for destination file .

  Date Of Submission : 25/12/2022

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
	/* Varibale decleration*/

	// index 
	int s,d;
	
	// permission flag 
	int per_flag = 0;
	
	// file mode info
	struct stat file_info;
	int ret;
	
	// file discreptor
	int source_fd,dest_fd;

	/* Validate the command line */ 
	if(argc >= 3)
	{
		// check -p is pass or not;
		if(strcmp(argv[1],"-p") == 0)
		{
			// check for the destination file
			if(argv[3] == NULL)
			{
				printf(" Error : Destination file Not Pass\n");
				return 1;
			}
			// when pass -p then decleare index of source and dest file	 
			s = 2;                  
			d = 3;
			// change the permission flag 
			per_flag = 1;
		}
		else
		{
			s = 1;
			d = 2;
		}
	}
	else
	{
		// Print the error message
		printf("pass the command line like : ./a.out -p <source_file> <dest_file>  OR\n  \t   ./a.out <source_file> <dest_file>\n");
		return 1;
	}
	
	/* file operation */

	// then open the source file in readonly mode 
	source_fd = open(argv[s],O_RDONLY);
		
	// error check
	if(source_fd == -1)
	{
		printf("%s file NOT  present in current directory ",argv[s]);
		return 1;
	}
	
	// store the file permission
	ret = fstat(source_fd,&file_info);
	
	// error check
	if(ret == -1)
	{
		printf("Find ERROR \n");
		return 1;
	}
	
	// depent upon the permission flag open the dest file in write only mode 
	if(per_flag == 1)
	{
		dest_fd = open(argv[d],O_CREAT | O_EXCL | O_WRONLY,file_info.st_mode);  // if the file is not exist then open it and pass the permission
	}
	else
	{
		dest_fd = open(argv[d],O_CREAT | O_EXCL | O_WRONLY,0664);  // Pass the default file permission
	}	

	// Error check 
	if(dest_fd == -1)
	{
		if(errno == EEXIST)
		{
			// variable for storing the user input 
			char option;
			printf("For OverWritten Pass y/Y : ");
			scanf("%c",&option);
			
			/* Permission for Over written or Not  */
			if(option == 'y' || option == 'Y')
			{
				// reopen the dest file and erase the previous content 
				dest_fd = open(argv[d],O_TRUNC | O_WRONLY);
				
				// error check 
				if(dest_fd == -1)
				{
					printf("Error Find \n");
					return 1;
				}
				
				int ret_val;
				// if permission is given then pass the permission from source to dest
				ret_val = fchmod(dest_fd,file_info.st_mode);
				
				// error check
				if(ret_val == -1)
				{
					printf("Error Find \n");
					return 1;
				}
			}
			else
			{
				printf("Your permission to close the file & terminate the program \n");
				return 0;
			}
		}
	}
			
	/* COPY FROM SOURCE TO DESTINATION */
	
	// declear the buffer memory
	char buff[20];
	
	// decleare the return variable 
	int rd_wr,count;

	// use loop for copy from one file and store in another(source ---> destination)
	do
	{
		// store in buffer from source file
		rd_wr = read(source_fd,buff,10);
		
		//printf("the rd_wr value %d \n",rd_wr);
		
		// write in destinition file from buffer
		
		count = write(dest_fd,buff,rd_wr);
		
		//printf("the count value %d \n",count);
		
		
	
	}while(rd_wr != 0);
	
	// print successful message
	printf("COPY SUCCESS\n");


	return 0;
}
