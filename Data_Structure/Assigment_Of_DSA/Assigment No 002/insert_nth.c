#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
	// Check List is empty or not 
	if(*head == NULL && n > 1)
	{
		return LIST_EMPTY;
	}
        // If the position is negative the Failure
	if(n < 0)
	{
		return POSITION_NOT_FOUND;
	}
	// If n == 1
	if(n == 1)
	{
		Slist *new = (Slist*)malloc(sizeof(Slist));
		if(new == NULL)
		{
			return FAILURE;
		}
		new->data = data;
		new->link = *head;
		*head = new;
		return SUCCESS;
	}
	int n1 = 1; // Use local variable for polling 
	Slist *temp = *head;
	while(temp != NULL)
	{
		if(++n1 == n)
		{	
			Slist *new = (Slist*)malloc(sizeof(Slist));
			if(new == NULL)
			{
				return FAILURE;
			}
			new->data = data;
			new->link = temp->link;
			temp->link = new;
			return SUCCESS;
		}
		else
		{
			temp = temp->link;
		}
	}
	return POSITION_NOT_FOUND;
	

}
