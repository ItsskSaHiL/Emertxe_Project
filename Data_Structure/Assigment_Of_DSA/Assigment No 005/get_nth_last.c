#include "sll.h"
/* Function to get the nth node from the last of a linked list*/
int find_nth_last(Slist *head, int pos, int *data) 
{ 
       /* if the Node is Empty */
	if(head == NULL)
	{
		return LIST_EMPTY;
	}
	// Initilize two pointer with head pointer
	Slist *temp1 = head,
	      *temp2 = head; 
	if(pos < 1)
	{
		return FAILURE;
	}
	for(int i = 0;i < pos;i++)
	{
		if(temp2 != NULL)
		{
			temp2 = temp2->link;
		}
		else
		{
			return FAILURE;
		}
	}
	while(temp2 != NULL)
	{
		temp1 = temp1->link;
		temp2 = temp2->link;
	}
	*data = temp1->data;
	return SUCCESS;

} 
