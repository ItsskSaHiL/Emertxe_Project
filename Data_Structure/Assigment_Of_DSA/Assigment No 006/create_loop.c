#include "sll.h"

/* Function to create the loop */
int create_loop(Slist **head, data_t data)
{
	// if list is empty
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	Slist *temp = *head,*temp2 = NULL;
	while(temp != NULL)
	{
		if(temp->link != NULL && temp->link->data == data)
		{
			temp2 = temp->link;
		}
		// making the loop if data is present 
		if(temp2 != NULL && temp->link == NULL)
		{
			temp->link = temp2;
			return SUCCESS;
		}
		else
		{
			temp = temp->link;
		}
	}
	// if data not found
	return DATA_NOT_FOUND;

}
