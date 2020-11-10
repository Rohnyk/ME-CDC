#include<stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Execute the command using this shell program.  */
#define SHELL "/bin/sh"
int my_system (const char *command);


int main(){
    printf("Inside process 6\n");
    int parent_status;
	printf("Process ppid: %d pid: %d\n",getppid(),getpid());
	char *args = "ls";
	parent_status = my_system(args);
	printf("Parent status %d",parent_status);
    return 0;
}

int my_system (const char *command)
{
  int status;
  pid_t pid;

  pid = fork ();
  printf("Inside process 6 - child\n");
  printf("Process ppid: %d pid: %d\n",getppid(),getpid());

  if (pid == 0)
    {
      /* This is the child process.  Execute the shell command. */
      execl (SHELL, SHELL, "-c", command, NULL);
      _exit (EXIT_FAILURE);
    }
  else if (pid < 0)
    /* The fork failed.  Report failure.  */
    status = -1;
  else
    /* This is the parent process.  Wait for the child to complete.  */
    if (waitpid (pid, &status, 0) != pid)
      status = -1;
  return status;
}
