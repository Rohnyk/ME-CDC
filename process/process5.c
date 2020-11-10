
//Code for Program to create processes using fork() and check different states for orphan process in C Programming

#include <stdio.h>


int main()
{    
    int pid;
    pid=getpid();
    
    printf("Current Process ID is : %d\n",pid);

    printf("[ Forking Child Process ... ] \n");    
    pid=fork(); /* This will Create Child Process and Returns Child's PID */
    printf("pid after fork %d",pid);
    
    if(pid < 0)
    {
        /* Process Creation Failed ... */
        exit(-1);
    }
    else if(pid==0)
    {
        /* Child Process */
        printf("Child Process is Sleeping ...");
        sleep(5);

        /*            Orphan Child's Parent ID is 1                */
        printf("\nOrphan Child's Parent ID : %d",getppid());
    }
    else
    {
        /* Parent Process */
        printf("Parent Process Completed ...");
    }    
    return 0;
}
