#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
	if(s->top == s->capacity)
		return FAILURE;
	s->stack[++s->top] = element;
		return SUCCESS;
}
