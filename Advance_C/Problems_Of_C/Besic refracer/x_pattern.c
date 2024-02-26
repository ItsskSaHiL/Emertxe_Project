/*
Name : SK SAHIL
Date : 11/06/2022
Discription : A6 - WAP to print the numbers in X format as shown below
Sample I/O : 
Test Case 1:
Enter the number: 4
1  4
 23
 23
1  4

Test Case 2:
Enter the number: 5
1   5
 2 4
  3
 2 4
1   5
*/

#include <stdio.h>
int main() 
 {
    // initilization and variables
    int row,col,n;
  // For user input
    printf("Enter the number:");
    scanf("%d", &n);
    // using for loop for printing the matrix format
    for( row = 1;row <= n; row++)    // outer loop for row
    {
        for(col = 1; col <= n; col++)   // Inner loop for collum
        {
           // Condition for X format
            if( row == col)    // check row == col and print the row value
            {
           printf("%d ", row);
            }
            else if ( row + col == n + 1)  // check add row and collum value and making condition with no of row and collum print the collum value
            {
             printf("%d ", col);
            }
              else                  // Print the space when conditon not match
              printf(" ");
        }       
        printf("\n");     // For new line
   }
      return 0;
 } 
