/*
  Name : Sk Sahil 
  Assigment : A20 - WAP to print the factorial of a given number using multithreads
  Pre-requisites:
	Knowledge about multi-thread process, How to read and understand ‘man pages’. 
	Good knowledge about pthread library functions. 
  Objective: 
 	To understand working and flow of multithread programs.
  Requirements: 
	1. Modify the factorial template code using multiple threads. 
	2. Create at-least 3 threads and share the work among threads equally . 
	3. Create and join threads using separate loops . 
	4. You may have to change the argument structure. 
	5. Declare all integer variables as unsigned long int (For max values). ﻿
  Sample execution: 
	1. ./factorial 
	Enter the number :10 
	Factorial of 10 is 3628800
*/


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// struct for store the value
typedef struct sum
{
	int num1,num2;
	int result;
}sumdata_t;

// global variable for lock
pthread_mutex_t lock;

void *fac_func(void *data)
{
	// lock the thread
	pthread_mutex_lock(&lock);
	int result = 1;
	sumdata_t *info = data;
	int n1,n2;
	n1 = info->num1;
	n2 = info->num2;	
	
	for(int i = n1; i <= n2;i++)
	{
		result *= i;
	}

	// unlock the thread
	pthread_mutex_unlock(&lock);
	
	return (void*)(long)result;
	
}

int main()
{
	// variable decleartion
	pthread_t tid1,tid2,tid3;
	sumdata_t data,data2,data3;
	int num;
	int fact = 0;	
	int sum1,sum2,sum3;

	printf("Enter the Number : ");
	scanf("%d",&num);

	// dristbute the value 
	data.num1 = 1;
	data.num2 = (num/3);
	
	data2.num1 = (num/3)+1;
	data2.num2 = num - (num/3);
	
	data3.num1 = num - (num/3) + 1;
	data3.num2 = num;
	
	// initilize the lock
	if(pthread_mutex_init(&lock,NULL) != 0)
	{
		perror("Mutex");
		exit(1);
	}
	// creating thereads
	pthread_create(&tid1,NULL,fac_func,&data);
	pthread_create(&tid2,NULL,fac_func,&data2);
	pthread_create(&tid3,NULL,fac_func,&data3);

	// wait for thread
	pthread_join(tid1,(void**)&sum1);
	pthread_join(tid2,(void**)&sum2);
	pthread_join(tid3,(void**)&sum3);
	
	// print result
	printf("Factorial of %d is : %d\n",num,(sum1*sum2*sum3));

	
	return 0;
}
