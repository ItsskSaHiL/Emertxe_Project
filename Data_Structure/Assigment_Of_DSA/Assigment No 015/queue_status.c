#include "queue.h"

int IsQueueFull(Queue_t *q)
{
	if(q->count == q->capacity)
	{
		return SUCCESS;
	}
	return FAILURE;
    
}

int IsQueueEmpty(Queue_t *q)
{
   	if(q->count == 0)
	{
		return SUCCESS;
	}
	return FAILURE;
}
