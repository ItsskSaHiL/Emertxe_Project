#include"hash.h"

int delete_element(hash_t *arr, int data, int size)
{
	// Find index
	int index;
	index = data % size;
	if(arr[index].value == data && arr[index].link == NULL)
	{
		arr[index].value = -1;
		return SUCCESS;
	}
	// if index has more node
	if(arr[index].value == data && arr[index].link != NULL)
	{
		hash_t *temp = arr[index].link;
		arr[index].value = temp->value;
		arr[index].link = temp->link;
		free(temp);
		return SUCCESS;
	}
	hash_t *temp = arr[index].link;
	hash_t *prev = (arr+index);
	while(temp != NULL)
	{
		if(temp->value == data)
		{
			prev->link = temp->link;
			free(temp);
			return SUCCESS;
		}
		prev = temp;
		temp = temp->link;
	}
	return DATA_NOT_FOUND;		
}
