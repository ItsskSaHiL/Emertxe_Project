/*
Name : SK SAHIL
Date : 2/07/2022
Discription : A21 - WAP to implement Circular right shift
Sample I/O :
Test Case 1:
Enter num: 12
Enter n : 3
Result : 10000000 00000000 00000000 00000001
Test Case 2: 
Enter num: -12
Enter n : 3
Result : 10011111 11111111 11111111 11111110
*/
#include <stdio.h>
     // Function Prototype
int circular_left(int, int);
int print_bits(int);

int main()
{
    int num, n, ret;
    
    printf("Enter the num:");
    scanf("%d", &num);
    
    printf("Enter n:");
    scanf("%d", &n);
    
    ret = circular_left(num, n);
    
    print_bits(ret);
}
        // Function Decleration
    int circular_left(int num, int n)         //Return type and Parameter type is int
     {
           int mask2,res;                     // Local variable decleration
           unsigned int num2 = num;            // Making signed int into unsigned int
           unsigned int mask1;                 // unsigned local variable decleration
           mask1 = num2>>n;                    //making mask1 as unsigned right shift
           mask2 =  num<<(32-n);               // Signed left shift
           res = mask1| mask2;                  // Using OR operation for output     
           return res;                         // Returning value
     }
        // Function Decleration
     int print_bits(int ret)
     {
           printf("Result in Binary: ");          // Using loop and right shift with bitwise & operator for print bits
          for(int i = 31; i>=0;i--)
          {
         if(ret&(1<<i))
           printf("1 ");
           else
           printf("0 ");
          }
     }
     
