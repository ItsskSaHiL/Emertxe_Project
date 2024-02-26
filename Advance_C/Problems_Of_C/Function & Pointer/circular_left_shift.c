/*
Name : SK SAHIL
Date : 2/07/2022
Discription : A20 - WAP to implement Circular left shift
Sample I/O :
Test Case 1:
Enter num: 12
Enter n : 3
Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0
Test Case 2: 
Enter num: -2
Enter n : 3
Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
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
    int circular_left(int num, int n)            //Return type and Parameter type is int
     {
           int mask1,res;                          // Local variable decleration
           unsigned int num2 = num;                 // Making signed int into unsigned int
           unsigned int mask2;                       // unsigned local variable decleration
           mask1 = num<<n;                           // left shift the number 
           mask2 =  num2>>(32-n);                     // Unsigned right shift 
           res = mask1| mask2;                        // Using OR operation for output    
           return res;                                // Returning value
     }
        // Function Decleration
     int print_bits(int ret)
     {
          for(int i = 31; i>=0;i--)                      // Using loop and right shift with bitwise & operator for print bits
          {
         if(ret&(1<<i))
           printf("1 ");
           else
           printf("0 ");
          }
     }
     
