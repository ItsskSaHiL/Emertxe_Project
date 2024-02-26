/*
  Name : Sk Sahil
  Assigment : A21 - WAP to sum and maximum of a given array using multiple threads.Synchronize threads using mutex.
  Pre-requisites:
	Knowledge about multi-thread process, How to read and understand ‘man pages’. 
	Good knowledge about pthread library functions. 
	Thread synchronization (mutex and semaphores). 
  Objective: 
	To understand need and implementation of thread synchronization. 
  Requirements: 
	1. Create an array[N] (min size 500) with 1 N values and two global variables → global_sum & global_max. 
	2. Create multiple threads to find sum of array and maximum value in array. 
	3. Threads will share array equally among them. Means each thread will access different part of array at same time. 
	4. Create at-least 5 threads. Create and join threads using separate loops. 
	5. Each thread will update global_sum and global_max. 
	6. Since we are accessing global variable from threads, do proper synchronization using mutex.
  Sample execution: 
	1. ./sum_max
	Enter the size of array : 100
	max = 100 Sum = 5050

*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct sum
{
	int num1,num2;
	int result;
}sumdata_t;

// global variable for lock
pthread_mutex_t lock;

void *sum_func(void *data)
{
	// lock the thread
	pthread_mutex_lock(&lock);
	int result = 0;
	sumdata_t *info = data;
	int n1,n2;
	n1 = info->num1;
	n2 = info->num2;	
	
	for(int i = n1; i <= n2;i++)
	{
		result += i;
	}

	// unlock the thread
	pthread_mutex_unlock(&lock);
	
	return (void*)(long)result;
	
}

int main()
{
	pthread_t tid1,tid2,tid3,tid4,tid5;
	sumdata_t data1,data2,data3,data4,data5;
	int num;
	int fact = 0;	
	int sum1,sum2,sum3,sum4,sum5;

	printf("Enter the Number : ");
	scanf("%d",&num);
	
	// error check
	if(num > 500 || num < 0)
	{
		printf("Enter Valid Number  0 to 500 \n");
		return 2;	
	}
	data1.num1 = 1;
	data1.num2 = (num/5);
	
	data2.num1 = (num/5)+1;
	data2.num2 = (num/5 + num/5) ;
	
	data3.num1 = (num/5)+ (num/5) + 1;
	data3.num2 = (num/5) + (num/5) + (num/5);

	data4.num1 = (num/5) + (num/5) + (num/5) + 1;
	data4.num2 = (num/5) + (num/5) + (num/5) + (num/5);
	
	data5.num1 = (num/5) + (num/5) + (num/5) + (num/5) + 1;
	data5.num2 = num;
	
	// initilize the lock
	if(pthread_mutex_init(&lock,NULL) != 0)
	{
		perror("Mutex");
		exit(1);
	}
	// creating the 1st theread
	pthread_create(&tid1,NULL,sum_func,&data1);
	pthread_create(&tid2,NULL,sum_func,&data2);
	pthread_create(&tid3,NULL,sum_func,&data3);
	pthread_create(&tid4,NULL,sum_func,&data4);
	pthread_create(&tid5,NULL,sum_func,&data5);

	pthread_join(tid1,(void**)&sum1);
	pthread_join(tid2,(void**)&sum2);
	pthread_join(tid3,(void**)&sum3);
	pthread_join(tid4,(void**)&sum4);
	pthread_join(tid5,(void**)&sum5);
	
	printf("max = %d \n",num);
	printf("sum = %d \n",(sum1+sum2+sum3+sum4+sum5));
	
	return 0;
}
