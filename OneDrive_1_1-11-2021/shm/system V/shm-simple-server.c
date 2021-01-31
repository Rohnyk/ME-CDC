#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<stdlib.h>

#define SHSIZE 100

int main(int argc, char * argv[]){


	int shmid; //id
	key_t key; // keuy
	char *shm; // pointer 
	char *s; // pointer


	key = 9866;

	shmid =shmget(key,SHSIZE,IPC_CREAT | 0666); // create a memory 

	if(shmid < 0){

		perror("shmget");
		exit(1);

	}

	shm = shmat(shmid,NULL,0);

	if(shm == (char *) -1){

		perror("Shmat");
		exit(1);
	}

	memcpy(shm, "HelloWorld",11);

	s = shm;
	//printf("Value of s %s",s);
	s += 11;
	//printf("Value of s %s",s);

	*s = 0;

	while(*shm != '*')
		sleep(1);
	return 0;
}