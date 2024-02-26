#include "sll.h"

int sl_delete_list(Slist **head)
{
	if(*head == NULL)
	{
		return FAILURE;
	}	

	 Slist *temp = *head;
	while(*head != NULL)
	{
		*head = temp->link;
		free(temp);
		temp = *head;         
	}
	return SUCCESS;
}
