#include "sll.h"

/* Function for insert the number in sorted linked list */
int insert_sorted( Slist **head, data_t data) 
{
	// Dynamically aloacated memory 
	Slist *new = (Slist*)malloc(sizeof(Slist));
	if(new == NULL)
	{
		return FAILURE;
	}
	new->data = data;
	new->link = NULL;
	// Check first condition
	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}	
	if((*head)->data > data)
	{
		new->link = *head;
		*head = new;
		return SUCCESS;
	}	
	// check the second condition when list is not empty
	Slist *temp = *head;
	while(temp != NULL)
	{
		if(temp->data < data && temp->link != NULL && temp->link->data > data)
		{
			new->link = temp->link;
			temp->link = new;
			return SUCCESS;
		}  
		else if(temp->data < data && temp->link == NULL)
		{
			temp->link = new;
			return SUCCESS;
		}
		else
		{
			temp = temp->link;
		}
	}

}
