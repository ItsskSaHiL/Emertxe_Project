#include"hash.h"

int insert_HT(hash_t *arr, int element, int size)
{
	// Insert element in Hashtable 
	int index;
	index = element%size;     // Find the Index Position 
	// If the index is empty then direct entry
	if(arr[index].value == -1)
	{
		arr[index].value = element;
		return SUCCESS;
	}
	// If the index is alrady full
	hash_t *new = malloc(sizeof(hash_t));
	if(new == NULL)	
	{
		return FAILURE;
	}
	new->value = element;
	new->index = index;
	new->link = NULL;
	if(arr[index].link == NULL)
	{
		arr[index].link = new;
		return SUCCESS;
	}
	// If there was more node present in one index
	hash_t *temp = arr[index].link;
	while(temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = new;
	return SUCCESS;		
}
