/*
Name : SK SAHIL
Date : 2/07/2022
Discription : A19 - WAP to put the (b-a+1) lsb’s of num into val[b:a]
Sample I/O :
Enter the value of 'num' : 11
Enter the value of 'a' : 3
Enter the value of 'b' : 5
Enter the value of 'val': 174
Result : 158
*/


#include <stdio.h>
      // Function Prototype
int replace_nbits_from_pos(int, int, int, int);

int main()
{
    int num, a, b, val, res = 0;
    
    printf("Enter num, a, b, and val:");
    scanf("%d%d%d%d", &num, &a, &b, &val);
    
    res = replace_nbits_from_pos(num, a, b, val);
    
    printf("Result = %d\n", res);
} 
  // Function Decleration
  int replace_nbits_from_pos(int num, int a, int b, int val)         //Return type and Parameter type is int
  {
      if(a<=b&&b<=31)                                                  // Condition for perfect bits position
      {
          int pos,mask1,num2,mask2,mask3,val2,val3;                     // Local variable decleration
          pos = (b-a+1);                                                 // Calculating bit position
          mask1 = ((1<<pos)-1);                                          // creatin mask for fetch no of require bits 
          num2 = num&mask1;                                              // Storing the fetch value in a variable  
          mask2 = (num2<<(b-pos+1));                                       // Changing the position of bits of the fetch data
          mask3 = ~(~(~0<<pos)<<(b-pos+1));                                // Creating mask for clear bit from position to require no of position
          val2 = val&mask3;                                                // clear the bits from val
          val3 = val2|mask2;                                               // Using OR operator to replace the bit position
          return val3;                                                     // Returning the value
      }
       else
           {
               printf("please satisfied this condition a<=b<=31");             // Print the error
               return 0;
            }
  }
