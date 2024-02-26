/*
Name : SK SAHIL
Date : 22/07/2022
Discription :  A38 - WAP to reverse the given string using iterative method
Sample I/O :
Test Case 1:
user@emertxe] ./str_rev
Enter a string : Hello World
Reverse string is : dlroW olleH

Test Case 2:
user@emertxe] ./str_rev
Enter a string : EMERTXE
Reverse string is : EXTREME
*/


#include <stdio.h>
#include <string.h>
   // Function Protypep
void reverse_iterative(char str[]);

int main()
{
    char str[30];

    printf("Enter any string : ");
    scanf("%29[^\n]", str);


   reverse_iterative(str);

    printf("Reversed string is : %s\n", str);
}
     // Function Decleration
   void reverse_iterative(char str[])
   {
     int n = strlen(str);    // string length

  for (int i = 0; i < n / 2; i++)   // Using loop
  {
    char ch = str[i];          // swap the charecter
    str[i] = str[n - i - 1];
    str[n - i - 1] = ch;
  }

   }
