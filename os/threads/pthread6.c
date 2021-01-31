/*Write a program that will create a number N of threads specified in the command line, each of which prints out a hello message and its own thread ID. To see how the execution of the threads interleaves, make the main thread sleep for 1 second for every 4 or 5 threads it creates. */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 50

pthread_t thread_id[MAX_THREADS];    

void * PrintHello(void * data)
{
    printf("Hello from thread %u - I was created in iteration %d !\n", (int)pthread_self(), (int)data);
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
    int rc, i, n;

    if(argc < 2) 
    {
        printf("Please add the number of threads to the command line\n");
        exit(1); 
    }
    n = atoi(argv[1]);
    if(n > MAX_THREADS) n = MAX_THREADS;

    for(i = 0; i < n; i++)
    {
        rc = pthread_create(&thread_id[i], NULL, PrintHello, (void*)i);
        if(rc)
        {
             printf("\n ERROR: return code from pthread_create is %d \n", rc);
             exit(1);
        }
        printf("\n I am thread %u. Created new thread (%u) in iteration %d ...\n", 
                (int)pthread_self(), (int)thread_id[i], i);
        if(i % 5 == 0) sleep(1);
    }

    pthread_exit(NULL);
}
