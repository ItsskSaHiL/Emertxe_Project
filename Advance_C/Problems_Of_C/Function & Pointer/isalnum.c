/*
Name : SK SAHIL
Date : 29/06/2022
Discription : A22 - WAP to implement your own isalnum() function
Sample I/O :
Test Case 1:
Enter the character: a
The character 'a' is an alnum character.
Test Case 2:
Enter the character: ?
The character '?' is not an alnum character.
*/


#include <stdio.h>
 // Function pritotype
int my_isalnum(int);

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character:");
    scanf("%c", &ch);
    
    ret = my_isalnum(ch);
     if(ret)
         printf("The character '%c' is an alnum character.\n",ch);
     else 
         printf("The character '%c' is not an alnum character.\n",ch);
    /*
        Based on return value, print whether ch is alphanumeric or not
    */
}
    // Function Decleration
    int my_isalnum(int ch)                   // Return type and Parameter type is int
    {
           if(( ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                 return 1;
           else 
                 return 0;
             

    }
