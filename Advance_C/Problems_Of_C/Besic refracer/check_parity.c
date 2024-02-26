/*
Name : SK SAHIL
Date : 11/06/2022
Discription : A5 - WAP to generate AP, GP, HP series
Sample I/O :
Test Case 1:

Enter the number : 7

Number of set bits = 3

Bit parity is Odd



Test Case 2:

Enter the number : 15

Number of set bits = 4

Bit parity is Even

Test Case 3:

Enter the number : 6

Number of set bits = 2

Bit parity is Even 
*/
#include <stdio.h>

int main()
{
     // initilization and variables
     int pos,count = 0, num;
     // For user input
     printf ("Enter the number:");
     scanf("%d",&num);
     // using for loop for integer for 4 byte 
     for( pos = 31; pos >= 0; pos--)
       {
         // Condition for set bit using left shift and '&' operator
         if( num&(1<<pos))
        // If true then increment
         count++;
       }
      // Print the output
      printf ("Number of set bits = %d\n", count);
     // Condition for odd or even
      if ( count % 2 == 0)
         printf ("Bit parity is Even\n");
      else
         printf ("Bit parity is Odd\n");

  return 0;
}
