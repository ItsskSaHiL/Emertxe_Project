#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
	if(*head == NULL && *tail == NULL)
	{
		return FAILURE;
	}
	else
	{
		while(*head != *tail)
		{
			Dlist *temp = *tail;
			*tail = temp->prev;
			temp->prev->next = NULL;
			free(temp);
		}
		Dlist *temp2 = *head;
		*head = *tail = NULL;
		free(temp2);
		return SUCCESS;
	}

}
