/*
 NAME : SK SAHIL
 PROJECT NAME : INVERTED SEARCH
 DATE : 06/12/2022
 
 BRIEF :  The purpose of storing an index is to optimize speed and performance in
		finding relevant documents for a search query. Without an index, the search
		engine would scan every document in the corpus, which would require
		considerable time and computing power.
 
PREREQUISITE :
		1. Hashing
		2. Single linked list
FUNCTIONS : 
		1. CREAT_DATABASE :
				  User give a file as input through command line, if file have any content then store the content include file name, in 
				  file list, and the content store in word list and table list;
				  Here I using Link List concept for storing the data. Using a special indexing concept take the first char from word
				  and store in correct poisition.
		2. DISPLAY_DATABASE :
				   By this function if there was any content store in database show in terminal(stdout).
		3. UPDATE_DATABASE :
				  By this finction user give another file and also update the file content in the data base.
		4.SEARCH :
			 By this function I traverse through the list and find the user given word is present or not .With Indexing Method.
		5.SAVE_DATABASE :
				By this function I traverse through the list and take every content and save in user given file using fprintf.
		
 Indexing :
	By Indexing, we are creating a database file which contains the index of all words. So this can be
	termed as Database Creation also. All the files whose index are to be created are selected and
	inputed to this function. All the files are parsed and words are separated and indexed. They are
	arranged in sorted order. For this a sorted Linked List or Hashing is used which will store the words
	and the related file details. The index thus created is then stored in the file as database. This file is
	later used in Querying. While the files are removed or added this index file is updated.
 Searching :
	Once the Indexing is over we have the Querying or Searching. The text to be searched is inputed
	which is parsed into words and those words are searched in the index file. To avoid the overhead of
	reading the file again, the file is converted back to a linkedList or hashing program, in which the
	words are searched. The information about the files which contain the words are collected. The ones
	with more matches are filtered and produced as the result.

 WHY : 
	Using for easy store and easy search also save the content for future pourpus.
	
 
	THANK YOU MAM !!!!	
*/

#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");
    // validate the CLA 
    char word[WORD_SIZE];
    Wlist *head[27] = {NULL};
    char option;	
    int choice;
    int index;
    if(argc <= 1)
    {
	printf("Enter the valid no. of arguments\n");
	printf("./Slist.exe f1.txt , f2.txt....\n");
	return 0;
    }

    //create the list of filenames
    //declare head pointer

    Flist *f_head = NULL;

    // validate the files

    file_validation_n_file_list(&f_head, argv);

    if(f_head == NULL)
    {
	printf("No files are available in the file LL\n");
	printf("Hence the process terminated\n");
	return 1;
    }

  do
  {
	printf("Enter the option:\n1. creat_database\n2. Display_Database\n3. Update_Database\n4. Search Data\n5. Save Database\n");
				
	printf("Enter Your Choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
   		 // CREATE DATABASE
    		case 1:
			create_database(f_head , head);
			break;
    		//DISPLAY DATABASE
   		case 2:
			display_database(head);
			break;
		
   		//UPDATE DATABASE
    		case 3:
			update_database(head , &f_head);
			break;

 		//SEARCH_DATABSE
		case 4:
    			printf("Enter the word to search\n");
    			scanf("%s" , word);
			index = tolower(word[0])%97;
			if(index > 25)
			{
				index = 26;
			}
    			search(head[index] , word);
			break;
		
    		//SAVE DATABASE
		case 5:
	    		save_database(head);
			break;
		default:
			printf("Invalid input \n");
		
  	}

		/* check for continue */
        printf("Enter (y/Y) to Continue or (n/N) to Discontinue: ");
        scanf("\n%c", &option);

  } while (option == 'y' || option == 'Y');
  
  return 0;
}

















