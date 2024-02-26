#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
	//If list is empty 
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
	Dlist *temp = *head;
	*head = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
