/*
Name : SK SAHIL
Date : 05/08/2022
Discription : A42 - Generate consecutive NRPS of length n using k distinct character  
Sample I/O :
Test Case 1:
user@emertxe] ./nrps
Enter the number characters C : 3
Enter the Length of the string N : 6
Enter 3 distinct characters : a b c
Possible NRPS is abcbca

Test Case 2:
Enter the number characters C : 3
Enter the Length of the string N : 7
Enter 3 distinct characters : a b a
Error : Enter distinct characters
*/
#include <stdio.h>
// Function prototype
void nrps(char str[] , int len, int k);

int main()
{
    int n, k, i, j;
    char kdistinct[255];
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    /* boundary check */
    /* Error Check for limit */
    if ((n < 0) || (n > 3628800))
    {
        printf("Error: Invalid Number. Retry\n");
        return 1;
    }
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    /* Error Check for limit */
    if ((k < 1) || (k > 10))
    {
        printf("Error: Invalid Number. Retry\n");
        return 1;
    }
    
    printf("Enter the k disctint characters: \n");
    for (i = 0; i < k; i++)
    {
          scanf("\n%c", &kdistinct[i]);
    }
    
    /* check for distinct characters */
    for (i = 0; i < k; i++)
    {
        for (j = (i+1); j < k; j++)
        {
            if(kdistinct[j] == kdistinct[i] )
            {
                printf("Error: values are not distinct.\n");
                return 1;
            }
        }
    }
    
    nrps(kdistinct, n, k);
      return 0;
}
 // For creat NRPS
void nrps(char str[] , int len, int k)
{
    int i, val = 0, count = 0;
    
    for (i = 0; i < len; i++)
    {
        if(i%k == 0 && i != 0)
		{
			val++;
		}
        printf("%c", *(str+((i+val)%k)));
    }
    
}
