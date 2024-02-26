#include "main.h"

void build_maxheap(int *heap, int size)
{
	int index = size / 2 - 1;
	while(index >= 0)
	{
		max_heap(heap,index,size);
		index--;
	}
	return;
}
