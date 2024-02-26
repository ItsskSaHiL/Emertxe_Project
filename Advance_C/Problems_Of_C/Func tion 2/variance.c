/*
Name : SK SAHIL
Date : 12/08/2022
Discription : A46 - Variance calculation with dynamic arrays
Sample I/O :

Test Case 1:
user@emertxe] ./variance
Enter the no.of elements : 10

Enter the 10 elements:
[0] -> 9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31
Variance is 40.000000
*/


#include <stdio.h>
#include <stdlib.h>

 // Function Prototype
   float variance(int *ptr, int size);
int main() {

    // Initilize size of the array
    int arr_size;
    printf("Enter the no. of elements :");
    scanf("%d",&arr_size);

    // Initilize the arr
    int *arr = (int*)malloc(arr_size*sizeof(int));    // Dinamic Memory allocation for the array

    // Input from user
    printf("Enter the %d elements:\n",arr_size);
      for(int i = 0; i < arr_size;i++)
       {
          printf("[%d]->",i);
          scanf("%d",(arr + i));
        }

    // Function call
    float res;
 
    res = variance(arr, arr_size);

    // Printing Variance
    printf("Variance is %f\n",res);
    // Free the pointer
    free(arr);
    return 0;
}
     // Function Decleration
   float variance(int *ptr, int size)
   {
      // variable decleration
       int i,j,k, Mean = 0;
       float Variance = 0;
       // Dynamic array decleration
       int *D = (int*)malloc(size*sizeof(int));
       int *D_sqr = (int*)malloc(size*sizeof(int));
       
      // Adding Array element and find Mean 
      for(i = 0;i < size;i++)
      {
         Mean =  Mean + *(ptr + i);
       }
         Mean = Mean/size;
       
       // Calculating Deviation
        for(j = 0;j < size;j++)
         {
             D[j] = *(ptr + j) - Mean;          
         }

        // Calculating Squar of Diviation
        for(k = 0; k < size;k++)
         {
            D_sqr[k] = D[k] * D[k];
           }
    
         // Calculating veriance 
       for(int l = 0;l  < size; l++)
        {
           Variance = Variance + D_sqr[l];
         }
           
        // Returing Variance 
        Variance = Variance/size;
    
        // Returning Variance
         return Variance;
   }
