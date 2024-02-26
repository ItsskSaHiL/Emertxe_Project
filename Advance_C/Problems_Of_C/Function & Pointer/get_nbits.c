/*
Name : SK SAHIL
Date : 25/06/2022
Discription : A14 - WAP to get 'n' bits of a given number
Sample I/O :
Test Case 1:
Enter the number: 10
Enter number of bits: 3
Result = 2
Test Case 2:
Enter the number: 15
Enter number of bits: 2
Result = 3
*/
#include <stdio.h>
  // Function Prototype
int get_nbits(int, int);
   
int main()
{
   
    int num, n, res = 0;

    printf("Enter num and n:");
    scanf("%d%d", &num, &n);
    
    res = get_nbits(num, n);
    
    printf("Result = %d\n", res);
}
    // Function Decleration
   int get_nbits(int a,int b)  // Return Type or Parameter type is Integer
   {
     int mask = ((1 << b) - 1);  // Creating Mask value with bitwise operator
     int res = a & mask;         // Using And bitwise for storing require value
     return res;                // Returning the output of the function
  }
