/*
Name : SK SAHIL
Date : 09/07/2022
Discription : A26 - WAP to find 2nd largest element in an array
Sample I/O :
Test Case 1:
Enter the size of the Array : 5
Enter the elements into the array: 5 1 4 2 8
Second largest element of the array is 5
Test Case 2:
Enter the size of the Array : 4
Enter the elements into the array: 66 22 11 3
Second largest element of the array is 22
*/
#include <stdio.h>
   // Function Prototype 
int sec_largest(int [], int);

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
    ret = sec_largest(arr, size);
   // ret = sec_largest(arr, size);
    
    printf("Second largest element of the array is %d\n", ret);
}
    // Function Decleration
   int sec_largest(int arr[], int size)
    {    
          // Initilization of temporary local variable 
         int temp = arr[0],temp2 = arr[0];
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
             
               return temp2;    // Return the second largest element
    }
