#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


	/**
	  * Since the code for the 3rd task also worked for the 4th task in my case
	  * i just reused the code from the 3rd task as it gives out the same result as
	  * intended
	  */

int main()
{
  char command[100];
  printf("Command should not exceed 100 charachters\nUse \"exit\" to exit the shell\n");
  while(1)
  {
    if(strcmp(command, "exit\n")){
      printf(">");
      fgets(command, 100, stdin);
      system(command);
    }else break;
  }
  return 0;
}