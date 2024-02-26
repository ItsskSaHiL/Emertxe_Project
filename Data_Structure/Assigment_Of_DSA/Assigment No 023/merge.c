#include "main.h"


void merge(int *array, int narray, int *left, int nleft, int *right, int nright)
{
	int i,j,k;
	i = j = k = 0;
	while(i<nleft && j<(narray-nleft))
	{
		if(left[i]<=right[j])
		{
			array[k] = left[i];
			k++;
			i++;
		}
		else
		{
			array[k] = right[j];
			k++;
			j++;
		}   
	}
	while(i<nleft)
	{
		array[k] = left[i];
		k++;
		i++;
	}
	while(j<(narray-nleft))
	{
		array[k] = right[j];
		k++;
		j++;
	}
	free(left);
	free(right);
}

