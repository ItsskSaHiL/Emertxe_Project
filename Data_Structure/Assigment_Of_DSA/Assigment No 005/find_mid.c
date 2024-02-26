#include "sll.h"
/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{
  /* if the Node is Empty */
	if(head == NULL)
	{
		return LIST_EMPTY;
	}
	// Initilize two pointer with head pointer
	Slist *temp1 = head,
	      *temp2 = head; 
	while(temp2 != NULL && temp2->link != NULL)
	{
		temp1 = temp1->link;
		temp2 = temp2->link->link;
	}
	*mid = temp1->data;
	return SUCCESS;
} 
