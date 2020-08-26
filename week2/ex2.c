#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main(void)  {
	//-----------------------------------------------------
	char s[20];
	fgets(s, 20, stdin);

	for(int i = strlen(s)-1; i >= 0 ; i--){
	 	if(s[i] != '\n' )
		   printf("%c", s[i]);
	 }
	printf("\n");
	return 0;
}
