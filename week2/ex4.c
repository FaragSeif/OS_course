#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string.h>

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main(void)  {

	int n1,n2;
	printf("Enter the first number: ");
	scanf("%d", &n1);
	printf("Enter the second number: ");
	scanf("%d", &n2);
	swap(&n1,&n2);
  printf("The First number after swap is: %d\n", n1);
	printf("The Second number after swap is: %d\n", n2);

	return 0;
}
