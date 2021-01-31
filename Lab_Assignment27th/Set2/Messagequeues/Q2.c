#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define PROJECT_ID 'M'
#define KEY_PATH "/mnt/d/ME/RTOS_LAB/Lab_Assignment27th/Set2/Messagequeues/Keys/Q1.txt"
#define PERMS 0644  

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
	long message_type
	int sum;
	int productn;
	float avgn;
	int state;
} values;

void main()
{

	int n;
	pid_t pid;
    values ans,rans;
    key_t key;	
    int retval;

   if ((key = ftok (KEY_PATH,PROJECT_ID)) == -1) {
        perror ("ftok");
        exit (1);
    }
    int msqid;

    if ((msqid = msgget (key, PERMS | IPC_CREAT)) == -1) {
        perror ("msgget: server_qid");
        exit (1);
    }
	pid=fork();
	if(pid==-1)
	{
		perror("Fork not working");
		exit(0);
	}
	else
	if(pid==0)
	{
     ans.state=0;
	do
	{
    if(ans.state==0){
	printf("Enter the number:\n");	
	scanf("%d",&n);
	if(n==999)
	{
		ans.state=999;
		    if((retval=msgctl(msqid,IPC_RMID,NULL))==-1){
            perror("error remove queue");
            exit(-1);
        }
		exit(0);
	}
	ans.sum=sum(n);
	ans.avgn=average(n);
	ans.productn=product(n);
    ans.state=1;
    if (msgsnd(msqid, &ans,sizeof(ans), 0) == -1)
    	perror("msgsnd");
    }
    if (msgrcv(msqid, &rans, sizeof(rans), 0, 0) == -1) {
          perror("msgrcv");
          exit(0);
       }
	
   }while(1);
   }
   else
   {
   	do{
   	if (msgrcv(msqid, &rans, sizeof(rans), 0, 0) == -1) {
          perror("msgrcv");
          exit(0);
       }
     if(rans.state==999)
     	exit(0);
     else
     if(rans.state==1){
      printf("%d,%d,%f\n",rans.sum,rans.productn,rans.avgn);
      rans.state=0;
     if (msgsnd(msqid, &rans,sizeof(rans), 0) == -1)
    	perror("msgsnd");
    }
   	 
   	
   }while(1);
   }
}
