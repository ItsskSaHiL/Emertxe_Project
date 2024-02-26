#include "main.h"

/* Function to check the number is minimum or maximum to decide the position */
void max_heap(int *heap, int i, int size)
{
	// find the left and right index
	int l = 2*i + 1;
	int r = 2*i + 2;
	int large = i;

	if(l<size && heap[large]<heap[l])
	{
		large = l;
	}
	
	if(r<size && heap[large]<heap[r])
	{
		large = r;
	}

	if(i != large)
	{
		swap(&heap[large],&heap[i]);
		max_heap(heap,large,size);
	}
}

void swap(int *a1,int *a2)
{
	int temp = *a1;
	*a1 = *a2;
	*a2 = temp;
}
	
