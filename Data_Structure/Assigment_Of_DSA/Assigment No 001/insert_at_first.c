#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
      if(*head != NULL)
       {
           Slist *new = (Slist*)malloc(sizeof(Slist));
           new->data = data;
           new->link = *head;
          *head = new;
          return SUCCESS;
      }
      else
      {
          printf("Insert the Element first \n");
          return FAILURE;
      }
	
}
