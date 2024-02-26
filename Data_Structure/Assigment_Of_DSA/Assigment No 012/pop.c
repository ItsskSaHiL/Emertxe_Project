#include "stack.h"

int Pop(Stack_t **top)
{
	if(*top == NULL)
	{
		return SUCCESS;
	}
	Stack_t *temp = *top;
	*top = temp->link;
	free(temp);
	return SUCCESS;
}
