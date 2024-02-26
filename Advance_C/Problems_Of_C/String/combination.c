/*
Name : SK SAHIL
Date : 05/08/2022
Discription : A43 - WAP to print all possible combinations of given string.  
Sample I/O :
Test Case 1:
user@emertxe] ./combinations
Enter a string: abc

All possible combinations of given string :abc
acb
bca
bac
cab
cba


Test Case 2:
Enter a string: abb
Error: please enter distinct characters.
*/
#include<stdio.h> 

 // Function prototype
void combination(char [],int ,int );
int my_strlen(char []);
void swap (char *x, char *y);
int main()

{
        char str[100];
        int n;
        int res;
        printf("Enter a string: ");
        scanf("%100[^\n]",str);    
        n = my_strlen(str);
        combination(str,0,n-1);                       
        return 0;
}
 // String length 
   int my_strlen(char *cptr)
   {
       static int len = 0;
       for(int i = 0; *(cptr + i) != '\0';i++)
       {
           len++;
       }
       return len;
   }
   // For swap the charecter
   void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Print all posible combination for distinct string
void combination(char *a, int i, int n)
{
     for(int k = 0; k <= n; k++)
       {
           for(int l = k + 1;l <= n;l++)
           {
               if(*(a + k) == *(a + l))
               {
                 printf("Error: please enter distinct characters.");
                 return;
               }
           }
       }
   
   static int count = 0;
       if(count == 0)
       {
           printf("All possible combinations of given string :%s\n",a);
           count++;
       }
    int j;
    if (i == n)
        printf("%s\n", a);
    else {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            combination(a, i + 1, n);
            swap((a + i), (a + j)); 
        }
    }
}
