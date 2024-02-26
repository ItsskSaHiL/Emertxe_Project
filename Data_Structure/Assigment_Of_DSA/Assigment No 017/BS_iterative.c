#include "main.h"
void bubbleSort(data_t *arr,int size)
{
	data_t count = 0;
	for(int i = 0;i < size-1;i++)
	{
		count = 1;
		for(int j = 0;j<size-1-i;j++)
		{
			if(arr[j] > arr[j+1])	
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				count = 0;
			}
		}
		if(count)
		return;
	}
}

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
	bubbleSort(arr,size);
	data_t low = 0,mid;
	data_t high = size - 1;
	while(low <= high)
	{
		mid = ((low+high)/2);
		if(arr[mid] == key)
		{
			return mid+1;
		}
		else if(key < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return DATA_NOT_FOUND;    
}

