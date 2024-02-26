#include "sll.h"

//remove duplicate data's from list
int remove_duplicates( Slist **head )
{
	if(*head == NULL)
    	{
       		 return FAILURE;
    	}
     Slist *temp1 = *head,*temp2 = (*head)->link,*temp3 = *head;
     while(temp1 != NULL)
     {
	while(temp2 != NULL)
	{	
		if(temp1->data == temp2->data)
		{
			temp3->link = temp2->link;
			free(temp2);
			temp2 = temp3->link;
		}
		else
		{
			temp2 = temp2->link;
			temp3 = temp3->link;
		}
	}
	temp1 = temp1->link;
	temp3 = temp1;
	if(temp1 != NULL)
	temp2 = temp1->link;
     } 
     
     return SUCCESS;
}
