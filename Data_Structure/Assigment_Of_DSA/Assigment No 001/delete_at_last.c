#include "sll.h"

int sl_delete_last(Slist **head)
{
	if(*head == NULL)
	{
		return FAILURE;
	}
	
	// Taking two pointer 
	Slist *temp = *head;
	if(temp->link == NULL)
	{
		free(temp);
		*head = NULL;
	}

	while(temp != NULL)
	{
		if(temp->link->link == NULL)
		{
			free(temp->link->link);
			temp->link = NULL;
			return SUCCESS;	
		}
		else		
		temp = temp->link;
	}
	
	return FAILURE;
	
}
