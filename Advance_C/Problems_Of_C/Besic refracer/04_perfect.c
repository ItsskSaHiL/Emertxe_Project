/*
Name : SK SAHIL
Date : 11/06/2022
Discription :A4 - WAP to check if number is perfect or not
Sample I/O : 
Test Case 1:

Enter a number: 6

Yes, entered number is perfect number

Test Case 2:
Enter a number: 10

No, entered number is not a perfect number

Test Case 3:
Enter a number: -1

Error : Invalid Input, Enter only positive number

*/

#include <stdio.h>

int main()
 {    
      // initilization and variables
      int i , sum = 0, num;
      printf("Enter a number:");
       scanf( "%d", &num);    // User input
  // Positive input condition
  if ( num > 0 )
   {   
     // using loop for dividing one by one
     for(i = 1; i < num ;i++)
       {
         // Using mod operaation for perfect factor
         if( num % i == 0)
         // Arithmatic operation add factor
         sum = sum + i;
        }
           // Condition for perfect or not and print
           if( sum == num)
          {
              printf("Yes, entered number is perfect number\n");
          }
          else
             printf( "No, entered number is not a perfect number\n");
    }
     // If negative number in input then print nerror
   else
        printf("Error : Invalid Input, Enter only positive number\n");         
          
          
     return 0;
}

