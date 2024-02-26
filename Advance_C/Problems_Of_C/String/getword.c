/*
Name : SK SAHIL
Date : 20/07/2022
Discription :  A35 - WAP to implement getword function 
Sample I/O :
est Case 1:
user@emertxe] ./getword
Enter the string : Welcome to Emertxe
You entered Welcome and the length is 7

Test Case 2:
user@emertxe] ./getword
Enter the string : Hello
You entered Hello and the length is 5
*/

#include <stdio.h>
   // Function Prototype
int getword(char str[]);

int main()
{
        int len = 0;
	    char str[100];

		printf("Enter the string : ");
		scanf(" %99[^\n]", str);

		len = getword(str);

        printf("You entered %s and the length is %d\n", str, len);
}
       // Function Decleartion 
        int getword(char str[])
     {
         // Local variable of this function
         int i, count = 0;
         // Using Char pointer for cheacking the charecter 
         char *ptr = str;  
        for( i = 0; i <= 100; i++)    // Using loop 
           {
               // Condition for checking space NULL and tab space 
              if(*(ptr + i) == ' ' || *(ptr + i) == '\0' || *(ptr + i) == '\t')
                 {
                     // If find space or tab then replace with NULL
                     *(ptr + i) = '\0';
                    // Break the loop 
                      break;
                 }
               else 
                   count++;   // Increment the count value 
             }
          return count;       // Returning the count value
       }

        
