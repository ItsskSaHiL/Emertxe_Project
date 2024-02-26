/*
Name : SK SAHIL
Date : 09/07/2022
Discription : A29 - WAP to find factorial of given number using recursion
Sample I/O :
Test Case 1:
Enter the value of N : 7
Factorial of the given number is 5040
Test Case 2:
Enter the value of N : 5
Factorial of the given number is 120
Test case 3:
Enter the value of N : -1
Invalid Input
Test case 4:
Enter the value of N : 0
*/
#include <stdio.h>

int main()
{
    static int num;
    static int count = 0;      // Using this for use one time scan f statement
    static unsigned long long int fact = 1;
   // Using the count value for one time user input
  if(count == 0)
  {
       // User input
   printf("Enter the value of N:");
        scanf("%d", &num);
        // Condition for invalid input 
        if (num < 0)
        {
            printf("Invalid input\n");
            return 0;
        }
        count ++;   // Increment of count cause we cant use this block
  }
     // Logic for factorial
    if (num > 0)
    {
        fact = fact * num;
        num--;         // Decrement of static var num
        main();     // Calling again the main function
    }
    else
    printf("Factorial of the given number is %llu\n", fact); //Print the op
}
