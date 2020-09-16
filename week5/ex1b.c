#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

	/*
	 * the main thread now will wait until the created thread exits to create the new one.
	 * The ID printed will be the same for all of them, 
	    since the ID is free to use
	*/

void* thread_func(void* arg)
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
		pthread_create(&thread_id, NULL, thread_func, &thread_id);
		printf("Created thread #%d\n", i);
		pthread_join(thread_id, NULL); // new line from the previous code
	}	
	return 0;
} 
