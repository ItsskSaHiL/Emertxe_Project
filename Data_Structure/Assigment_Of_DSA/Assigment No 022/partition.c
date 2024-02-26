#include "main.h"

/* Function to partition the array */
int partition(int *arr, int first, int last)
{
	int pivot,p,q;
	pivot = first;
	p = first;
	q = last;
	while(p < q)
	{
		while(arr[p] <= arr[pivot] && p<last)
		{
			p++;
		}
		while(arr[q] > arr[pivot])
		{
			q--;
		}
		if(p < q)
		{
			int temp = arr[p];
			arr[p] = arr[q];
			arr[q] = temp;
		}
	}
	int temp = arr[pivot];
	arr[pivot] = arr[q];
	arr[q] = temp;
	return q;    
}

