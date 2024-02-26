/*
Name : SK SAHIL
Date : 09/06/2022
Discription : A2 - WAP to generate positive Fibonacci numbers
Sample I/O :
Test Case 1 :

user@emertxe] ./fibbonacci_series

Enter a number: 8

0, 1, 1, 2, 3, 5, 8

Test Case 2:

Enter a number: 10

0, 1, 1, 2, 3, 5, 8

Test Case 3:

Enter a number: 21

0, 1, 1, 2, 3, 5, 8, 13, 21

Test Case 4:

Enter a number: -21

Invalid input
*/
#include<stdio.h>
 int main()
 {

   // num1 and num2 is initilization and all are variable and num is user input
   int num1 = 0 , num2 = 1, next, num, i;
    printf("Enter a num:" );
    scanf("%d", &num );   // user input
   // Condition for zero
 if( num == 0 )
  {
    printf( "%d" , num1 );
  
  }
   // Condition for positive input
  else if( num > 0 )
   {
  // Printing the value
   printf( "%d, %d" , num1, num2 );
  // Using loop for calculating the next number of fibonacci series         
   for( i = 0; i < num; i++ )

     {
       // cindition for next number
       next = num1 + num2;
       if ( next <= num )
      {
       // Printing the value
        printf( ", %d",  next  );
       }
        num1 = num2;
        num2 = next;
     }
    }
       // For negative input Error
      else 
         { 
           printf( "Invalid input\n" );

           }
       
  return 0;
 }

