/*
  Name : Sk Sahil 
  Assigment No : 02
  Assigment Subject : Implement a cp(copy) command with –p option
  
  Pre-requisites:
	Knowledge about system calls, How to read and understand ‘man pages’.
	Command line arguments, File operation system calls (open, read, write, close...etc)

  Objective:
  	To understand and implement using basic system calls
  
  Discription : 
	validte the CLA and print the required output

  Output : 
	1.When no arguments or file is  passed 
		./word_count
		Hai hello world
		1 3 16 lines words characters
    		Reads from stdin till EOF (ctrl + d) and count lines words and bytes.

	2. When one file passed
		./word_count file.txt
 		10 20 45
   		Reads from file till EOF (ctrl + d) and count lines words and bytes.
	3.When Mutilple files are passed
		./word_count f1.txt f2.txt
		5 7 40 f1.txt
		3 4 10 f2.txt
		8 11 50 total
	3. When options passed (-l, -w, -c).
		./word_count file.txt –l –w
		10 20
     		Prints according to given option. Option combination also should work.(Use getopt function )
  
  Date Of Submission : 26/12/2022

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

// print function prototype
void print_value(int word,int cha,int line,int w_flag,int c_flag,int l_flag);


int main(int argc,char *argv[])
{
	// variable decleration 
	int word = 0;
	int line = 0;
	int cha = 0;
	
	// flag for print specific 
	int l_flag = 0;
	int w_flag = 0;
	int c_flag = 0;
	
	// for storing the total char word line count
	int total_l = 0;
	int total_c = 0;
	int total_w = 0;

	// for check the specifire
	int opt;	
	
	// input flag
	int file_flag = 0;
	
	// for file count
	int file_count;
	
	// validate the CLA
	if(argc == 0)
	{
		return 1;
	}
	
	// for the specific option 
	while((opt = getopt(argc,argv,"lwc")) != -1)
	{
		switch(opt)
		{
			case 'l':
				l_flag = 1;
				break;
			case 'w':
				w_flag = 1;
				break;
			case 'c':
				c_flag = 1;
				break;
			default:
				printf("Unknown char find\n");
				return 1;
		}
	}

	
	// if the file is pass then the optind
//	printf("optind -> %d",optind);
//	printf ("Lflag = %d, Cflag = %d, Wvalue = %d\n",l_flag, c_flag,w_flag);

	// check file is present or not 
	if(argv[optind] != NULL)
	{
//		printf("file present \n");
		
		// change the input 
		file_flag = 1;
		
		// save the file count
		file_count = optind;
	}
/*	else
	{
		printf("file is Not present \n");
		
	}
*/	
	
	/* read the input from the STDIN */
	
	if(file_flag == 0)
	{
		// decleare the buffer memory
		char buff[1024] = {'\0'};
		int ret; // store return value from return 
		
		//read from stdin
		ret = read(0,buff,1000);
		
		
//		printf("return value -> %d",ret);
		
		int i = 0;

		while(buff[i] != '\0')
		{
			cha++;

        		/* Check new line */
        		if (buff[i] == '\n' || buff[i] == '\0')
        		line++;

        		/* Check words */
        		if (buff[i] == ' ' || buff[i] == '\t' || buff[i] == '\n' || buff[i] == '\0')
            		word++;
			
			// increment the count i
			i++;
		}
		
		// print the values
		print_value( word, cha,line, w_flag, c_flag, l_flag);
		
		printf("\n");
	}
	
	/* read input from file */
	
	if(file_flag == 1)
	{
		// decleare the buffer memory
		char buff[1024] = {'\0'};
		int ret; // store return value from return 
		
		// save the file descriptor
		int fd;
 
		//read from file
		while(argv[file_count] != NULL)
		{
			// open the file and store file descriptor
			fd = open(argv[file_count],O_RDONLY);
			
			// error check
			if(fd == -1)
			{
				printf("error find in %s \n",argv[file_count]);
			}
	
			while(ret != 0)
			{
				//read file content from file
				ret = read(fd,buff,1000);
		
		
//				printf("return value -> %d",ret);
			
				int i = 0;
	
				while(i != ret)
				{
					cha++;
	
       			 		/* Check new line */
        				if (buff[i] == '\n' || buff[i] == '\0')
        				line++;
		
        				/* Check words */
        				if (buff[i] == ' ' || buff[i] == '\t' || buff[i] == '\n' || buff[i] == '\0')
            				word++;
			
					// increment the count i
					i++;
				}
				
				// re initilize the count
				i = 0;
			}
			// print the char word and file count
			print_value( word, cha, line, w_flag, c_flag, l_flag);
			
			// print the file name 
			printf(" %s",argv[file_count]);
		
			printf("\n");
	
			// add them all
			total_l += line;
			total_c += cha;
			total_w += word;
			
			// reinitilize them all
			line = 0;
			cha = 0;
			word = 0;
			
			// increment the file count
			file_count++;
			
			// reinitilize the ret value with -1
			ret = -1;
		}
	}
	
	// print total values
	if((file_count - optind) > 1)
	{
		print_value( total_w, total_c, total_l, w_flag, c_flag, l_flag);
		printf("  total\n");
	}

	return 0;
}


/* finction for printing count */

void print_value(int word,int cha,int line,int w_flag,int c_flag,int l_flag)
{

	// print the line count 
	if(l_flag == 1)
	{
		printf("\t%d",line);
	}

	// print the word count 
	if(w_flag == 1)
	{
		printf("\t%d",word);
	}
	

	// print the charecter count 
	if(c_flag == 1)
	{
		printf("\t%d",cha);
	}
	
	/* Print All of them */
	if(l_flag == 0 && c_flag == 0 && w_flag == 0)
	{
		printf("\t%d\t%d\t%d",line,word,cha);
	}

}
