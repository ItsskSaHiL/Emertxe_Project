/*
Name : SK SAHIL
Date : 12/06/2022
Discription : A7 - WAP to print triangle pattern as shown below
Sample I/O : 
Test Case 1:
Enter the number: 4
1 2 3 4
5     6
7 8
9

Test Case 2:
Enter the number: 5
1 2 3 4 5
6       7
8    9
10 11
12
*/
#include <stdio.h>
int main() 
{
      // initilization and variables
     int row,col,n,i = 1;
     // For user input
     printf("Enter the number:");
     scanf("%d",&n);
    // Outer loop for print row
     for(row = n; row >= 1; row--)
    {
    // Inner loop for print collum
    for(col = 1; col <= row; col++)
    {
        // Logic for printing the row and collum value
        if ( col == 1 || col == row || row == n )
        {
        printf("%d ", i);  // print number 
        i++;               // with increment value
        }
        // for printing space 
        else  
        {
            
        printf("  ");
        }
    }
    // print new line   
    printf("\n");
}   
    
    return 0;
}
