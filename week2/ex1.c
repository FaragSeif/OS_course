#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main(int argc, char** argv)  {
	int n;
	float f;
	double d;
	n = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;
	printf("%lu",sizeof(n));
	printf("\n");
	printf("%lu",sizeof(f));
	printf("\n");
	printf("%lu",sizeof(d));
	printf("\n");
	return 0;
}
