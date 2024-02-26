#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	
	Slist *cur = *head;
        Slist *prev = NULL;
        while(cur != NULL)
        {
            Slist *temp = cur->link;
            cur->link = prev;
            prev = cur;
            cur = temp;
        }
        *head = prev;
	return SUCCESS;
}
