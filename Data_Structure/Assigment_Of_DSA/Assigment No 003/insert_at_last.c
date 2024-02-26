#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
	// Check list is empty or not 
	if(*head == NULL && *tail == NULL)
	{
		Dlist *new = (Dlist*)malloc(sizeof(Dlist));
		if(new == NULL)
		{
			return FAILURE;
		}
		new->prev = NULL;
		new->next = NULL;
		new->data = data;
		*head = new;
		*tail = new;
		return SUCCESS;
	}
	        // When the list is not empty
		Dlist *temp = *tail;
		Dlist *new = (Dlist*)malloc(sizeof(Dlist));
		if(new == NULL)
		{
			return FAILURE;
		}
		new->prev = NULL;
		new->next = NULL;
		new->data = data;

   		// Link Established
		new->prev = temp;
		temp->next = new;
		*tail = new;
		return SUCCESS;

}
