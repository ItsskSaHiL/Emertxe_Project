#include"hash.h"

int destroy_HT(hash_t *arr, int size)
{
	for(int i = 0; i < size;i++)
	{
		if(arr[i].value != -1)
		{
			arr[i].value = -1;
			hash_t *temp = arr[i].link;
			arr[i].link = NULL;			
			hash_t *temp2 = temp;
			while(temp != NULL)
			{
				temp2 = temp->link;
				free(temp);
				temp = temp2;
			}
		}
	}
	return SUCCESS;
}
