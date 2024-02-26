/*
Name : SK SAHIL
Date : 24/07/2022
Discription :  A40 - WAP to implement strtok function
Sample I/O :
Test Case 1:
user@emertxe] ./my_strtok
Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
Mumbai

Test Case 2:
user@emertxe] ./my_strtok
Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
Enter string2 : ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
*/
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
  // Function prototype
char *my_strtok(char str[], const char delim[]);

int main()
{
    char str[50], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
    
    __fpurge(stdout);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    __fpurge(stdout);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}
  // Function decleration
  char *my_strtok(char str[], const char delim[])
  {
      // Use static pointer for contionous form
  static char * index;

  
  if (str != NULL)
  {
    index = str;
  }
  else
  {
    str = index;
  }

  if ( * index == '\0') 
  {
    return NULL;
  }
     // Making delimiter as null 
  while ( * index != '\0') 
  {
     for (int i = 0; delim[i] != '\0'; i++) 
     {
      if ( * index == delim[i])
      {
        if (index == str)
        {
          index++;
          str++;
        }
        else 
        {
          * index = '\0';
          break;
        }
      }
    }
     // Return the address
    if ( * index == '\0')
    {
      index++;
      return str;
    }

    index++;
  }
  return str;

}

