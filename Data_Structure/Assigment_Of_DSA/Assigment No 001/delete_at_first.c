#include "sll.h"

int sl_delete_first(Slist **head)
{
	if(*head == NULL)   // If head == NULL
	{
		return FAILURE;
	}
        
	Slist *temp = *head;   // LOcal ponter 
	*head = temp->link;    // Link established
	free(temp);            // Free the allocated memory
	return SUCCESS;      
}
