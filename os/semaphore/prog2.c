#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>

main(){
    int semid,key,nsem,flag;
    key=(key_t)0x20;
    nsem = 1;
    flag =IPC_CREAT | 0666;
    semid=semget(key,nsem,flag);
    printf("Created Semaphore with ID: %d\n",semid);
}
