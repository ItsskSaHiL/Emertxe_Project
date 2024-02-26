#include "main.h"


int merge_sort(int *array, int narray)
{	
	int mid;
	if(narray == 1)
	{
		return FAILURE;
	}
	mid = narray/2;
	int *left = malloc(sizeof(int)*mid);
	if(left == NULL)
	{
		return FAILURE;
	}
	for(int i = 0;i<mid;i++)
	{
		left[i] = array[i];
	}
	int *right = malloc(sizeof(int)*(narray - mid));
	if(left == NULL)
	{
		return FAILURE;
	}
	for(int i = mid;i<narray;i++)
	{
		right[i-mid] = array[i];
	}
	merge_sort(left,mid);
	merge_sort(right,(narray - mid));
	merge(array,narray,left,mid,right,(narray - mid));
}

