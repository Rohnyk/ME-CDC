#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

/* Execute the command using this shell program.  */
#define SHELL "/bin/sh"


int main(){
	fork();
	fork();
	printf("Process ppid: %d pid: %d\n",getppid(),getpid());
	execl("ps -al");

}



/*
Exec family
int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg, ..., 
                               char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[], 
                              char *const envp[]);
                              
                              
*/
