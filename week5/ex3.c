#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct {
	int count;
	int capacity;
	int *data;
} buffer;

void* producer(void *vararg)
{
	while(1)
	{
		// buffer full. wait
		while(buffer.count >= buffer.capacity);

		// if race condition happens, stop everything
		if(buffer.count >= buffer.capacity)
		{
			printf("FATAL ERROR! Trying to produce to a full buffer");
			exit(1);
		}

		// insert data
		buffer.data[buffer.count] = buffer.count;	// rand();
		buffer.count++;
	}
}
void* consumer(void *vararg)
{
	while(1)
	{
		// buffer empty, wait
		while(buffer.count <= 0);

		// if race condition happens, stop everything
		if(buffer.count <= 0)
		{
			printf("FATAL ERROR! Trying to consume from an empty buffer");
			exit(1);
		}

		// consume data
		buffer.data[buffer.count] = 0;
		buffer.count--;
	}
}

int main()
{
	buffer.capacity = 2;
	buffer.count = 0;
	buffer.data = (int*) malloc(buffer.capacity * sizeof(int));

	pthread_t prod, cons;

	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);

	pthread_join(prod, NULL);
	pthread_join(cons, NULL);

	return 0;
} 
