/*
Name : SK SAHIL
Date : 27/07/2022
Discription : A41 - Squeeze the character in s1 that matches any character in the string s2  
Sample I/O :
Test Case 1:
user@emertxe] ./squeeze
Enter s1 : Dennis Ritchie
Enter s2 : Linux
After squeeze s1 : Des Rtche


Test Case 2:
user@emertxe] ./squeeze
Enter s1 : Welcome
Enter s2 : Emertxe
After squeeze s1 : Wlco
*/

#include <stdio.h>
 // Function Prototype
void squeeze(char *ptr, char *ptr2);

int main()
{
    char str1[30], str2[30];
    
    printf("Enter string1:");
    scanf("%29[^\n]", str1);
     // For Swallow new line for scanf function
    getchar();    

    printf("Enter string2:");
    scanf("%29[^\n]", str2);
    
    squeeze(str1, str2);   // Function call
    
    printf("After squeeze s1 : %s\n", str1);
    
}
  // Function Decleration 
void squeeze(char *ptr, char *ptr2)
{
      
    int i,j,k; // Initiligation of variable
    // First for loof for itterate string 1
    for(i = 0; *(ptr + i) != '\0'; i++)
    {
      // Second for loop for itterate 2nd string
       for(j = 0; *(ptr2 + j) !='\0'; j++)
       {
           // Compare charecter with chater if string 1 and string 2
           if(*(ptr + i) == *(ptr2 + j))
           {
           k = i;  // Initilize value with matching position 
           while(*(ptr + k) != '\0') // Itterate loop for swap the charecter
            {
               *(ptr + k) = *(ptr + k + 1);  // For swaping the charecter
               k++;  
               j = 0;   // When swap string 2 index Initilize with 0
            }
           }  
       }
    }
}
