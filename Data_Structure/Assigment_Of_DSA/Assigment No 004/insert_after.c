#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
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
			new->next = temp->next;
			new->prev = temp;
			if(temp != (*tail))
			{
				temp->next->prev = new;
			}
			else
			{
				*tail = new;
			}
			temp->next = new;
			return SUCCESS;
		}
	}
	return DATA_NOT_FOUND;
}
