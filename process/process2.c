#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 



int main(){
	printf("Inside process 2\n");
	printf("Process ppid: %d pid: %d\n",getppid(),getpid());
	char *args[] = {"Hello", "process","World",NULL};
	execv("./process4",args);
	printf("Back to process2.c");

}
