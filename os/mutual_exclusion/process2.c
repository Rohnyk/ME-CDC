/*process-2.c*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <semaphore.h>
int main(int argc, char * argv[]) {
    sem_t * mutex;
    char * c = "This is CSCI3150--An operating system course.\n";
    // specify no buffering for stderr
    setbuf(stderr, NULL);  
    mutex = sem_open("mutex_for_stderr", O_CREAT, 0666, 1);
    sem_wait(mutex);
    while (* c != '\0') {
        fputc(* c, stderr);
        c++;
        sleep(rand()%2+1);
    }
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex_for_stderr");
    return 0;
}
