#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
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
		Dlist *temp = *head;
		Dlist *new = (Dlist*)malloc(sizeof(Dlist));
		if(new == NULL)
		{
			return FAILURE;
		}
		new->prev = NULL;
		new->next = NULL;
		new->data = data;
		new->next = temp;
		temp->prev = new;
		*head = new;
		return SUCCESS;


}
