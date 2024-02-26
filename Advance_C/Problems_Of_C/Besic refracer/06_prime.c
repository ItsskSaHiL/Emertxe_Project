/*
Name : SK SAHIL
Date : 11/06/2022
Discription : A12 - WAP to print all primes using Sieve of Eratosthenes method
Sample I/O : 
Test Case 1: 
A positive number
Enter the value of 'n' : 20
The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
Test Case 2 :
Enter the value of 'n' : -20
Please enter a positive number which is > 1
*/
#include<stdio.h>
int main()
{
   // Initilization and variables
   int num,i,j;
    // For user input 
    printf("Enter num value of 'n' :");
    scanf("%d",&num);
   if(num > 0)
   {
     // Initiliging an array
     int arr[num];
    // Using loop for store data in array
     for(i =0; i <= (num - 2);i++)
     {
        arr[i] = 2 + i;
     }
      // Loop for fetch multiplier and making as 0
      for(i =0; i <= (num - 2);i++)
     {
         if( arr[i] != 0)
        {
                // Condition for making 0 the multiplier and use num as limit and the increment is adding the element
              for(j = (arr[i]*arr[i]); j <= num;  j = j + arr[i])
               arr[j - 2] = 0;
         }

     }
      // Printing all primes from the array execpt zeros
    printf("The primes less than or equal to %d are :",num);
    for(i =0; i <= (num - 2);i++)
    {
       if(arr[i] != 0)
       printf("%d ", arr[i]);
    }
       printf("\n");
   }
    else
      printf("Please enter a positive number which is > 1\n");
   return 0;
 }

