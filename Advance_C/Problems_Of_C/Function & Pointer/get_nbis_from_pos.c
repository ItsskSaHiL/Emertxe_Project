/*
Name : SK SAHIL
Date : 25/06/2022
Discription : A16 - WAP to get 'n' bits from given position of a number
Sample I/O :
Test Case 1:
Enter the number: 12
Enter number of bits: 3
Enter the pos: 4
Result = 3
Test Case 2:
Enter the number: 15
Enter number of bits: 2
Enter the pos: 2
Result =  3
*/
#include <stdio.h>
   // Function Prototype
int get_nbits_from_pos(int, int, int);

int main()
{
    int num, n, pos, res = 0;
    
    printf("Enter num, n and val:");
    scanf("%d%d%d", &num, &n, &pos);
    
    res = get_nbits_from_pos(num, n, pos);
    
    printf("Result = %d\n", res);
}
    // Function Decleration
   int get_nbits_from_pos(int val, int n, int pos)    // Return type and Parameter type is int
   {
        int mask = ((1<<n)-1);         // Creating a mask for universal
        int val2 = (val>>(pos-n+1));     // Right shift the value bcz the pos start fron 0
        int res = val2&mask;            //  Using bitwise AND operator new crated value store in variables
         return res;                     // Returing the output
    }

