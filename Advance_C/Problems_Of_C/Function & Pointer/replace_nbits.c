/*
Name : SK SAHIL
Date : 25/06/2022
Discription : A15 - WAP to replace 'n' bits of a given number
Sample I/O :
Test Case 1:
Enter the number: 10
Enter number of bits: 3
Enter the value: 12
Result = 12
Test Case 2:
Enter the number: 15
Enter number of bits: 2
Enter the value: 1
Result =  13
*/
#include <stdio.h>
  // Function prototype
int replace_nbits(int, int, int);

int main()
{
    int num, n, val, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &val);
    
    res = replace_nbits(num, n, val);
    
    printf("Result = %d\n", res);
}
     // Function Declaration
   int replace_nbits(int num, int n, int val)  // Return type and Parameter type is int
   {
      int mask1 = ~((1 << n) - 1);  // Making Mask for clear n bit fron lsb
      int num2 = num & mask1;       // Clearing n bit and store in a veriable
      int mask2 = ((1 << n) - 1);   // Making mask for get n bit from lsb
      int val2 = val & mask2;       // Get n bits and store it
      int res = num2 | val2;        // Using OR bitwise operator adding n bit from lsb
      return res;                    // Returing the output
    }
