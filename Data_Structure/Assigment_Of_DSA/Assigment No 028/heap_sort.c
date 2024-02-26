#include "main.h"

/* Function to sort the array using heap sort */
void heap_sort(int *heap, int size )
{
	build_maxheap(heap,size);
	int index = size-1;
	while(index >= 0)
	{
		swap(&heap[0],&heap[index]);
		max_heap(heap,0,index);
		index--;
	}
}       

