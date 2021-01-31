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

	//specify the key for shared memory
	key = 9866;

	//create the memory, and persmision using shmget will return shmid
	shmid =shmget(key,SHSIZE,IPC_CREAT | 0666); // create a memory 
	printf("SHMID = %d\n",shmid);

	if(shmid < 0){

		perror("shmget");
		exit(1);

	}

	shm = shmat(shmid,NULL,0);
	printf("SHM attach return= %d\n",shm);

	if(shm == (char *) -1){

		perror("Shmat");
		exit(1);
	}
	printf("Value of shm(int) %d\n",shm);
	memcpy(shm, "HelloWorld",11);

	s = shm;

	printf("Value of s %s\n",s);
	printf("Value of shm %s\n",shm);
	printf("Value of shm(int) %d\n",shm);
	
	printf("Value of s(int) %d\n",s);
	printf("Value of *s(ascii) %d\n",*s);
	printf("Value of *s(char) %c\n",*s);
	s += 11;
	printf("Value of &s(s+11) %d\n",s);
	printf("Value of *s(ascii) %d\n",*s);
	printf("Value of *s(char) %c\n",*s);
	printf("Value of *shm(char) %c\n",*shm);

	//printf("Value of s %s",s);

	*s = 0;
	printf("Value of *s(ascii) %d\n",*s);
	printf("Value of *s(char) %c\n",*s);

	while(*shm != '*')
		sleep(1);
	return 0;
}