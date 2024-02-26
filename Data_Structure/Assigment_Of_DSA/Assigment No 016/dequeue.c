#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
	if(*front == NULL)
	{
		return FAILURE;
	}
	if(*front == *rear)
	{
		free((*front));
		*front = *rear = NULL;
		return SUCCESS;
	}
	else
	{
		(*rear)->link = (*rear)->link->link;
		free((*front));
		*front = (*rear)->link;
		return SUCCESS;
	}
	return FAILURE;
}
