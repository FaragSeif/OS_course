#include <stdio.h>
#include <unistd.h>

int main()
{
	 /**
	  * Each process gets forked into 2, each of which get forked into 2 more
	  * The total number of processes will reach 2^N
	  */
	int N = 5;

	for(int i=0; i<N; i++)
	{
		fork();
		sleep(5);
	}
	return 0;
} 
