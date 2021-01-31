#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

/* Execute the command using this shell program.  */
#define SHELL "/bin/sh"


int main(int argc,char *argv[]){
	printf("%d",argc);
	printf("Inside process 4\n");
	printf("Process pid of process4: %d\n",getpid());
	

}
