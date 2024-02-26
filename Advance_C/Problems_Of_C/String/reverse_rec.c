/*
Name : SK SAHIL
Date : 24/07/2022
Discription :  A39 - WAP to reverse the given string using recursive method
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

// Function prototypr
void reverse_recursive(char str[], int ind, int len);

int main()
{
    char str[30];
    
    
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    // Initilization ind = 0 for base element
    // Initilixition len = string length - 1 bcz without null cherecter 
    int ind = 0, len = (strlen(str) - 1);
    
    reverse_recursive(str, ind, len); 
     
    printf("Reversed string is %s\n", str);
}
   
// Function Decleration
void reverse_recursive(char str[], int ind, int len)
{
    //Condition for strlen/2 number of recurtion
    if (ind < len)
    {
        // For swap the charecter
        char ch = str[ind];
        str[ind] = str[len];
        str[len] = ch;
        // Increment of pointer and decrement of string length
        ind++;
        len--;
        // Again function call
        reverse_recursive(str, ind, len);
    }
}

