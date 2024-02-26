#include "main.h"

void bubbleSort(int *arr,int size)
{
	int count = 0;
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

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
	if(first > last)
	{
		return DATA_NOT_FOUND;
	}
	data_t mid;
	mid = (first+last)/2;
	if(arr[mid] == key)
	{
		return mid+1;
	}
	else if(arr[mid] > key)
	{
		return binarySearch_recursive(arr,size,key,first,mid-1);
	}
	else
	{
		return binarySearch_recursive(arr,size,key,mid+1,last);
	}
}



