#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main()
{
	int p1,p2,p3;
	p1=fork();
	if(p1==-1)
    {
    	printf("can't fork,error\n");
    	exit(0);
    }
	else if(p1==0)
	{
	  printf("Child 1 pid=%d\n and ppid=%d",getpid(),getppid());	
     
	}
	else
    {
     	printf("Parent pid=%d\n",getpid());
     	p2=fork();
	    if(p2==-1)
        {
    		printf("can't fork,error\n");
    		exit(0);
        }
    	else
    	if(p2==0)
        {
          printf("Child 2 pid=%d\n and ppid=%d",getpid(),getppid());
        }
        else
        {	
          p3=fork();
	      if(p3==-1)
          {
    	   printf("can't fork,error\n");
    	   exit(0);
          }
          else
         	if(p3==0)
         	{
         		printf("Child 3 pid=%d\n and ppid=%d",getpid(),getppid());
         	}
        }
    }
}
