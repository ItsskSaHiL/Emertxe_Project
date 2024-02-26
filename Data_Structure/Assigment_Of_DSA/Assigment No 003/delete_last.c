#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{
	if(*head == NULL && *tail == NULL)
	{
		return FAILURE;
	}
	if(*head == *tail)
	{
		Dlist *temp = *head;
		*head = *tail = NULL;
		free(temp);
		return SUCCESS;
	}
	Dlist *temp = *tail;
	temp->prev->next = NULL;
	*tail = temp->prev;
	free(temp);
	return SUCCESS;

}
