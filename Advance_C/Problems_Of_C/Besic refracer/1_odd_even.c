/*
Name : SK SAHIL
Date : 08/06/2022
Discription : A1 - WAP to check if number is odd or even
Sample I/O :
Test Case 1:

user@emertxe] ./even_odd

Enter the value of 'n' : -2

-2 is negative even number

Test Case 2:

Enter the value of 'n' : 2

2 is positive even number

Test Case 3:

Enter the value of 'n' : 0

0 is neither odd nor even
*/

#include<stdio.h>
int main()
{   
   // Integer input from user
    int n;
    printf( "Enter a number 'n':" );
    scanf( "%d", &n);
   // Condition for +ve number
    if( n > 0 )
    {  
       // Condition for even and odd with mod operator
       if( n % 2 == 0)
      { 
          printf( "%d is psitive even numbern",n);
       }
       else
      {
          printf("%d is positive odd number" , n);

       } 
       }
   // Condition for -ve number
     else if( n < 0 )
    {
      // Condition for even or odd number with using mod operator
       if( n % 2 == 0)
      {
          printf( "%d is negative even number",n);
       }
       else
       {
          printf( "%d is negative odd numbern", n);
       }
       }
         // Condition for 0 
    else 
       {
          printf( "%d is nither odd nor even",n);
       }
    return 0;
     }


