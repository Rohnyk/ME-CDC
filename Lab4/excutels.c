#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 


int main(int argc,char* argv[])
{
	int pid=fork();
	if(pid==-1)
    {
    	printf("can't fork,error\n");
    	exit(0);
    }
    else
    	if(pid==0)
    	{
           char* args[2]={argv[1],NULL};
           printf("child process\n");
           execv(args[0],args);
           //exit(0);
    	}
}