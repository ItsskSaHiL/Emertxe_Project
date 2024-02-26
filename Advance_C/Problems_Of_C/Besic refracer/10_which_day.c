/*
Name : SK SAHIL
Date : 16/06/2022
Discription : A9 - WAP to find which day of the year
Sample I/O :
Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 2
The day is Tuesday
Test Case 2:
Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 3
The day is Wednesday
Test Case 3: 
Enter the value of 'n' : 9

Choose First Day :

1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 8
Error: Invalid input, first day should be > 0 and <= 7
Test Case 4:

Enter the value of 'n' : 0
Error: Invalid Input, n value should be > 0 and <= 365
Test Case 5:
Enter the value of 'n' : 366
Error: Invalid Input, n value should be > 0 and <= 365 
*/
#include <stdio.h>
int main() 
{   
    // Initillition and variables
    int n, sd, rem, day, day2;
    // For user  input 
    printf("Enter the value of 'n' : ");
    scanf("%d",&n);
    printf(" 1.Sunday\n 2.Monday\n 3.Tuesday\n 4.Wednesday\n 5.Thursday\n 6.Friday\n 7.Saturday\n");
    printf("Enter the option to set the first day : ");
    scanf("%d",&sd);
    // Check condition for pass correct Nth number
    if( n <= 365 && n >= 1)
    {
        // Check condition for pass correct date no 
        if(sd<=7 && sd>=1)
        {
         // Arithmatic operation for getting reminder 
        rem = n % 7;
        // From the require date 
        day = sd + rem - 1;
        // Condition for check day also for switch case
        if(day<=7 && day>0)
        {
           // Using switch for printing require output 
            switch(day)
    {
        case 1:printf("The day is Sunday\n");
                break;
        case 2: printf("The day is Monday\n");
                 break;
        case 3:printf("The day is Tuesday\n");
                break;
        case 4: printf("The day is Wednesday\n");
                 break;
        case 5:printf("The day is Thursday\n");
                break;
        case 6: printf("The day is Friday\n");
                 break;
        case 7:printf("The day is Saturday\n");
                break;
    }
        }
     // If calculating of day is > 7 then 
    else
    {
        // using another arithmatic operation for print require output 
        day2 = day % 7;
         switch(day2)   // Max range of case is = 7 - 6 - 1 = 12 and 12 % 7 = 5 so only 5 switch case 
       {
          
        case 1:printf("The day is Sunday\n");
                break;
        case 2: printf("The day is Monday\n");
                 break;
        case 3:printf("The day is Tuesday\n");
                break;
        case 4: printf("The day is Wednesday\n");
                 break;
        case 5:printf("The day is Thursday\n");
                break;
         case 0:printf("The day is Saturday\n");
                break;
            
    }
    }
    }
          // Those are for printong error for not require input 
    else
             printf("Error: Invalid input, first day should be > 0 and <= 7\n");
    }
         else 
            printf("Error: Invalid Input, n value should be > 0 and <= 365\n");
         
    return 0;
}
