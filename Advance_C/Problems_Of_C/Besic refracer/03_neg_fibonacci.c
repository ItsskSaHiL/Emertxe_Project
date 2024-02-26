/*
Name : SK SAHIL
Date : 11/06/2022
Discription :A3 - WAP to generate negative Fibonacci numbers
Sample I/O :
est Case 1 :

user@emertxe] ./fibbonacci_series

Enter a number: -8

0, 1, -1, 2, -3, 5, -8

Test Case 2:

Enter a number: -10

0, 1, -1, 2, -3, 5, -8

Test Case 3:

Enter a number: -21

0, 1, -1, 2, -3, 5, -8, 13, -21

Test Case 4: 

Enter a number: -13

0, 1, -1, 2, -3, 5, -8, 13

Test Case 4: 

Enter a number: 13

Invalid input

*/


#include<stdio.h>
 int main()
 {     
    //initilization and variables
   int num1 = 0 , num2 = 1, next, num,nump, i;
    printf("Enter a num:" );
    scanf("%d", &num );   // user input
    // Condition for zero
  nump = num * (-1);   // logic for maling positive number
  // Condition for zero
 if( num == 0 )
  {
    printf( "%d" , num1 );
  
  }
  // condition for negative input
  else if( num < 0 )
   {
   printf( "%d, %d" , num1, num2 );    // printing 0 1
   for( i = num; i < 0; i++ )          // condition for loop 

     {
       // Logic for making Fibonacci series 
       next = num1 - num2;
       if ( next >= num && next <= nump )   // Condition for Print require output
      
        printf( ", %d",  next  );          // Print require output
      
        num1 = num2;
        num2 = next;
     }
    }
      // condition for print error
      else 
         { 
           printf( "Invalid input\n" );

           }
       
  return 0;
 }
