#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


	/*
	 * Order of printing is mixed and unpredictable.
	 * Main thread can sometimes print first, 
	    and other times the new thread would print first.
	 */

void* tFunc(void* arg)
{
	printf("This is thread #%lu\n", *(unsigned long*)arg);
	pthread_exit(NULL);
}

int main()
{
	int N;
	printf("Enter the number of threads: ");
	scanf("%d", &N);

	for(int i=1; i<=N; i++)
	{
		pthread_t thread_id;
		pthread_create(&thread_id, NULL, tFunc, &thread_id);
		printf("Created thread #%d\n", i);
	}	
	return 0;
} 
