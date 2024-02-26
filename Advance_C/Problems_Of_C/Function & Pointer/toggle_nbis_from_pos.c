/*
Name : SK SAHIL
Date : 25/06/2022
Discription : A17 - WAP to toggle 'n' bits from given position of a number
Sample I/O :
Test Case 1:
Enter the number: 10
Enter number of bits: 3
Enter the pos: 5
Result = 50
Test Case 2:
Enter the number: 15
Enter number of bits: 2
Enter the pos: 2
Result =  9
*/
#include <stdio.h>
  // Function Prototype
int toggle_nbits_from_pos(int, int, int);

int main()
{
    int num, n, pos, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);
    
    res = toggle_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", res);
}
    // Function Decleration
    int toggle_nbits_from_pos(int val, int n, int p)    //Return type and Parameter type is int
    {
       int res = val^(~(~0<<n)<<(p-n+1));               // Using XOR for togglingthe bits and make unuversal mask
       return res;                                     //Returing the output
     }

