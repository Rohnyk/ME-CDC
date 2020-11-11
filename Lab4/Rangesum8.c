#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 

int main(int argc,char * argv[])
{ 
  if(argc!=3)
  {
   printf("Too less or too many arguments");
   exit(1);
  }
  int cp[2],count[2],min,max;
  min=atoi(argv[1]);
  max=atoi(argv[2]);
  printf("%d,%d",min,max);
   if(min>max)
   {
   	printf("min greater then max");
   exit(0);	
   }
  else
   if(min<1000 || min>9999) 
  {
   printf("Invalid min");
   exit(0);	 
   }
   else
  if(max<1000 || max>9999)
  {
    printf("Invalid max");
    exit(0);	 
  }

  if (pipe(cp) < 0) 
        exit(1); 
  if(pipe(count)<0)
  	exit(1);
  int pid=fork();
  if (pid == -1){ 
 
	printf("can't fork, error occured\n"); 
	exit(EXIT_FAILURE); 
    }
    else
    if(pid==0) 
    {
    	close(cp[0]);
     	close(count[0]);
    	printf("child process, pid = %u\n",getpid());
    	int list[150],k=0;
    	for(int i=min;i<=max;i++)
    	{
    		int sum=0;
    		int n=i;
    		while(n>0)
    		{
    			sum+=(n%10);
    			n/=10;
    		}
    	   if(sum==8)
    	   {
    	   	printf("%d\n",i);
    	   	list[k++]=i;
    	   }

    	}
        write(cp[1], list, sizeof(list));
        write(count[1],&k,sizeof(k));
        close(cp[1]);
        close(count[1]);
    	exit(0);

    }
    else
     {
     	close(cp[1]);
     	close(count[1]);
     	int k,getlist[150];
     	printf("Parent id:%d\n",getpid());
     	printf("Parent is waiting\n");
     	wait(NULL);
     	printf("Parent printing\n");
     	read(cp[0],getlist,sizeof(getlist));
     	read(count[0],&k,sizeof(k));
     	close(cp[0]);
     	close(count[0]);
     	for(int i=0;i<k;i++)
     		printf("%d\n",getlist[i]);
        exit(0);
     }	

}