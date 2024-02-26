#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
	// if list Empty
	if(head == NULL)
	{
		return LIST_EMPTY;
	}
	Slist *temp_1 = head,*temp_2 = head; 
	while(temp_1 != NULL && temp_2 != NULL && temp_2->link != NULL)
	{
		temp_1 = temp_1->link;
		temp_2 = temp_2->link->link; 
		if(temp_1 == temp_2)
		{
			return SUCCESS;
		}
	}
	return LOOP_NOT_FOUND;
		

}
