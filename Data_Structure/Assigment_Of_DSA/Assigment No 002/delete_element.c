#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
	/* if list is empty */
	if(*head == NULL)
	{
		return FAILURE;
	}
	// Use temprary pointer 
	Slist *temp = *head;
	// If list has one node 
	if(temp->data == data)
	{
	   *head = temp->link;
	    free(temp);
	    return SUCCESS;
	}
	/* delete others node */
	while(temp != NULL)
	{
		if(temp->link != NULL && temp->link->data == data)
		{
			Slist *temp2 = temp->link;
			temp->link = temp->link->link;
			free(temp2);
			return SUCCESS;
		}
		else
		{
			temp = temp->link;
		}
	}
	return DATA_NOT_FOUND;

}
