#include "sll.h"
Slist *reverse(Slist *head)
{
	if((head) ->link)
	{
		return head;
	}
	Slist *revHead = reverse((head)->link);
	(head)->link->link = head;
	(head)->link = NULL;
	return revHead;
} 
int reverse_recursion(Slist ** head)
{
	if(*head == NULL)
	{
		return LIST_EMPTY;
	}
	*head = reverse(*head);
	return SUCCESS;
}
