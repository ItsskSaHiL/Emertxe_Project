/*
Name : SK SAHIL
Date : 12/08/2022
Discription : A51 - WAP to find the product of given matrix.
Sample I/O :

Test case1:
user@emertxe] ./transpose_product
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :

1      1     1
2      2     2
3      3     3
Product of two matrix :
14      14      14
14      14      14
14      14      14

Test case 2:
user@emertxe] ./transpose_product
Enter number of rows : 3
Enter number of columns : 3
Enter values for 3 x 3 matrix :
1      2      3
1      2      3
1      2      3
Enter number of rows : 2
Enter number of columns : 3
Matrix multiplication is not possible
*/

#include <stdio.h>
#include <stdlib.h>

 // Function Prototype 
     void Matrix_mul(int row1, int col1, int *A[col1],int row2, int col2, int *B[col2]);
int main()
{
    // Variable Decleration
     int row1,row2,col1,col2;

      // FOR THE MATRIX NO - 1 
    
     // Input From user for Matrix 1
      printf("Enter ROW-1 and COL-1 value : ");
      scanf("%d%d",&row1,&col1); 

    // Initilize the 2d array 
     int **a1;
     int i,j;
    // Both Dynamic Array decleration
     a1 = malloc(row1 * sizeof(int *));
    // Dynamic memory allocate for collums
     for (i = 0; i < row1; i++)
     {
     a1[i] = malloc(col1 * sizeof(int));
      } 
    
    // User input for Array element
     printf("Enter the array element :\n");
     for(i = 0;i < row1;i++)
      {
      for(j = 0; j < col1;j++)
      {
         printf("a1[%d][%d]->",i,j);
          scanf("%d",(a1[i] + j));
       }
      
       }
 
     // FOR MATRIX NO - 2
         
     // Input From user for Matrix 2
      printf("Enter ROW-2 and COL-2 value : ");
      scanf("%d%d",&row2,&col2);

    // Check if multiplication is Possible
    if (row2 != col1)
    {
        printf(" Multiplication is Not Possible\n");
        return 0;
    }
    else
     {
    // Initilize the 2d array
     int **a2;
 
    // Both Dynamic Array decleration
     a2 = malloc(row2 * sizeof(int *));
    // Dynamic memory allocate for collums
     for (i = 0; i < row2; i++)
     {
     a2[i] = malloc(col1 * sizeof(int));
      }

    // User input for Array element
     printf("Enter the array element :\n");
     for(i = 0;i < row2;i++)
      {
      for(j = 0; j < col2;j++)
      {
          printf("a1[%d][%d]->",i,j);
          scanf("%d",(a2[i] + j));
      }
       }
          
    Matrix_mul(row1,col1,a1,row2,col2,a2);
 return 0;
    }
}

  // Function decleration
     void Matrix_mul(int row1, int col1, int *A[col1],int row2, int col2, int *B[col2])
      {
    // Initilize variable
    int i, j, k;
 
    // Matrix to store the result
    int *C[row1];
    // Dynamically memori allocation 
     for(i = 0;i < row1;i++)
     {
      C[i] = calloc(col2,sizeof(int));
     }
  
    // Multiply the two
    for (i = 0; i < row1; i++) 
    {
        for (j = 0; j < col2; j++) 
        {
            for (k = 0; k < row2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
 
    // Print the result
    printf("\nResultant Matrix: \n");
     
     for (int i = 0; i < row1; i++) 
     {
        for (int j = 0; j < col2; j++)
            printf("%d ",C[i][j]);

        printf("\n");
    }

}


