/*to find the maximum no of semaphore sets availbale in our LINUX System*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>

main(){
   int semid,nsem, nsemset,flag,key;
   nsem = 1;
   flag = 0666 | IPC_CREAT;
   for(nsemset=0;;nsemset++){
   	key =(key_t)nsemset;
   	semid=semget(nsemset,nsem,flag);
   	if(semid>0){
   		printf("\nCreated Semaphore with ID: %d\n",semid);
   	}
   	else{
   		printf("Maximum number of semaphore set are %d\n",nsemset);
   		exit(0);
   	}
   }

}
