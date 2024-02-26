#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{ 
   // If the list is empty 
	if(*head == NULL)
  	{
	    return LIST_EMPTY;
       	}
	/* Use temprary pointer to traverse through the list */
	Slist *temp = *head;
	/* use Loop to find the data */
	while(temp != NULL)
	{
		if(temp->data == g_data)
		{
			/*Memory alloacated dynamically */
			Slist *new = (Slist*)malloc(sizeof(Slist));
			/* check successfully allocated or not */
			if(new == NULL)
			{
			  return FAILURE;
			}
			new->data = ndata;
			new->link = NULL;
			new->link = temp->link;  // Link Established btn new node + next node
			temp->link = new;        // Link Established btn new node + prev node
			return SUCCESS;
		}
		else
		{
			temp = temp->link;
		}

	}
	return DATA_NOT_FOUND;

}
