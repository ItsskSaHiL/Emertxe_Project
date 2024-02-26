#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{
    // Creat a new node
       Slist *new = (Slist*)malloc(sizeof(Slist));
  
       // Check the condition
      if(new == NULL)
      {
          return FAILURE;
      }
 
          new->data = data;
          new->link = NULL;
 
      // Check head pointer is null or not
      if(*head == NULL)
      {
          *head = new;
          return SUCCESS;
      }
            Slist *temp = *head;
           while(temp->link != NULL)
           {
               temp = temp->link;
          }
           temp->link = new;
           return SUCCESS;
}
