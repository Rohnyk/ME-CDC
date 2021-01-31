#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define Max_size 10
#define PROJECT_ID 'M'
#define KEY_PATH "/mnt/d/ME/RTOS_LAB/Lab_Assignment27th/Set2/SharedMemory/Keys/Q1.txt"
#define PERMS 0644  
#define BUF_SIZE 1024


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
    int shmid;
    int *my_message, *return_message;
    int det;
     if ((shmid = shmget (key,1024,PERMS | IPC_CREAT)) == -1) {
        perror ("shmid: server_qid");
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
        my_message = shmat(shmid, NULL, 0);
        *my_message=sum(a);
        printf("%d\n",*my_message);
        if((det = shmdt(my_message))==-1)
            perror("detaching error:");
 
    }
    else
    {
    	float avg;
    	wait(NULL);
        return_message=shmat(shmid,NULL,0);
    	//printf("%d\n",sum);
        avg=average(*return_message);
        printf("The average of the given array is:%f",avg);

         if ((det=shmdt(return_message))==-1) 
          perror("detaching parent erorr");

        int retval;
        if((retval=shmctl(shmid,IPC_RMID,NULL))==-1){
            perror("error remove memory");
            exit(-1);
        }
 
    }



    return 0;
    
}