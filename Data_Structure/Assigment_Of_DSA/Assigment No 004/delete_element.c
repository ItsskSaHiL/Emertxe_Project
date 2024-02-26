#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{
	// If list is Empty 
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	Dlist *temp = *head;
	while(temp != NULL)
	{
		if(temp->data != data)
		{
			temp = temp->next;
		}
		else
		{
			if(temp == (*head) && temp == (*tail))
			{
				*head = *tail = NULL;
				free(temp);
				return SUCCESS;
			}
			else if(temp = (*head))
			{
				*head = temp->next;
				free(temp);
				return SUCCESS;
			}
			else if(temp = (*tail))
			{
				*tail = temp->prev;
				free(temp);
				return SUCCESS;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				free(temp);
				return SUCCESS;
			}
		}
	}
	return DATA_NOT_FOUND;				

}
