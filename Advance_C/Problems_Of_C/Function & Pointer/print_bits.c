/*
Name : SK SAHIL
Date : 26/06/2022
Discription : A18 - WAP to print 'n' bits from LSB of a number
Sample I/O :
Test Case 1:
Enter the number: 10
Enter number of bits: 12
Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 
Test Case 2:
Enter the number: 15
Enter number of bits: 4
Binary form of 15: 1 1 1 1
*/
#include <stdio.h>
   // Function Prototype
int print_bits(int, int);

int main()
{
    int num, n;
    
    printf("Enter num, n :\n");
    scanf("%d%d", &num, &n);
    
    printf("Binary form of %d:", num);
    print_bits(num, n);
 }
    // Function Decleration
   int print_bits(int num, int n)
   {
    int i, mask;                // Variables
     if(n<32)                   // Condition for integer bits  
       {
         for(i=(n-1);i>=0;i--)  // Loop cindition
           {
             mask = (1<<i);     // Creating a mask
             if(num&mask)       // If statement for print 0 and 1
              printf("1 ");
            else
                printf("0 ");
             }
        }       
    }
