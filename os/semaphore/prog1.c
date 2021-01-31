#include <sys/types.h>
#include <sys/ipc.h>

main(){
    int semid,key,nsem;
    key=(key_t)0x20;
    nsem = 0;
    semid=semget(key,nsem,IPC_CREAT | 0666);
    printf("Created Semaphore with ID: %d\n",semid);
}
