#include "queue.h"

/* Function to Insert the element */
int enqueue(Queue_t *q, int data)
{
	if(q->count == q->capacity)
	{
		return FAILURE;	
	}
	if(q->front == -1)
	{
		q->front = 0;
	}
	q->rear = (q->rear + 1)%(q->capacity);
	(q->count)++;
	q->Que[q->rear] = data;
	return SUCCESS;
}
