#include <stdio.h>
#include <unistd.h>

int main()
{
	/*
	 * fork() returns the PID of the child process to the parent, and 0 to the child. (souce: stackoverflow)
	 * getpid() will return the PID of the process who called it
	 */
	int n = fork();
	char *processName;
	if(n != 0)
		processName = "parent";
	else
		processName = "child";
	printf("Hello from %s [%d - %d]\n", processName, getpid(), n);
	return 0;
} 
