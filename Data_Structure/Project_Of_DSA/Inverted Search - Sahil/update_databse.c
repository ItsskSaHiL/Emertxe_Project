#include"inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    //prompt the user to enter new file name 
    char file_name[FNAME_SIZE];
    int empty;
    int flag = 1;
    Flist *temp = *f_head;
    printf("Enter the filename to update database\n");
    scanf("%s" , file_name);

    // validate
   //..........TODO......
	empty = isFileEmpty(file_name);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n", file_name);
	    printf("Hence we are not adding into file linked list\n");
		return ;
	}
	else if(empty == FILE_EMPTY)
	{

	    printf("File : %s is not having any contents in it\n",file_name);
	    printf("Hence we are not adding into file linked list\n");
		return ;
	}
	else
	{
		int ret_val = to_create_list_of_files(f_head, file_name);
		if(ret_val == SUCCESS)
              	{
                	printf("Successfull : inserting the filename : %s into file     linked list\n" , file_name);
   			while((*f_head)->link != NULL)
   			{
				*f_head = (*f_head)->link;
				//temp = temp->link;
			}
			create_database(*f_head , head);
			return;
              	}
              	else if ( ret_val == REPEATATION)
              	{
                	printf("This file name : %s is repeated . So do not add more     than once :\n", file_name);
        		return ;      
		}
             	else
              	{
              	    	printf("Failure\n");
			return;
              	}
	}
        return;
}


