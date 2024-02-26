/*
Name : SK SAHIL
Date : 21/07/2022
Discription :  A36 - WAP to implement atoi function
Sample I/O :
Test Case 1 :
Enter a numeric string: 12345
String to integer is 12345

Test Case 2 :
Enter a numeric string: -12345
String to integer is -12345

Test Case 3 :
Enter a numeric string: +12345
String to integer is 12345

Test Case 4 :
Enter a numeric string: +-12345
String to integer is 0

Test Case 5 :
Enter a numeric string: 12345-
String to integer is 12345

Test Case 6 :
Enter a numeric string: abcd12345
String to integer is 0

Test Case 7 :
Enter a numeric string: 12345abcd
String to integer is 12345
*/
#include <stdio.h>
  // Function prototype
int my_atoi(const char []);

int main()
{
    char str[20];

    printf("Enter a numeric string : ");
    scanf("%s", str);

    printf("String to integer is %d\n", my_atoi(str));
}
   //function Decleration
   int my_atoi(const char str[])
    {
       const char *ptr = str; // Char pointer initilation
        int i = 0, n = 0, num = 0, sign = 1; // Local variable initilation
         
          if (*(ptr + i) == '-')
          {
          sign = -1;
            i++;
           }
           if (*(ptr + i) == '+')
           {
          sign = 1;
            i++;
           }
        while(*(ptr + i) != '\0') // Using loop till NULL
         {
              if(*(ptr + i) >= '0' && *(ptr + i) <= '9')  // Condition for Digit
                {
                    n = *(ptr + i) - '0';  // Clalulating ascii to integer
                    num = num*10 + n;     // Making as an integer
                }
                else
                  break;                   // If not digit then break the loop
                i++;
         }
         return num * sign;                 // Returning the num value
    }
