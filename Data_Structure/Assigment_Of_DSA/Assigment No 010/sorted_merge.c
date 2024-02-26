#include "sll.h"

int sorted_merge( Slist **head1, Slist **head2)
{
	// If two list is empty
	if(*head1 == NULL && *head2 == NULL)
	{
		return FAILURE;
	}
	else if(*head1 == NULL)
	{
		sort(head2);
		return SUCCESS;
	}
	else if(*head2 == NULL)
	{
		sort(head1);
		return SUCCESS;
	}
	else
	{
		Slist *temp = *head1;
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = *head2;
		sort(head1);
		return SUCCESS;
	}
	return FAILURE;
	
}
