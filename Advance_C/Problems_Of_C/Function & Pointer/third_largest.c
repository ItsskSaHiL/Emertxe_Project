/*
Name : SK SAHIL
Date : 09/07/2022
Discription : A27 - WAP to find 3rd largest element in an array
Sample I/O :
Test Case 1:
Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Third largest element of the array is 4
Test Case 2:
Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Third largest element of the array is 11
*/

#include <stdio.h>

int third_largest(int [], int);

int main()
{
    int size, ret;
    
    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);
    
    int arr[size];
    
    //Read elements into the array
     printf("Enter the array Element:");
    for(int i = 0; i < size; i++)
    scanf("%d",&arr[i]);
    
    //funtion call
    ret = third_largest(arr, size);
    
    printf("Third largest element of the array is %d\n", ret);
}
     // Function Decleration
   int third_largest(int arr[], int size)
    {    
          // Initilization of temporary local variable 
         int temp = 0,temp2 = 0,temp3 = 0;
          // Logic for finding Largest element in an array
         for(int i = 0; i < size; i++)
            {
                if(arr[i] > temp)
                  temp = arr[i];    // Storing largest element
                 
            }
             // Condition for second largest element in array
            for(int i = 0; i < size; i++)
            {
                if(arr[i] > temp2 && arr[i] != temp)
                  temp2 = arr[i]; // storing second largest element
            }
            // Condition for third largest element in array
            for(int i = 0; i < size; i++)
            {
                if(arr[i] > temp3 && arr[i] != temp2 && arr[i] != temp)
                  temp3 = arr[i]; // storing third largest element
            }
             
               return temp3;    // Return the third largest element
    }

