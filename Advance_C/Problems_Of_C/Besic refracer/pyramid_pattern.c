/*
Name : SK SAHIL
Date : 12/06/2022
Discription : A8 - WAP to print pyramid pattern as shown below
Sample I/O : 
Enter the number: 4
4
3 4
2 3 4
1 2 3 4
2 3 4
3 4
4
Test Case 2:
Enter the number: 5
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
*/
#include <stdio.h>
int main() 
{
  // Initiligation and variables
    int  n, i, j;
   // User input
    printf("Enter the number: ");
    scanf("%d",&n);
    //  Condition for printing 1st triangle pattern 
    for(int i = n; i >= 1; i--)
{
for(int j = i ; j <= n; j++)
{
printf("%d ",j);
}
printf("\n");
}
 // Condition for printing lower side of triangle
for(int i = 2; i <= n; i++)
{
for(int j = i ; j <= n; j++)
{
printf("%d ",j);
}
printf("\n");
}
    return 0;
}
