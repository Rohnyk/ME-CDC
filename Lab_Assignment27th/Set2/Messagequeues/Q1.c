#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define Max_size 10
#define PROJECT_ID 'M'
#define KEY_PATH "/mnt/d/ME/RTOS_LAB/Lab_Assignment27th/Set2/Messagequeues/Keys/Q1.txt"
#define PERMS 0644  

typedef struct message {
    long message_type;
    int sum;
}message;


int sum(int *a)
{
	int sum=0;
	for(int i=0;i<Max_size;i++)
		sum+=a[i];
	return sum;
}

float average(int sum)
{
	return (float)sum/Max_size;
}


int main()
{
    key_t key;
    int a[Max_size];

   if ((key = ftok (KEY_PATH,PROJECT_ID)) == -1) {
        perror ("ftok");
        exit (1);
    }
    int msqid;
    message my_message, return_message;
     if ((msqid = msgget (key, PERMS | IPC_CREAT)) == -1) {
        perror ("msgget: server_qid");
        exit (1);
    }


    printf("\nEnter the Elements:\n");
    for(int i=0;i<Max_size;i++)
        scanf("%d",&a[i]);
    pid_t pid;
    pid=fork();
    if(pid<0)
    	fprintf(stderr,"fork failed");
    else
    	if(pid==0)
    {
        my_message.message_type=1;
    	my_message.sum=sum(a);
    	printf("%d\n",my_message.sum);
        if (msgsnd(msqid, &my_message,sizeof(my_message), 0) == -1) /* +1 for '\0' */
            perror("msgsnd");
    }
    else
    {
        int sum;
    	float avg;
    	wait(NULL);
         if (msgrcv(msqid, &return_message, sizeof(return_message), 0, 0) == -1) {
          perror("msgrcv");
          exit(1);
      } 
    	//printf("%d\n",sum);
        avg=average(return_message.sum);
        printf("The average of the given array is:%f",avg);
        int retval;
        if((retval=msgctl(msqid,IPC_RMID,NULL))==-1){
            perror("error remove queue");
            exit(-1);
        }
 
    }

    return 0;
    
}