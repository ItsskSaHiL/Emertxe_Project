/*
  Name : Sk Sahil
  Assigment : A22 - WAP to multiply two matrices using multiple threads
  Pre-requisites:
	• Knowledge about multi-thread process, How to read and understand ‘man pages’.
 	• Good knowledge about pthread library functions. 
	• Multiplication of two matrices. 
	• Dynamic allocation for 2D array. 
  Objective: 
	• To understand working and flow of multithread programs. 
  Requirements: 
	1. Create three local matrices, M1 MxN M2 NxP and Result MxP (M1 columns = M2 rows) where M, N & P values are provided by user. 
	2. In case M1 columns != M2 rows print error message to user. 
	3. Create all matrices using dynamic allocation. 
	4. Use structure to pass arguments to threads sample structure. 
    	typedef struct thread_data {    
    		 short m1_row;       
    		 short m1_col;        
    		 short m2_col;       
    		 int **matrix1;         
    		 int **matrix2;        
    		 int **result;        
    		 short cur_row;
    	    }Thread_data_t; ﻿
	5. Each thread will calculate and store single row in result. So number of threads equals number of rows in M1. ﻿

		Eg: M1= 1 2 3               M2 = 1 1 1
	                1 1 1                    2 2 2
	                2 2 2                    3 3 3

	Thread 1 : M1 row1 x M2 col1, col2, col3 
                	        1x1 + 2x2 + 3x3 1x1 + 2x2 + 3x3 1x1 + 2x2 + 3x3
        	                14  14  14

	Thread 2 : M1 row2 x M2 col1, col2, col
				 1x1 + 1x2 + 1x3 1x1 + 1x2 + 1x3 1x1 + 1x2 + 1x3 
				 6 6 6 
	Thread 3 : M1 row3 x M2 col1, col2, col3 
  				2x1 + 2x2 + 2x3 2x1 + 2x2 + 2x3 2x1 + 2x2 + 2x3 
  				12 12 12 6. 
		﻿﻿Don't create any global variables. 
	7. Create generic function for matrix dynamic allocation and deallocating.﻿

  Sample execution: -
	 1. ./matrix_mul 
	Enter M1 rows and columns 3  3 
	Enter M2 rows and columns 3  3
	Enter M1 values 1  2  3  1  1  1  2  2  2
	Enter M2 values 1  2  3  1  2  3  1  2  3 
	Result is 
	14 14 14 
	6 6 6 
	12 12 12
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* A structure to hold multiple arguments */
typedef struct thread_data
{
		short m1_row;
		short m1_col;//m2_row must be equal to m1_col
		short m2_col;
		int **matrix1;
		int **matrix2;
		int **result;
		short cur_row;
}Thread_data_t;

void matrix_dynamic_allocation(int*** matrix, short rows, short cols)
{
		*matrix = malloc(rows * sizeof(int*));
		for (short i = 0; i < rows; i++)
		{
				(*matrix)[i] = calloc(cols, sizeof(int));
		}
}

void fill_up_matrix(int** matrix, short rows, short cols)
{
		for (short row = 0; row < rows; row++)
		{
				for (short col = 0; col < cols; col++)
				{
						printf("Enter row-%d:col-%d: ", row + 1, col + 1);
						scanf("%d", &matrix[row][col]);
						/*Tried to scan on single line, but didn't work*/
						//getchar();
						//printf("\t");
				}
				//printf("\n");
		}
}

void print_matrix(int** matrix, short rows, short cols)
{
		for (short row = 0; row < rows; row++)
		{
				for (short col = 0; col < cols; col++)
				{
						printf("%d\t", matrix[row][col]);
				}
				printf("\n");
		}
}

void free_dynamic_memory(int** matrix, short cols)
{
		for (short i = 0; i < cols; i++)
		{
				free(matrix[i]);
		}
		free(matrix);
}

//Initialize mutex as fast mutex
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void* thread_fun(void* arg)
{
		Thread_data_t* ptr = (Thread_data_t*)arg;
		pthread_mutex_lock(&mut);//Lock the shared resource
		for (short cur_col = 0; cur_col < ptr -> m2_col; cur_col++)
		{
				//Keep in mind: m1_col = m2_row.
				//Let's call it 'rc' to avoid confusion
				//Also note that our result matrix was initially having all zeros because of calloc()
				for (short rc = 0; rc < ptr -> m1_col; rc++)
				{
						ptr -> result[ptr -> cur_row][cur_col] += (ptr -> matrix1[ptr -> cur_row][rc]) * (ptr -> matrix2[rc][cur_col]);
				}
		}
		++(ptr -> cur_row);
		pthread_mutex_unlock(&mut);//Unlock the shared resource
}

int main()
{
		Thread_data_t data;
		short m2_rows;
		printf("Enter Matrix 1 rows: ");
		scanf("%hd", &(data.m1_row));
		printf("Enter Matrix 1 columns: ");
		scanf("%hd", &(data.m1_col));
		printf("Enter Matrix 2 rows: ");
		scanf("%hd", &m2_rows);
		if (data.m1_col != m2_rows)
		{
				printf("Sorry! Matrix multiplication is not possible!\nPlease ensure the no. of Matrix 1 columns equals the no. of Matrix 2 rows\n\n");
				exit(EXIT_FAILURE);
		}
		printf("Enter Matrix 2 columns: ");
		scanf("%hd", &(data.m2_col));

		//Create all matrices using dynamic allocation
		//Matrix 1: m1_row x m1_col
		matrix_dynamic_allocation(&data.matrix1, data.m1_row, data.m1_col);
		//Fill up matrix 1
		printf("\n-------Fill up Matrix 1-------\n");
		fill_up_matrix(data.matrix1, data.m1_row, data.m1_col);
		//Matrix 2: m1_col x m2_col
		matrix_dynamic_allocation(&data.matrix2, data.m1_col, data.m2_col);
		//Fill up matrix 1
		printf("\n-------Fill up Matrix 2-------\n");
		fill_up_matrix(data.matrix2, data.m1_col, data.m2_col);
		//Result: m1_row x m2_col
		matrix_dynamic_allocation(&data.result, data.m1_row, data.m2_col);

		//Set current row in the structure as row 0
		data.cur_row = 0;

		//Display matrix 1 and matrix 2
		printf("\n-------Matrix 1-------\n");
		print_matrix(data.matrix1, data.m1_row, data.m1_col);
		printf("\n-------Matrix 2-------\n");
		print_matrix(data.matrix2, data.m1_col, data.m2_col);

		short NO_OF_THREADS = data.m1_row; 
		pthread_t tid[NO_OF_THREADS];//Thread Ids

		//Thread create
		for (short i = 0; i < NO_OF_THREADS; i++)
		{
				pthread_create(&tid[i], NULL, thread_fun, &data);
		}

		//Thread join
		for (short i = 0; i < NO_OF_THREADS; i++)
		{
				pthread_join(tid[i], (void**) NULL);
		}

		//Display result matrix
		printf("\n-----Result Matrix----\n");
		print_matrix(data.result, data.m1_row, data.m2_col);

		//Free up dynamic memory space
		free_dynamic_memory(data.matrix1, data.m1_row);
		free_dynamic_memory(data.matrix2, data.m1_col);
		free_dynamic_memory(data.result, data.m1_row);
}
