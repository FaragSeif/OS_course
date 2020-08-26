#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main(int argc, char** argv)  {
	int n;
	sscanf(argv[1], "%d", &n);
	for(int i = 0; i < n; i++){

		for(int j = i+1; j<n; j++)
			printf(" ");

		for(int j = 0; j <= 2*i; j++)
			printf("*");

		if(i < n-1) puts("");
	}
	puts("");
	return 0;
}
