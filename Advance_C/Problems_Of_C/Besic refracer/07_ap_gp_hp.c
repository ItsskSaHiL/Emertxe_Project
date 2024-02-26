/*
Name : SK SAHIL
Date : 11/06/2022
Discription : A5 - WAP to generate AP, GP, HP series
Sample I/O : 
Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': 5
AP = 2, 5, 8, 11, 14
GP = 2, 6, 18, 54, 162
HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428

Test Case 2:
Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': -5
Invalid input
*/
#include<stdio.h>
int main()
 {
       // initilization and variables
       int A, R,N, i, GP,H;
       // User inputs 
       printf("Enter the First Number 'A':");
       scanf("%d",&A);
       printf("Enter the Common Difference / Ratio 'R':");
       scanf("%d",&R);
       printf("Enter the number of terms 'N':");
       scanf("%d",&N);
       // Initilization for future use
       GP = A;
       H = A;
      // Calculating first term of HP series using Typecasting int to float type increment
    float HP = (float) 1 / A;
   // for requre no of steps positive
   if ( N > 0 )
{
     // Calculating AP series
    printf("AP=%d", A);
    for( i = 1; i < N ; i++)
    {
        A = A + R;          // Arithmatic operation for AP
        printf(", %d", A);
    }  

     //Calculating GP series
      printf("\nGP=%d", GP);
     for( i = 1; i < N ; i++)
    {
        GP = GP * R;         // Arithmatic operation for GP
        printf(", %d", GP);
    }
     
      //Calculating HP series
     printf("\nHP=%f", HP);
     for( i = 1; i < N ; i++)
    {   
         H = H + R;           // Arithmatic operation for HP
        HP = (float) 1 / H;
        printf(", %f", HP);
     } 
   
 } 
   // For invalid no of Terms
   else
         printf("Invalid input");   
  return 0;
 }

