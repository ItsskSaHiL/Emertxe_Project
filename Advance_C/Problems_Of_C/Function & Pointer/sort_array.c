/*
Name : SK SAHIL
Date : 11/07/2022
Discription : A32 - Print the values in sorted order without modifying or copying array
Sample I/O :
Test Case 1:
Enter the size : 5
Enter 5 elements 
10 1 3 8 -1
After sorting: -1 1 3 8 10
Original array values 10 1 3 8 -1

Test Case 2:
user@emertxe] ./sort
Enter the size : 7
Enter 7 elements 
1 3 2 5 4 7 6
After sorting: 1 2 3 4 5 6 7
Original array values 1 3 2 5 4 7 6

Test Case 3:
user@emertxe] ./sort
Enter the size : 4
Enter 4 elements 
-1 -2  4 3
After sorting: -2 -1 3 4
Original array values -1 -2  4 3
*/

#include <stdio.h>
  // Function prototype
void print_sort(int [], int);

int main()
{
    int size, iter;
    
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    
    int arr[size];
    
    printf("Enter the %d elements\n",size);
    for (iter = 0; iter < size; iter++)
    {
        scanf("%d", &arr[iter]);
    }
    
    print_sort(arr, size);
}
    // Function decleration 
   void print_sort(int arr[], int size)
   {
    int i, j;

    int min, max, temp;

    max = min = arr[0];

    //find min and max value from array

    for(i = 0 ; i < size ; i++)

    {

        if(arr[i] > max)

            max = arr[i];

        if(arr[i] < min)

            min = arr[i];

    }

    //print Statement

    printf("After Shorting :");

    printf("%d ", min);

    //Condition for Array shorting

    for(i= 0 ; i < size ;i++)

    {

        temp = max;

        for(j = 0 ; j < size ; j++)

        {

            if(arr[j] > min && arr[j] < temp )

            {

                temp = arr[j];

            }

        }

        printf("%d ",temp);

        if(temp == max)

        {

            break;

        }

        min = temp ;           

    }
        // Print the original array element
         printf("\n");
        printf("Original array values");
         for (i = 0; i < size; i++)
         printf("%d ",arr[i]);
          printf("\n");
}
