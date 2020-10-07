//i'm working with WSL terminal so i couldn't generate the vmstat text file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB (1024*1024)

int main()
{
	int *data = NULL;
	size_t size = 0;
	for(int i=0; i<10; i++)
	{
		size += 10*MB;
		data = realloc(data, size);
		if(data == NULL)
		{
			printf("Error occured!\n");
			exit(1);
		}
		memset(data, 0, size);
		sleep(1);
	}

	free(data);
	return 0;
} 
