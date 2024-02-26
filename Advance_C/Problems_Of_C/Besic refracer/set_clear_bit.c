/*
Name : SK SAHIL
Date : 11/06/2022
Discription :A4 - WAP to check if number is perfect or not
Sample I/O :
Test Case 1:

Enter the number: 19

Enter 'N': 1

Enter 'M': 4

Updated value of num is 3 

Test Case 2:

Enter the number: 19

Enter 'N': 2

Enter 'M': 4

Updated value of num is 19 
*/
#include <stdio.h>
int main() 
{    
      // Initilition and variable 
      int num,N,M,res,mask;
      // For user input number, position of bit
      printf ("Enter the number: ");
      scanf("%d",&num);
      printf ("Enter 'N': ");
      scanf("%d",&N);
      printf ("Enter 'M: ");
      scanf("%d",&M);
      // Condition for check set bit or clear bit
        if( num&(1<<N))
           {
          // Making mask value for clear bit for require position
          mask = ~(1<<M);
         // Using & operation for clear the require bit 
          res = (num&mask);
          // print updated output 
          printf ("Updated value of num is %d\n", res);
          }
        else
          printf ("Updated value of num is %d\n", num);

    return 0;
}

