#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
	// If list is empty
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	Dlist *temp = *head;
	while(temp != NULL)
	{
		if(temp->data != gdata)
		{
			temp = temp->next;
		}
		else
		{
			Dlist *new = (Dlist*)malloc(sizeof(Dlist));
			if(new == NULL)
			{
				return FAILURE;
			}
			new->data = ndata;	
			new->next = temp;
			new->prev = temp->prev;
			if(temp != (*head))
			{
				temp->prev->next = new;
			}
			else
			{
				*head = new;
			}
			temp->prev = new;
			return SUCCESS;
		}
	}
	return DATA_NOT_FOUND;
}


