#include "main.h"

data_t selection(data_t *arr, data_t size )
{
	int i,current_min,current_item;
	for(i=0;i<size;i++)
	{
		current_min = i;
		for(current_item = i+1;current_item < size;current_item++)
		{
			if(arr[current_item] < arr[current_min])
			{
				current_min = current_item;
			}
		}
		if(current_min != i)
		{
			int temp = arr[i];
			arr[i] = arr[current_min];
			arr[current_min] = temp;
		}
	}
	return 1;   
}
 
