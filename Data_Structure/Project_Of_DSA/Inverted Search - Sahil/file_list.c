#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n", argv[i]);
	    printf("Hence we are not adding into file linked list\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{

	    printf("File : %s is not having any contents in it\n",argv[i]);
	    printf("Hence we are not adding into file linked list\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val=to_create_list_of_files(f_head, argv[i]);
	    if(ret_val == SUCCESS)
	    {
		printf("Successfull : inserting the filename : %s into file linked list\n" , argv[i]);
	    }
	    else if ( ret_val == REPEATATION)
	    {
		printf("This file name : %s is repeated . So do not add more than once :\n", argv[i]);
	    }
	    else
	    {
		printf("Failure\n");
	    }
	    i++;
	    continue;
	}
    }
}


//function is used to check whether file is available or not
// it is going to check file empty or not

int isFileEmpty(char *filename)
{
    FILE *fptr=fopen(filename , "r");
    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) == 0 )
	return FILE_EMPTY;
}

int to_create_list_of_files(Flist **f_head,char *name)
{
	 //...........TODO......
   	 //create file linked_list 
   	 //check filenames duplicate or not 

	// Creat a new node for Flist
	Flist *new = malloc(sizeof(Flist));
	
	if(new == NULL)
	{
		return FAILURE;
	}
	// Update the node
	strcpy(new->file_name,name);
	new->link = NULL;
	
	if((*f_head) == NULL)
	{
		*f_head = new;
		return SUCCESS;
	}
	// Using temp pointer for traversing
	Flist *temp = *f_head;
	Flist *temp2;
	while(temp != NULL)
	{
		if(!(strcmp(temp->file_name,name)))
		{
			free(new);
			return REPEATATION;
		}
		temp2 = temp;
		temp = temp->link;
		//temp = temp->link;
	}
	// Update link
	temp2->link = new;
	return SUCCESS;
}
