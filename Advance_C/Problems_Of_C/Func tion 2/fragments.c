/*
Name : SK SAHIL
Date : 10/08/2022
Discription : A49 - WAP to implement fragments using Array of Pointers
Sample I/O :
Test case 1:
user@emertxe] ./fragmentsEnter
Enter no.of rows : 3
Enter no of columns in row[0] : 4
Enter no of columns in row[1] : 3
Enter no of columns in row[2] : 5
Enter 4 values for row[0] : 1 2 3 4
Enter 3 values for row[1] : 2 5 9
Enter 5 values for row[2] : 1 3 2 4 1

Before sorting output is:

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

After sorting output is:

1.000000 3.000000 2.000000 4.000000 1.000000 2.200000

1.000000 2.000000 3.000000 4.000000 2.500000

2.000000 5.000000 9.000000 5.333333
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int array_count, i, j;
	float sum;
	char choice;
	
		printf("\nEnter no. of rows: ");
		scanf("%d",&array_count);
		float *arr[array_count];
		int array_of_col_count[array_count];
		int output_pos[array_count];
		
		/*dynamically allocating memory and fill the output_pos array in order*/
		for(i=0; i<array_count; i++)
		{
			printf("Enter no. of colums in row[%d]: ",i);
			scanf("%d",&array_of_col_count[i]);
			arr[i] = malloc( sizeof(float) * array_of_col_count[i]+1);
			output_pos[i] = i;
		}
		
		/*inputing the array elements*/
		for(i=0; i<array_count; i++)
		{
			printf("Enter %d values of row[%d]: ",array_of_col_count[i], i);
			for(int j=0; j<array_of_col_count[i]; j++)
				scanf(" %f",&arr[i][j]);
		}
		
		/*printing the array before sorting*/
		printf("Before shorting output is: \n");
		for(i=0; i<array_count; i++)
		{	
			sum = 0;
			for(j=0; j<array_of_col_count[i]; j++)
			{
				printf("%f ",arr[i][j]);
				sum = sum + arr[i][j];
			} 
		// 	printf("j = %d %d\n",j,i);
			printf("%f\n", arr[i][j]=sum/j );
		}
		
		/*checking the mean and sorting with the mean values of 'n' arrays*/
		for( i=0; i < array_count-1; i++)
		{
			for( j=0; j < array_count-1-i; j++)
			{
			
				if(arr[output_pos[j]][array_of_col_count[output_pos[j]]] > arr[output_pos[j+1]][array_of_col_count[output_pos[j+1]]])
					output_pos[j] = output_pos[j] + output_pos[j+1] - (output_pos[j+1] = output_pos[j]); 
			}	
				
		}
		
		/*printing the array after sorting*/
		printf("\nAfter shorting output is : \n");
		for(i=0; i<array_count; i++,printf("\n"))
		{	
			for(j=0; j<array_of_col_count[output_pos[i]]+1; j++)
				printf("%f ",arr[output_pos[i]][j]);
		}
	
	
	return 0;
}
