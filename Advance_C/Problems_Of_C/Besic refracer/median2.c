/*
Name : SK SAHIL
Date : 22/06/2022
Discription : A13 - WAP to find the median of two unsorted arrays
Sample I/O : 
Test Case 1: 
Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 5
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 3 7 8 5
Median of array1 : 4
Median of array2 : 7
Median of both arrays : 5.5                         
Test Case 2:
Enter the 'n' value for Array A: 5
Enter the 'n' value for Array B: 4
Enter the elements one by one for Array A: 3 2 8 5 4
Enter the elements one by one for Array B: 12 13 7 5
Median of array1 : 4
Median of array2 : 9.5                                      
Median of both arrays : 6.75    
*/ 



#include <stdio.h>

int main() 
{
    // Variables and user input 
    int n,m,i,j,temp;
    printf("Enter the 'n' value for Array A:");
    scanf("%d",&n);
    printf("Enter the 'n' value for Array A:");
    scanf("%d",&m);
    int arr1[n];
    int arr2[m];
    // Entering array eliment
     printf("Enter the elements one by one for Array A:"); 
     for(i = 0;i < n; i++)
     {
         scanf("%d",&arr1[i]);
     }
       printf("Enter the elements one by one for Array A:");
     for(i = 0;i < m; i++)
     {
         scanf("%d",&arr2[i]);
     }
     // Shorting the array element 
      // For arr-1
       for(i = 0; i <=(n-2);i++)
       {
         for(j = 0;j <=(n-2-i);j++)
          {
            if(arr1[j+1]<arr1[j])
           {
            temp = arr1[j];
             arr1[j] = arr1[j+1];
               arr1[j+1] = temp;
             }
           }
        }
       // For arr-2
        for(i = 0; i <=(m-2);i++)
       {
         for(j = 0;j <=(m-2-i);j++)
          {
            if(arr2[j+1]<arr2[j])
           {
            temp = arr2[j];
             arr2[j] = arr2[j+1];
               arr2[j+1] = temp;
             }
           }
        }
     // Fimd the median
    // For Array 1
    int m1,m2,m3,m4;
    if( n % 2 == 0)
   {
     m1 = arr1[n/2];
     m2 = arr1[n/2 - 1];
     float Med = (m1+m2)/2.0;
     printf(" Median of array1 : %g\n",Med);
    }
   else
     {
      float Med = arr1[n/2];
     printf("Median of array1 : %g\n",Med);
      }
    // For array 2
      if( m % 2 == 0)
   {
     m3 = arr2[m/2];
     m4 = arr2[m/2 - 1];
     float Med2 = (m3+m4)/2.0;
     printf("Median of array2 : %g\n",Med2);
    }
   else
     {
      float Med2 = arr2[m/2];
     printf("Median of array1 : %g\n",Med2);
      }
     // Printing the average
      float avg = (Med + Med2)/2.0;
      printf("Median of both arrays :%g\n",avg);
    return 0;
}
