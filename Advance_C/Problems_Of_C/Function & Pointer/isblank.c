#include <stdio.h>

int my_isblank(int);

int main()
{
    char ch;
    int ret;
    
    printf("Enter the character:");
    scanf("%c", &ch);
    
    ret = my_isblank(ch);
 
     /*   
     Based on return value, print whether ch is blank character or not
    */
}
      // Function Decleration
    int my_isblank(int n)                   // Return type and Parameter type is int
    {
       
           if(n == 32 || n == 9)
                printf("The character is an blank character.\n");
           else 
                   printf("The character is not an blank character.\n");

    }

