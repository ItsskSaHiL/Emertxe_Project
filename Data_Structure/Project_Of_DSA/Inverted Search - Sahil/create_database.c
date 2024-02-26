#include "inverted_search.h"

//char *fname;
void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the file list
    while(f_head)
    {
	read_datafile(f_head , head, f_head -> file_name);
	f_head = f_head->link;
    }
	printf("Successful : Creating Database \n"); 
	return;
}
// read contents of file 

void read_datafile(Flist *file, Wlist *head[], char *filename)
{
    //open file
    FILE *fptr = fopen(filename , "r");

    int flag = 1;
    strcpy(fname,filename);

    //declare an array to store the words
    char word[WORD_SIZE];
    while(fscanf(fptr , "%s" , word) != EOF)
    {
	//index

	int index = tolower(word[0])%97;
	
	//other than alphabets
	if( !(index >= 0 && index <= 25))
	    index = 26;
	
	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];
	    //compare the words at each node with new word
	    while(temp)
	    {
		if(!(strcmp(temp->word , word)))
		{
		    update_word_count(&temp , filename);
		    flag = 0;
		    break;
		}
		temp = temp->link;
	    }
	}
	if(flag == 1)
	{
	   //words are not repeated
	    insert_at_last(&head[index] , word);
	}
    }
	fclose(fptr);
	return;
}

int update_word_count(Wlist **head , char *file_name)
{
	int flag = 1;
	Ltable *temp = (*head)->Tlink;
	// Traverse the list
	while(temp->table_link != NULL)
	{
		if(!(strcmp(temp->file_name,file_name)))
		{
			temp->word_count = temp->word_count+1;
			flag = 0;
		}
		temp = temp->table_link;
	}
	if(!(strcmp(temp->file_name,file_name)))
	{
		temp->word_count = temp->word_count+1;
		flag = 0;
	}
	
	if(flag == 0)
	{
		return SUCCESS;
	}
	// Check if the file name is not match
	if(flag == 1)
	{
		//create node
   		Ltable *new = malloc(sizeof(Ltable));
   		//error check
   		if(new == NULL)
   		{
			return FAILURE;
    		}
    		new->word_count = 1;
    		strcpy(new->file_name,file_name);
    		new->table_link = NULL;
		// update new node 
    		temp->table_link = new;
		// Update file count 
		(*head)->file_count = (*head)->file_count + 1;
		
    		return SUCCESS;
	}
}

