#include "stack.h"

int Push(Stack_t **top, data_t data)
{
	// At first creat a node
	Stack_t *new = (Stack_t*)malloc(sizeof(Stack_t));
	if(new == NULL)
	{
		return SUCCESS;
	}
	new->data = data;
	new->link = *top;
	*top = new;
	return SUCCESS;
}
