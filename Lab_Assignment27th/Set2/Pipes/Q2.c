#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>



int sum(int n)
{
	static int sum=0;
	sum+=n;
    return sum;    
}

float average(int n)
{
	static int i=0;
	i+=1;
	static int sum2=0;
	sum2+=n;
	return (float)sum2/i;
}

int product(int n)
{
	static int product=1;
	product*=n;
}

typedef struct values
{
	int sum;
	int productn;
	float avgn;
} values;

void main()
{

	int n;
	pid_t pid;
	int status1[2],status2[2],fd1[2],state;
    values ans;
	if(pipe(fd1)==-1)
		fprintf(stderr,"data pipe failed");
	if(pipe(status1)==-1)
		fprintf(stderr,"status1 pipe failed");
	if(pipe(status2)==-1)
		fprintf(stderr,"status2 pipe failed");
	pid=fork();
	if(pid==-1)
	{
		perror("Fork not working");
		exit(0);
	}
	else
	if(pid==0)
	{
    state=0;
    close(fd1[0]);
    close(status1[0]);
    close(status2[1]); 
	do
	{
    if(state==0){
	printf("Enter the number:\n");	
	scanf("%d",&n);
	if(n==999)
	{
		state=999;
        write(status1[1],&state,sizeof(state));
		exit(0);
	}
	ans.sum=sum(n);
	ans.avgn=average(n);
	ans.productn=product(n);
	write(fd1[1],&ans,sizeof(ans));
	state=1;
	write(status1[1],&state,sizeof(state));
   }
   read(status2[0],&state,sizeof(state));
   }while(1);
   }
   else
   {
   	 close(fd1[1]);
     close(status1[1]);
     close(status2[0]);
   	do{
     read(status1[0],&state,sizeof(state));
     if(state==999)
     	exit(0);
     else
     if(state==1){
     read(fd1[0],&ans,sizeof(ans));	
   	 printf("%d,%d,%f\n",ans.sum,ans.productn,ans.avgn);
   	 state=0;
   	 write(status2[1],&state,sizeof(state));
   	}
   }while(1);
   }
}
