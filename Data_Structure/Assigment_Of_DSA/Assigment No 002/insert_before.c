#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
       // If the list is empty 
	if(*head == NULL)
  	{
	    return LIST_EMPTY;
       	}
	/* Use temprary pointer to traverse through the list */
	Slist *temp = *head;
	/* if 1 node is present */
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
		
			new->link = temp;  // Link Established btn new node + next node
			*head = new;        // Link Established btn new node + head
			return SUCCESS;
	}
		
	/* use Loop to find the data */
	while(temp != NULL)
	{
                if(temp->link != NULL && temp->link->data == g_data)
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
