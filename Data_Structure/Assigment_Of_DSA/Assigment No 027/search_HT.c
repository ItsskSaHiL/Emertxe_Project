#include"hash.h"

int search_HT(hash_t *arr, int data, int size)
{
	// Find the index
	int index;
	index = data % size;
	if(arr[index].value == data)
	{
		return SUCCESS;
	}
	// If there was more the one node in one index
	hash_t *temp = arr[index].link;
	while(temp != NULL)
	{
		if(temp->value == data)
		{
			return SUCCESS;
		}
		temp = temp->link;
	}
	return DATA_NOT_FOUND;
}
