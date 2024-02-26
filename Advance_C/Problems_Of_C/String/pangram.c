/*
Name : SK SAHIL
Date : 27/07/2022
Discription : A44 - WAP to check given string is Pangram or not  
Sample I/O :
Test Case 1:

Enter the string: The quick brown fox jumps over the lazy dog

The Entered String is a Pangram String

Test Case 2:

Enter the string: The quick brown fox jumps over the dog

The Entered String is not a Pangram String
*/
#include <stdio.h>
// Function prototype 
int pangram(char *cptr);

int main()
{
    char str[100];
        int res;
        printf("Enter a string: ");
        scanf("%99[^\n]",str);
        res = pangram(str);// Return the function 
        if(res)    // For checking Pangram or not
        printf("The Entered String is a Pangram String");
        else
        printf("The Entered String is not a Pangram String");
}
   // Function Definition 
   int pangram(char *cptr)
   {
        // For captial letter
       const char cptrA[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        // Array for small letter
        const char cptra[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
         // Integer array which initilize with zeros
        int arr[26] = {0};
       // Using some local variable for loop itterate
       int i = 0,j,k;
       
       //loop for fetch string
       while(*(cptr + i) != '\0')
       {
       for(j = 0;j < 26;j++)
       {
           // Condition for checking the match charecter
           if((*(cptr + i) == cptrA[j]) || (*(cptr + i) == cptra[j]))
           {
            // Then the equvalent array index is initilize with 1
           arr[j] = 1;
           continue;
           }
       }
       i++;
       }
   // Initilize a varibale 
     int sum = 0;
       // Addding all the 26 array number 
       for(k = 0; k < 26;k++)
       {
           sum = sum + arr[k];
        }
           // Then check sum is equal to 26
           if(sum == 26)
           return 1;
           else
           return 0;
       
      
   }
